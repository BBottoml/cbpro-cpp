//
// Created by Bradley Bottomlee on 1/22/21.
//

#include <string>
#include <cbpro++/marketdata/product.h>

namespace responses {

    std::string
    product::getId() const {
        return data.get<std::string>("id");
    }

    std::string
    product::getDisplayName() const {
        return data.get<std::string>("display_name");
    }

    std::string
    product::getBaseCurrency() const {
        return data.get<std::string>("base_currency");
    }

    std::string
    product::getQuoteCurrency() const {
        return data.get<std::string>("quote_currency");;
    }

    std::string
    product::getBaseIncrement() const {
        return data.get<std::string>("base_increment");
    }

    std::string
    product::getQuoteIncrement() const {
        return data.get<std::string>("quote_increment");
    }

    std::string
    product::getBaseMinSize() const {
        return data.get<std::string>("base_min_size");
    }

    std::string
    product::getBaseMaxSize() const {
        return data.get<std::string>("base_max_size");
    }

    std::string
    product::getMinMarketFunds() const {
        return data.get<std::string>("min_market_funds");
    }

    std::string
    product::getMaxMarketFunds() const {
        return data.get<std::string>("max_market_funds");
    }

    std::string
    product::getStatus() const {
        return data.get<std::string>("status");
    }

    std::string
    product::getStatusMessage() const {
        return data.get<std::string>("status_message");
    }

    bool product::getCancelOnly() const {
        return data.get<bool>("cancel_only");
    }

    bool product::getLimitOnly() const {
        return data.get<bool>("limit_only");
    }

    bool product::getPostOnly() const {
        return data.get<bool>("post_only");
    }

    bool product::getTradingDisabled() const {
        return data.get<bool>("trading_disabled");
    }

    product::product(const pt::ptree &data) : data(data) {}
} // namespace responses