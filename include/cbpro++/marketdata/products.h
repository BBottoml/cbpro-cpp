//
// Created by Bradley Bottomlee on 1/19/21.
//


#ifndef CBPRO_PRODUCTS_H
#define CBPRO_PRODUCTS_H

#include <cbpro++/responses/product.h>
#include <cbpro++/auth.h>
#include <utility>
#include <unordered_map>

namespace marketdata {
    namespace products {
        std::vector<responses::product> getProducts(Auth &auth);
        responses::product getProduct(Auth &auth, std::string &productId);
    } // namespace products
} // namespace marketdata

#endif //CBPRO_PRODUCTS_H