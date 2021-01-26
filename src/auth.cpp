//
// Created by Bradley Bottomlee on 12/21/20.
//

#include <cbpro++/auth.h>

Auth::Auth(const std::string &apiKey, const std::string &apiSecret, const std::string &passphrase) : apiKey(apiKey),
                                                                                                     apiSecret(
                                                                                                             apiSecret),
                                                                                                     passphrase(
                                                                                                             passphrase) {};

const std::string &Auth::getApiKey() const {
    return apiKey;
}

const std::string &Auth::getApiSecret() const {
    return apiSecret;
}

const std::string &Auth::getPassphrase() const {
    return passphrase;
}

