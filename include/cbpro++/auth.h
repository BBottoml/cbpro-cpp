//
// Created by Bradley Bottomlee on 1/1/21.
//

#include <string>

#ifndef CBPRO_AUTH_H
#define CBPRO_AUTH_H

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

    Mode getMode() const;

private:
    const std::string &apiKey;
    const std::string &apiSecret;
    const std::string &passphrase;
    Auth::Mode mode;


};

#endif //CBPRO_AUTH_H