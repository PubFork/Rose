// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "net/ssl/ssl_config.h"
#include "net/ssl/ssl_config_service_bindcert.hpp"

#include "filesystem.hpp"
#include "rose_config.hpp"
#include "serialization/string_utils.hpp"

namespace net {

	std::map<std::string, std::string> SSLConfigServiceBindCert::certs;
/*
	unsigned char server_cert_der[] = {
		0x30, 0x82, 0x03, 0x2e, 0x30, 0x82, 0x02, 0x16, 0x02, 0x09, 0x00, 0xbf,
		0x9b, 0xc4, 0x2b, 0x81, 0x97, 0x05, 0x63, 0x30, 0x0d, 0x06, 0x09, 0x2a,
		0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01, 0x0b, 0x05, 0x00, 0x30, 0x53,
		0x31, 0x0b, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x41,
		0x55, 0x31, 0x13, 0x30, 0x11, 0x06, 0x03, 0x55, 0x04, 0x08, 0x0c, 0x0a,
		0x53, 0x6f, 0x6d, 0x65, 0x2d, 0x53, 0x74, 0x61, 0x74, 0x65, 0x31, 0x21,
		0x30, 0x1f, 0x06, 0x03, 0x55, 0x04, 0x0a, 0x0c, 0x18, 0x49, 0x6e, 0x74,
		0x65, 0x72, 0x6e, 0x65, 0x74, 0x20, 0x57, 0x69, 0x64, 0x67, 0x69, 0x74,
		0x73, 0x20, 0x50, 0x74, 0x79, 0x20, 0x4c, 0x74, 0x64, 0x31, 0x0c, 0x30,
		0x0a, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0c, 0x03, 0x61, 0x70, 0x70, 0x30,
		0x1e, 0x17, 0x0d, 0x31, 0x38, 0x30, 0x33, 0x32, 0x35, 0x31, 0x35, 0x30,
		0x30, 0x35, 0x31, 0x5a, 0x17, 0x0d, 0x32, 0x38, 0x30, 0x33, 0x32, 0x32,
		0x31, 0x35, 0x30, 0x30, 0x35, 0x31, 0x5a, 0x30, 0x5f, 0x31, 0x0b, 0x30,
		0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x41, 0x55, 0x31, 0x13,
		0x30, 0x11, 0x06, 0x03, 0x55, 0x04, 0x08, 0x0c, 0x0a, 0x53, 0x6f, 0x6d,
		0x65, 0x2d, 0x53, 0x74, 0x61, 0x74, 0x65, 0x31, 0x21, 0x30, 0x1f, 0x06,
		0x03, 0x55, 0x04, 0x0a, 0x0c, 0x18, 0x49, 0x6e, 0x74, 0x65, 0x72, 0x6e,
		0x65, 0x74, 0x20, 0x57, 0x69, 0x64, 0x67, 0x69, 0x74, 0x73, 0x20, 0x50,
		0x74, 0x79, 0x20, 0x4c, 0x74, 0x64, 0x31, 0x18, 0x30, 0x16, 0x06, 0x03,
		0x55, 0x04, 0x03, 0x0c, 0x0f, 0x31, 0x30, 0x31, 0x2e, 0x31, 0x33, 0x32,
		0x2e, 0x31, 0x34, 0x33, 0x2e, 0x32, 0x33, 0x31, 0x30, 0x82, 0x01, 0x22,
		0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x01,
		0x01, 0x05, 0x00, 0x03, 0x82, 0x01, 0x0f, 0x00, 0x30, 0x82, 0x01, 0x0a,
		0x02, 0x82, 0x01, 0x01, 0x00, 0xbc, 0xd9, 0xc3, 0xa3, 0x02, 0x33, 0xa0,
		0xba, 0x0b, 0x4d, 0xe2, 0x05, 0xcf, 0xba, 0xf2, 0xa7, 0x3e, 0x46, 0xd8,
		0xa9, 0xa8, 0x27, 0xa0, 0x9b, 0x6f, 0x2d, 0x5d, 0xbc, 0xac, 0x21, 0x24,
		0xb0, 0x7d, 0x92, 0x09, 0x7a, 0x91, 0x1c, 0x33, 0x78, 0xae, 0x84, 0xba,
		0xd6, 0xae, 0xd8, 0xc1, 0xd9, 0xb9, 0xf5, 0x87, 0x12, 0x99, 0x21, 0xed,
		0x3f, 0x99, 0x71, 0xf8, 0xf5, 0x61, 0xfb, 0x59, 0x09, 0xdb, 0x73, 0x8e,
		0x24, 0xd6, 0xad, 0x00, 0xd7, 0x72, 0x9f, 0x0c, 0x4c, 0x54, 0xc6, 0x5a,
		0xd0, 0xd1, 0x90, 0xfd, 0x9c, 0xa7, 0x2f, 0x4e, 0x25, 0xd5, 0xb7, 0x11,
		0x00, 0xe5, 0x6b, 0xb4, 0xce, 0x51, 0x4f, 0xa1, 0xbb, 0x11, 0x58, 0x78,
		0xba, 0x28, 0xb1, 0x5c, 0x93, 0x30, 0xfa, 0x80, 0x55, 0x94, 0x82, 0xe7,
		0x34, 0xf0, 0xcf, 0xe2, 0xc7, 0xe9, 0x4c, 0x86, 0x01, 0x6e, 0x48, 0x00,
		0x51, 0xa6, 0x94, 0xbe, 0x46, 0xaf, 0x91, 0x8a, 0x0e, 0x8a, 0x32, 0xd4,
		0x7e, 0x2f, 0x1f, 0x3e, 0x1e, 0x83, 0x16, 0x40, 0xea, 0x2f, 0x80, 0x1a,
		0x9e, 0x48, 0xca, 0x66, 0xe4, 0x24, 0xaf, 0x23, 0x4b, 0x5d, 0x83, 0xdc,
		0x96, 0xc2, 0x38, 0xc5, 0x26, 0x77, 0x65, 0xe4, 0x19, 0xde, 0xfd, 0x0e,
		0x04, 0xa6, 0xd2, 0x65, 0x9b, 0xd8, 0x51, 0xc3, 0x21, 0x2d, 0xe9, 0xda,
		0x97, 0x0d, 0x36, 0xa3, 0x68, 0x0c, 0xfd, 0xca, 0x4e, 0xc3, 0xcf, 0xa2,
		0x9a, 0x44, 0x56, 0x08, 0x7f, 0xca, 0x85, 0xe1, 0x23, 0xa0, 0xb7, 0xc2,
		0xe9, 0xd5, 0x32, 0xcc, 0x92, 0xd9, 0xda, 0xd5, 0x37, 0x08, 0x1d, 0x7d,
		0x45, 0xc4, 0xe8, 0x13, 0xc5, 0xc8, 0xfd, 0xfa, 0xe2, 0x0b, 0xad, 0xcc,
		0xf1, 0xa1, 0xcb, 0xbd, 0x0a, 0xdf, 0x43, 0x3e, 0xe1, 0xc7, 0x29, 0x88,
		0xad, 0xc6, 0x89, 0x76, 0xa0, 0xd1, 0xc4, 0x31, 0x5f, 0x02, 0x03, 0x01,
		0x00, 0x01, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d,
		0x01, 0x01, 0x0b, 0x05, 0x00, 0x03, 0x82, 0x01, 0x01, 0x00, 0x56, 0x5f,
		0x2a, 0x30, 0xb9, 0x4a, 0x23, 0xc1, 0xeb, 0x13, 0xc3, 0x5a, 0x06, 0x37,
		0x21, 0x1c, 0xdf, 0xdb, 0x89, 0x43, 0x70, 0x3a, 0x91, 0x6d, 0xe2, 0x5f,
		0x33, 0xb1, 0xa2, 0xf8, 0x7c, 0x87, 0xa2, 0xb0, 0xef, 0x20, 0x4c, 0x9f,
		0x1f, 0xdd, 0xfa, 0xf0, 0xcb, 0xd3, 0x60, 0x32, 0x3b, 0xaf, 0x55, 0xec,
		0xa3, 0xd1, 0x0e, 0xc5, 0xf8, 0x68, 0x4d, 0xf6, 0xc1, 0xfc, 0xe4, 0x64,
		0x8b, 0x02, 0xe2, 0x13, 0xee, 0xbc, 0xb1, 0x65, 0xc3, 0x9f, 0x23, 0xf2,
		0x77, 0x03, 0x85, 0xf8, 0xb7, 0x75, 0x8c, 0x95, 0x91, 0x2f, 0x7e, 0x30,
		0x9f, 0x29, 0x2d, 0xe0, 0x13, 0xfe, 0x1e, 0x3d, 0xbc, 0x39, 0x3c, 0xb0,
		0x2b, 0x44, 0x3d, 0xb3, 0x1f, 0x24, 0xdd, 0x50, 0x64, 0x2b, 0x9d, 0x44,
		0x4b, 0x4d, 0xf7, 0x15, 0x80, 0x60, 0x2a, 0xb0, 0xab, 0x64, 0xe0, 0xd4,
		0xea, 0x92, 0xbd, 0xb4, 0x4f, 0x01, 0xa4, 0x17, 0xb9, 0x0a, 0xbd, 0x95,
		0x36, 0x1d, 0x53, 0xc4, 0x18, 0x9b, 0x09, 0xee, 0x72, 0xd7, 0x0b, 0x0f,
		0x70, 0xba, 0xbe, 0x63, 0xcf, 0x12, 0x86, 0x4b, 0xbd, 0xbb, 0xe5, 0x3b,
		0xaa, 0xde, 0xdf, 0xa9, 0x2c, 0x0e, 0xc5, 0x94, 0x93, 0x65, 0x8d, 0x72,
		0x18, 0xfb, 0xa5, 0x27, 0x48, 0x65, 0x83, 0xa5, 0xe2, 0x67, 0xa5, 0xe7,
		0x28, 0xf5, 0x2c, 0x61, 0x79, 0x7f, 0xd3, 0xfd, 0x31, 0x5e, 0xb1, 0xb4,
		0x08, 0xde, 0x6d, 0x0b, 0x6c, 0x26, 0x29, 0x4f, 0xb5, 0x7b, 0x7d, 0xd1,
		0x11, 0xd8, 0xac, 0xf5, 0x14, 0x6c, 0xb2, 0x7b, 0xf6, 0xee, 0xfb, 0xe0,
		0xdc, 0xde, 0xbf, 0xf0, 0x06, 0x5d, 0x01, 0x8b, 0xd8, 0xde, 0xcc, 0x72,
		0xf9, 0xe3, 0x10, 0xd7, 0x53, 0x8b, 0xc0, 0xac, 0x35, 0xaa, 0x3b, 0x12,
		0x9b, 0xd2, 0x1f, 0x76, 0x5d, 0x73, 0xd5, 0xff, 0x7e, 0xd3, 0xe2, 0x40,
		0xca, 0x7d
	};
*/
	SSLConfigServiceBindCert::SSLConfigServiceBindCert(const std::string& cert)
		: cert_(cert)
	{
		CHECK(!cert_.empty());
	}

	void SSLConfigServiceBindCert::GetSSLConfig(SSLConfig* config) {
		*config = default_config_;
		if (config->allowed_bad_certs.size() == 0) {
			std::map<std::string, std::string>::const_iterator find_it = certs.find(cert_);
			if (find_it == certs.end()) {
				std::pair<std::map<std::string, std::string>::iterator, bool> ins = certs.insert(std::make_pair(cert_, null_str));
				tfile file(game_config::path + "/" + game_config::app_dir + "/cert/" + cert_, GENERIC_READ, OPEN_EXISTING);
				int64_t fsize = file.read_2_data();
				CHECK(fsize > 0);
				ins.first->second.assign(file.data, fsize);
				find_it = certs.find(cert_);
			}
			scoped_refptr<X509Certificate> cert = X509Certificate::CreateFromBytes(find_it->second.c_str(), find_it->second.size());
/*
			scoped_refptr<X509Certificate> cert = X509Certificate::CreateFromBytes(
				reinterpret_cast<const char*>(server_cert_der) , sizeof(server_cert_der));
			// SSLConfig::CertAndStatus::CertAndStatus(cert,NULL);
*/
			config->allowed_bad_certs.push_back(SSLConfig::CertAndStatus(cert, 0));
		}
	}

	SSLConfigServiceBindCert::~SSLConfigServiceBindCert() = default;

}  // namespace net
