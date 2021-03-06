/*
 *  Copyright (c) 2012 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

// This sub-API supports the following functionalities:
//
//  - Enables full duplex VoIP sessions via RTP using G.711 (mu-Law or A-Law).
//  - Initialization and termination.
//  - Trace information on text files or via callbacks.
//  - Multi-channel support (mixing, sending to multiple destinations etc.).
//
// To support other codecs than G.711, the VoECodec sub-API must be utilized.
//
// Usage example, omitting error checking:
//
//  using namespace webrtc;
//  VoiceEngine* voe = VoiceEngine::Create();
//  VoEBase* base = VoEBase::GetInterface(voe);
//  base->Init();
//  int ch = base->CreateChannel();
//  base->StartPlayout(ch);
//  ...
//  base->DeleteChannel(ch);
//  base->Terminate();
//  base->Release();
//  VoiceEngine::Delete(voe);
//
#ifndef VOICE_ENGINE_VOE_BASE_H_
#define VOICE_ENGINE_VOE_BASE_H_

#include "api/audio_codecs/audio_decoder_factory.h"
#include "common_types.h"  // NOLINT(build/include)
#include "modules/audio_coding/include/audio_coding_module.h"
#include "rtc_base/scoped_ref_ptr.h"

namespace webrtc {

class AudioDeviceModule;
class AudioProcessing;

// VoiceEngine
class WEBRTC_DLLEXPORT VoiceEngine {
 public:
  // Creates a VoiceEngine object, which can then be used to acquire
  // sub-APIs. Returns NULL on failure.
  static VoiceEngine* Create();

  // Deletes a created VoiceEngine object and releases the utilized resources.
  // Note that if there are outstanding references held via other interfaces,
  // the voice engine instance will not actually be deleted until those
  // references have been released.
  static bool Delete(VoiceEngine*& voiceEngine);

 protected:
  VoiceEngine() {}
  ~VoiceEngine() {}
};

// VoEBase
class WEBRTC_DLLEXPORT VoEBase {
 public:
  struct ChannelConfig {
    AudioCodingModule::Config acm_config;
    bool enable_voice_pacing = false;
  };

  // Factory for the VoEBase sub-API. Increases an internal reference
  // counter if successful. Returns NULL if the API is not supported or if
  // construction fails.
  static VoEBase* GetInterface(VoiceEngine* voiceEngine);

  // Releases the VoEBase sub-API and decreases an internal reference
  // counter. Returns the new reference count. This value should be zero
  // for all sub-APIs before the VoiceEngine object can be safely deleted.
  virtual int Release() = 0;

  // Initializes all common parts of the VoiceEngine; e.g. all
  // encoders/decoders, the sound card and core receiving components.
  // This method also makes it possible to install some user-defined external
  // modules:
  // - The Audio Device Module (ADM) which implements all the audio layer
  // functionality in a separate (reference counted) module.
  // - The AudioProcessing module is unused - only kept for API compatibility.
  // - An AudioDecoderFactory - used to create audio decoders.
  virtual int Init(
      AudioDeviceModule* audio_device,
      AudioProcessing* audio_processing,
      const rtc::scoped_refptr<AudioDecoderFactory>& decoder_factory) = 0;

  // Terminates all VoiceEngine functions and releases allocated resources.
  virtual void Terminate() = 0;

  // Creates a new channel and allocates the required resources for it.
  // The second version accepts a |config| struct which includes an Audio Coding
  // Module config and an option to enable voice pacing. Note that the
  // decoder_factory member of the ACM config will be ignored (the decoder
  // factory set through Init() will always be used).
  // Returns channel ID or -1 in case of an error.
  virtual int CreateChannel() = 0;
  virtual int CreateChannel(const ChannelConfig& config) = 0;

  // Deletes an existing channel and releases the utilized resources.
  // Returns -1 in case of an error, 0 otherwise.
  virtual int DeleteChannel(int channel) = 0;

 protected:
  VoEBase() {}
  virtual ~VoEBase() {}
};

}  // namespace webrtc

#endif  //  VOICE_ENGINE_VOE_BASE_H_
