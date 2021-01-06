//
// Created by Bradley Bottomlee on 1/1/21.
//

#ifndef CBPRO_AUTH_H
#define CBPRO_AUTH_H

#endif //CBPRO_AUTH_H

#include <string>
#include <boost/beast.hpp>

class Auth {
private:
    const std::string &apiKey;
    const std::string &apiSecret;
    const std::string &passphrase;


public:
    Auth(const std::string &apiKey, const std::string &apiSecret, const std::string &passphrase);

    const std::string &getApiKey() const;

    const std::string &getApiSecret() const;

    const std::string &getPassphrase() const;
};