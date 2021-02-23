//
// Created by Bradley Bottomlee on 2/11/21.
//


#include <cbpro++/responses/ask.h>

#include <utility>

namespace responses {

    askLevel1_2::askLevel1_2(std::string price, std::string size, std::string numOrders) : price(std::move(price)),
                                                                                           size(std::move(size)),
                                                                                           numOrders(
                                                                                                   std::move(numOrders)) {}

    const std::string &askLevel1_2::getPrice() const {
        return price;
    }

    const std::string &askLevel1_2::getSize() const {
        return size;
    }

    const std::string &askLevel1_2::getNumOrders() const {
        return numOrders;
    }

    askLevel3::askLevel3(std::string price, std::string size, std::string orderId) : price(std::move(price)),
                                                                                     size(std::move(size)),
                                                                                     orderId(std::move(orderId)) {}

    const std::string &askLevel3::getPrice() const {
        return price;
    }

    const std::string &askLevel3::getSize() const {
        return size;
    }

    const std::string &askLevel3::getOrderId() const {
        return orderId;
    }


} // namespace responses