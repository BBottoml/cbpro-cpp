//
// Created by Bradley Bottomlee on 1/22/21.
//

#include <string>
#include <cbpro++/responses/product.h>

const std::string &
responses::Product::getId() const {
    return id;
}

const std::string &
responses::Product::getDisplayName() const {
    return displayName;
}

const std::string &
responses::Product::getBaseCurrency() const {
    return baseCurrency;
}

const std::string &
responses::Product::getQuoteCurrency() const {
    return quoteCurrency;
}

const std::string &
responses::Product::getBaseIncrement() const {
    return baseIncrement;
}

const std::string &
responses::Product::getQuoteIncrement() const {
    return quoteIncrement;
}

const std::string &
responses::Product::getBaseMinSize() const {
    return baseMinSize;
}

const std::string &
responses::Product::getBaseMaxSize() const {
    return baseMaxSize;
}

const std::string &
responses::Product::getMinMarketFunds() const {
    return minMarketFunds;
}

const std::string &
responses::Product::getMaxMarketFunds() const {
    return maxMarketFunds;
}

const std::string &
responses::Product::getStatus() const {
    return status;
}

const std::string &
responses::Product::getStatusMessage() const {
    return statusMessage;
}

const bool &responses::Product::getCancelOnly() const {
    return cancelOnly;
}

const bool &responses::Product::getLimitOnly() const {
    return limitOnly;
}

const bool &responses::Product::getPostOnly() const {
    return postOnly;
}

const bool &responses::Product::getTradingDisabled() const {
    return tradingDisabled;
}
