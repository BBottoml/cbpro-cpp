//
// Created by Bradley Bottomlee on 1/19/21.
//


#ifndef CBPRO_PRODUCTS_H
#define CBPRO_PRODUCTS_H

#include <cbpro++/marketdata/product.h>
#include <cbpro++/marketdata/book.h>
#include <cbpro++/marketdata/ticker.h>
#include <cbpro++/marketdata/trade.h>
#include <cbpro++/marketdata/stats.h>
#include <cbpro++/auth.h>
#include <utility>
#include <unordered_map>

namespace marketdata {
    namespace products {
        std::vector<responses::product> getProducts(Auth &auth);

        responses::product getProduct(Auth &auth, const std::string &productId);

        responses::ticker getTicker(Auth &auth, const std::string &productId);

        responses::stats getStats(Auth &auth, const std::string &productId);

        std::vector<responses::trade> getTrades(Auth &auth, const std::string &productId);

        responses::book<responses::bidLevel1_2, responses::askLevel1_2>
        getOrderBookLevelOne(Auth &auth, const std::string &productId);

        responses::book<responses::bidLevel1_2, responses::askLevel1_2>
        getOrderBookLevelTwo(Auth &auth, const std::string &productId);

        responses::book<responses::bidLevel3, responses::askLevel3>
        getOrderBookLevelThree(Auth &auth, const std::string &productId);

    } // namespace products
} // namespace marketdata

#endif //CBPRO_PRODUCTS_H
