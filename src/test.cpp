//
// Created by Bradley Bottomlee on 1/7/21.
//
#include <iostream>
#include <cbpro++/test.h>
#include "util/HttpClient.h"

test::test(Auth &auth) : auth(auth) {};

void test::hitEndpoint() {
    HttpClient a;
    auto resp = a.makeRequest("/products");
    for (auto& product: resp) {
        std::cout << product.second.get<std::string>("id") << std::endl;
    }
}

