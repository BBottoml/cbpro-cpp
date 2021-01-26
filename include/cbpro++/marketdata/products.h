//
// Created by Bradley Bottomlee on 1/19/21.
//

#include <cbpro++/responses/product.h>
#include <utility>
#include <unordered_map>

#ifndef CBPRO_PRODUCTS_H
#define CBPRO_PRODUCTS_H


namespace marketdata {
    namespace products {
        std::vector<responses::Product> getProducts();
        //std::unordered_map<std::string, std::string>
    } // namespace products
} // namespace marketdata

#endif //CBPRO_PRODUCTS_H