//
// Created by Bradley Bottomlee on 2/24/21.
//

#include <cbpro++/orders/order.h>

namespace responses {

    /**
     * Returns whether order was placed successfully
     *
     * @return bool
     */
    bool
    order::getOrderOutcome() const {
        return !data.get_optional<bool>("error");
    }

    std::string
    order::getId() const {
        return data.get<std::string>("id");
    }

    std::string
    order::getPrice() const {
        return data.get<std::string>("price");
    }

    std::string
    order::getSize() const {
        return data.get<std::string>("size");
    }

    std::string
    order::getProductId() const {
        return data.get<std::string>("product_id");
    }

    std::string
    order::getSide() const {
        return data.get<std::string>("side");
    }

    std::string
    order::getStp() const {
        return data.get<std::string>("stp");
    }

    std::string
    order::getType() const {
        return data.get<std::string>("type");
    }

    std::string
    order::getTimeInForce() const {
        return data.get<std::string>("time_in_force");
    }

    std::string
    order::getCreatedAt() const {
        return data.get<std::string>("created_at");
    }

    std::string
    order::getFillFees() const {
        return data.get<std::string>("fill_fees");
    }

    std::string
    order::getFilledSize() const {
        return data.get<std::string>("filled_size");
    }

    std::string
    order::getExecutedValue() const {
        return data.get<std::string>("executed_value");
    }

    std::string
    order::getStatus() const {
        return data.get<std::string>("status");
    }

    bool
    order::getPostOnly() const {
        return data.get<bool>("post_only");
    }

    bool
    order::getSettled() const {
        return data.get<bool>("settled");
    }

    order::order(const pt::ptree &data) : data(data) {}

} // namespace responses