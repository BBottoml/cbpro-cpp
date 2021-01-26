//
// Created by Bradley Bottomlee on 1/7/21.
//
#include <iostream>
#include <cbpro++/test.h>
#include <cbpro++/marketdata/products.h>

#include "util/httpclient.h"

test::test(Auth &auth) : auth(auth) {};

void test::hitEndpoint() {
    HttpClient httpClient("api-public.sandbox.pro.coinbase.com", "443");
    auto resp = httpClient.makeRequest("/products");
    for (auto& product: resp) {
        std::cout << product.second.get<std::string>("id") << std::endl;
    }

    //auto products = marketdata::products::getProducts();

   /* for (auto& product : products) {
        std::cout << product.first << " | " << product.second << std::endl;
    }
    */

}

