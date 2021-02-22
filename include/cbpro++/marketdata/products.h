//
// Created by Bradley Bottomlee on 1/19/21.
//


#ifndef CBPRO_PRODUCTS_H
#define CBPRO_PRODUCTS_H

#include "../../../src/responses/product.h"
#include <cbpro++/auth.h>
#include <utility>
#include <unordered_map>

namespace marketdata {
    namespace products {

        enum class Level {
            TWO, THREE
        };

        std::vector<responses::product> getProducts(Auth &auth);

        responses::product getProduct(Auth &auth, std::string &productId);

        void getOrderBook(Auth &auth, std::string &productId);

        void getOrderBook(Auth &auth, std::string &productId, marketdata::products::Level level);
    } // namespace products
} // namespace marketdata

#endif //CBPRO_PRODUCTS_H