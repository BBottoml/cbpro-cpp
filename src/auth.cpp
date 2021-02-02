//
// Created by Bradley Bottomlee on 12/21/20.
//

#include <cbpro++/auth.h>

Auth::Auth(const std::string &apiKey, const std::string &apiSecret, const std::string &passphrase, Auth::Mode mode)
        : apiKey(apiKey),
          apiSecret(
                  apiSecret),
          passphrase(
                  passphrase), mode(mode) {

    bool authMode = mode == Auth::Mode::LIVE;
    httpClientPtr = std::make_shared<HttpClient>(apiKey, apiSecret, passphrase, authMode);
};

Auth::~Auth() = default;

const std::string &Auth::getApiKey() const {
    return apiKey;
}

const std::string &Auth::getApiSecret() const {
    return apiSecret;
}

const std::string &Auth::getPassphrase() const {
    return passphrase;
}

const std::shared_ptr<HttpClient> &Auth::getHttpClientPtr() const {
    return httpClientPtr;
}

Auth::Mode Auth::getMode() const {
    return mode;
}

