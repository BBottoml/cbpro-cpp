//
// Created by Bradley Bottomlee on 2/23/21.
//

#include <cbpro++/responses/ticker.h>

namespace responses {
    std::string
    ticker::getSize() const {
        return data.get<std::string>("size");
    }

    std::string
    ticker::getTime() const {
        return data.get<std::string>("time");
    }

    std::string
    ticker::getAsk() const {
        return data.get<std::string>("ask");
    }

    std::string
    ticker::getBid() const {
        return data.get<std::string>("bid");
    }

    std::string
    ticker::getVolume() const {
        return data.get<std::string>("volume");
    }

    std::string
    ticker::getPrice() const {
        return data.get<std::string>("price");
    }

    std::string
    ticker::getTradeId() const {
        return data.get<std::string>("trade_id");
    }

    ticker::ticker(const pt::ptree &data) : data(data) {}
} // namespace responses