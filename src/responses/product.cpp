//
// Created by Bradley Bottomlee on 1/22/21.
//

#include <string>
#include <cbpro++/responses/product.h>

const std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> &
responses::Product::getId() const {
    return id;
}

const std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> &
responses::Product::getDisplayName() const {
    return displayName;
}

const std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> &
responses::Product::getBaseCurrency() const {
    return baseCurrency;
}

const std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> &
responses::Product::getQuoteCurrency() const {
    return quoteCurrency;
}

const std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> &
responses::Product::getBaseIncrement() const {
    return baseIncrement;
}

const std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> &
responses::Product::getQuoteIncrement() const {
    return quoteIncrement;
}

const std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> &
responses::Product::getBaseMinSize() const {
    return baseMinSize;
}

const std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> &
responses::Product::getBaseMaxSize() const {
    return baseMaxSize;
}

const std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> &
responses::Product::getMinMarketFunds() const {
    return minMarketFunds;
}

const std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> &
responses::Product::getMaxMarketFunds() const {
    return maxMarketFunds;
}

const std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> &
responses::Product::getStatus() const {
    return status;
}

const std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> &
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
