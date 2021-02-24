//
// Created by Bradley Bottomlee on 2/11/21.
//

#include <cbpro++/marketdata/bid.h>

#include <utility>

namespace responses {

    bidLevel1_2::bidLevel1_2(std::string price, std::string size, std::string numOrders) : price(std::move(price)),
                                                                                                    size(std::move(size)),
                                                                                                    numOrders(std::move(
                                                                                                            numOrders)) {}

    const std::string &bidLevel1_2::getPrice() const {
        return price;
    }

    const std::string &bidLevel1_2::getSize() const  {
        return size;
    }

    const std::string &bidLevel1_2::getNumOrders() const {
        return numOrders;
    }

    bidLevel3::bidLevel3(std::string price, std::string size, std::string orderId) : price(std::move(price)),
                                                                                                          size(std::move(size)),
                                                                                                          orderId(std::move(orderId)) {}

    const std::string &bidLevel3::getPrice() const {
        return price;
    }

    const std::string &bidLevel3::getSize() const {
        return size;
    }

    const std::string &bidLevel3::getOrderId() const {
        return orderId;
    }


} // namespace responses