//
// Created by Bradley Bottomlee on 1/7/21.
//

#include "Auth.h"

#ifndef CBPRO_TEST_H
#define CBPRO_TEST_H

class test {
private:
public:
    Auth &auth;
    explicit test(Auth &);

    void hitEndpoint();
};

#endif //CBPRO_TEST_H
