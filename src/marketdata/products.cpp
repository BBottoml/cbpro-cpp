//
// Created by Bradley Bottomlee on 1/19/21.
//

#include <cbpro++/marketdata/products.h>

namespace marketdata {
    namespace products {

        std::vector<responses::product> getProducts(Auth &auth) {
            const auto &httpClient = auth.getHttpClientPtr();
            auto resp = httpClient->makeRequest("/products");

            std::vector<responses::product> products;
            for (const auto &prod : resp) {
                responses::product product(prod.second);
                products.push_back(product);
            }
            return products;
        }

        responses::product getProduct(Auth &auth, std::string &productId) {
            const auto &httpClient = auth.getHttpClientPtr();

            std::string target = "/products/";
            target += productId;
            auto resp = httpClient->makeRequest(target);

            responses::product product(resp);
            return product;
        }

    } // namespace products
} // namespace marketdata