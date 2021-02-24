//
// Created by Bradley Bottomlee on 2/24/21.
//

#include <cbpro++/accounts/entry.h>

namespace responses {

    std::string
    entry::getId() const {
        return data.get<std::string>("id");
    }

    std::string
    entry::getCreatedAt() const {
        return data.get<std::string>("created_at");
    }

    std::string
    entry::getAmount() const {
        return data.get<std::string>("amount");
    }

    std::string
    entry::getBalance() const {
        return data.get<std::string>("balance");
    }

    std::string
    entry::getType() const {
        return data.get<std::string>("type");
    }

    std::string
    entry::getOrderId() const {
        auto details = data.get_child_optional("details");
        if (details) {
            auto orderId = data.get_optional<std::string>("order_id");
            if (orderId) {
                return orderId.value();
            }
        }
        return "";
    }

    std::string
    entry::getTradeId() const {
        auto details = data.get_child_optional("details");
        if (details) {
            auto tradeId = data.get_optional<std::string>("trade_id");
            if (tradeId) {
                return tradeId.value();
            }
        }
        return "";
    }

    std::string
    entry::getProductId() const {
        auto details = data.get_child_optional("details");
        if (details) {
            auto productId = data.get_optional<std::string>("trade_id");
            if (productId) {
                return productId.value();
            }
        }
        return "";
    }

    entry::entry(const pt::ptree &data) : data(data) {}
} // namespace responses

