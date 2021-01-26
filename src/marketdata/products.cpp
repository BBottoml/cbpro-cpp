//
// Created by Bradley Bottomlee on 1/19/21.
//

#include <cbpro++/marketdata/products.h>
#include <iostream>
#include "../util/httpclient.h"

namespace marketdata {
    namespace products {

        std::vector<responses::Product> getProducts() {
            HttpClient httpClient("api-public.sandbox.pro.coinbase.com", "443");
            auto resp = httpClient.makeRequest("/products");

            std::vector<responses::Product> products;
            for (auto &product : resp) {
                std::cout << product.first << std::endl;
                //std::cout << product.second.get<std::string>(product.first);
                auto baseCurrency = product.second.get<std::string>("base_currency");
                auto quoteCurrency = product.second.get<std::string>("quote_currency");
                //products.emplace_back(baseCurrency, quoteCurrency);
            }

            return products;
        }

    } // namespace products
} // namespace marketdata