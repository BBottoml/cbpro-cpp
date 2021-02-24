//
// Created by Bradley Bottomlee on 1/22/21.
//

#ifndef CBPRO_PRODUCT_H
#define CBPRO_PRODUCT_H

#include <string>
#include <vector>
#include <boost/property_tree/ptree.hpp>

namespace pt = boost::property_tree;


namespace responses {
    class product {
    public:
        explicit product(const pt::ptree &data);

        [[nodiscard]] std::string getId() const;

        [[nodiscard]] std::string getDisplayName() const;

        [[nodiscard]] std::string getBaseCurrency() const;

        [[nodiscard]] std::string getQuoteCurrency() const;

        [[nodiscard]] std::string getBaseIncrement() const;

        [[nodiscard]] std::string getQuoteIncrement() const;

        [[nodiscard]] std::string getBaseMinSize() const;

        [[nodiscard]] std::string getBaseMaxSize() const;

        [[nodiscard]] std::string getMinMarketFunds() const;

        [[nodiscard]] std::string getMaxMarketFunds() const;

        [[nodiscard]] std::string getStatus() const;

        [[nodiscard]] std::string getStatusMessage() const;

        [[nodiscard]] bool getCancelOnly() const;

        [[nodiscard]] bool getLimitOnly() const;

        [[nodiscard]] bool getPostOnly() const;

        [[nodiscard]] bool getTradingDisabled() const;

    private:
        pt::ptree data;
    };
} // namespace responses
#endif //CBPRO_PRODUCT_H
