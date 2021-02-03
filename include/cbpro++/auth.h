//
// Created by Bradley Bottomlee on 1/1/21.
//

#ifndef CBPRO_AUTH_H
#define CBPRO_AUTH_H

#include <string>
#include <memory>
#include "../../src/util/httpclient.h"

class Auth {
public:
    enum class Mode {
        SANDBOX, LIVE
    }; // scoped enum

    Auth(const std::string &apiKey, const std::string &apiSecret, const std::string &passphrase, Auth::Mode mode);

    ~Auth();

    [[nodiscard]] const std::string &getApiKey() const;

    [[nodiscard]] const std::string &getApiSecret() const;

    [[nodiscard]] const std::string &getPassphrase() const;

    [[nodiscard]] Mode getMode() const;

    [[nodiscard]] const std::shared_ptr<HttpClient> &getHttpClientPtr() const;

private:
    const std::string &apiKey;
    const std::string &apiSecret;
    const std::string &passphrase;
    Auth::Mode mode;

    std::shared_ptr<HttpClient> httpClientPtr;


};

#endif //CBPRO_AUTH_H