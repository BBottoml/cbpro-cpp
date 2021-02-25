//
// Created by Bradley Bottomlee on 2/24/21.
//

#ifndef CBPRO_ORDERS_H
#define CBPRO_ORDERS_H

#include <cbpro++/auth.h>
#include <cbpro++/orders/order.h>
#include <cbpro++/orders/options.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/algorithm/string.hpp>

#include <string>
#include <vector>

namespace pt = boost::property_tree;

namespace orders {

    enum class OrderType {
        MARKET, LIMIT
    }; // scoped enum

    enum class OrderSide {
        BUY, SELL
    }; // scoped enum

    responses::order
    placeMarketOrder(Auth &auth, const std::string &productId, orders::OrderSide side, const std::string &size = "",
                     const std::string &funds = "", const orders::options &opts = {});

    responses::order
    placeLimitOrder(Auth &auth, const std::string &productId, orders::OrderSide side, const std::string &size,
                    const std::string &price, const orders::options &opts = {});

    responses::order
    getOrder(Auth &auth, const std::string &orderId, bool isClientOid = false);

    std::vector<responses::order>
    getOrders(Auth &auth, const std::string &productId = "", bool open = true, bool pending = true, bool active = true);

    std::vector<std::string> cancelAllOrders(Auth &auth, const std::string &productId = "");

    bool cancelOrder(Auth &auth, const std::string &id, const std::string &productId = "", bool isClientOid = false);


}

#endif //CBPRO_ORDERS_H
