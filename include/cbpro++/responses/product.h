//
// Created by Bradley Bottomlee on 1/22/21.
//

#ifndef CBPRO_PRODUCT_H
#define CBPRO_PRODUCT_H

#include <string>
#include <vector>

namespace responses {
    class Product {
    private:
        const std::string &id;
        const std::string &displayName;
        const std::string &baseCurrency;
        const std::string &quoteCurrency;
        const std::string &baseIncrement;
        const std::string &quoteIncrement;
        const std::string &baseMinSize;
        const std::string &baseMaxSize;
        const std::string &minMarketFunds;
        const std::string &maxMarketFunds;
        const std::string &status;
        const std::string &statusMessage;
        const bool &cancelOnly;
        const bool &limitOnly;
        const bool &postOnly;
        const bool &tradingDisabled;
    public:
        [[nodiscard]] const std::string &getId() const;

        [[nodiscard]] const std::string &getDisplayName() const;

        [[nodiscard]] const std::string &getBaseCurrency() const;

        [[nodiscard]] const std::string &getQuoteCurrency() const;

        [[nodiscard]] const std::string &getBaseIncrement() const;

        [[nodiscard]] const std::string &getQuoteIncrement() const;

        [[nodiscard]] const std::string &getBaseMinSize() const;

        [[nodiscard]] const std::string &getBaseMaxSize() const;

        [[nodiscard]] const std::string &getMinMarketFunds() const;

        [[nodiscard]] const std::string &getMaxMarketFunds() const;

        [[nodiscard]] const std::string &getStatus() const;

        [[nodiscard]] const std::string &getStatusMessage() const;

        [[nodiscard]] const bool &getCancelOnly() const;

        [[nodiscard]] const bool &getLimitOnly() const;

        [[nodiscard]] const bool &getPostOnly() const;

        [[nodiscard]] const bool &getTradingDisabled() const;
    };
}
#endif //CBPRO_PRODUCT_H
