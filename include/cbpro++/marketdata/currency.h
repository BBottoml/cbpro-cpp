//
// Created by Bradley Bottomlee on 2/23/21.
//

#ifndef CBPRO_CURRENCY_H
#define CBPRO_CURRENCY_H

#include <string>
#include <vector>
#include <boost/property_tree/ptree.hpp>

namespace pt = boost::property_tree;

namespace responses {
    class currency {
    public:
        explicit currency(const pt::ptree &data);

        [[nodiscard]] std::string getId() const;

        [[nodiscard]] std::string getName() const;

        [[nodiscard]] std::string getMinSize() const;

        [[nodiscard]] std::string getStatus() const;

        [[nodiscard]] std::string getMaxPrecision() const;

        [[nodiscard]] std::string getMessage() const;

        [[nodiscard]] std::string getType() const;

        [[nodiscard]] std::string getSymbol() const;

        [[nodiscard]] std::string getNetworkConfirmations() const;

        [[nodiscard]] std::string getSortOrder() const;

        [[nodiscard]] std::string getCryptoAddressLink() const;

        [[nodiscard]] std::string getCryptoTransactionLink() const;

        [[nodiscard]] std::string getDisplayName() const;

        [[nodiscard]] long getProcessingTime() const;

        [[nodiscard]] long minWithdrawalAmount() const;

        [[nodiscard]] long maxWithdrawalAmount() const;


    private:
        pt::ptree data;
    };

} // namespace responses


#endif //CBPRO_CURRENCY_H
