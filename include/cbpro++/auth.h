//
// Created by Bradley Bottomlee on 1/1/21.
//

#include <string>

#ifndef CBPRO_AUTH_H
#define CBPRO_AUTH_H

class Auth {
private:
    const std::string &apiKey;
    const std::string &apiSecret;
    const std::string &passphrase;


public:
    Auth(const std::string &, const std::string &, const std::string &);

    [[nodiscard]] const std::string &getApiKey() const;

    [[nodiscard]] const std::string &getApiSecret() const;

    [[nodiscard]] const std::string &getPassphrase() const;
};

#endif //CBPRO_AUTH_H