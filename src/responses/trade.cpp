//
// Created by Bradley Bottomlee on 2/23/21.
//

#include <cbpro++/responses/trade.h>

namespace responses {

    std::string
    trade::getPrice() const {
        return data.get<std::string>("price");
    }

    std::string
    trade::getSize() const {
        return data.get<std::string>("size");
    }

    std::string
    trade::getSide() const {
        return data.get<std::string>("side");
    }

    std::string
    trade::getTime() const {
        return data.get<std::string>("time");
    }

    std::string
    trade::getTradeId() const {
        return data.get<std::string>("trade_id");
    }

    trade::trade(const pt::ptree &data) : data(data) {}
} // namespace responses

