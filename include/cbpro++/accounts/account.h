//
// Created by Bradley Bottomlee on 2/24/21.
//

#ifndef CBPRO_ACCOUNT_H
#define CBPRO_ACCOUNT_H

#include <string>
#include <vector>
#include <boost/property_tree/ptree.hpp>

namespace pt = boost::property_tree;

namespace responses {
    class account {
    public:
        explicit account(const pt::ptree &data);

        [[nodiscard]] std::string getId() const;

        [[nodiscard]] std::string getCurrency() const;

        [[nodiscard]] std::string getBalance() const;

        [[nodiscard]] std::string getAvailable() const;

        [[nodiscard]] std::string getHold() const;

        [[nodiscard]] std::string getProfileId() const;

        [[nodiscard]] bool getTradingEnabled() const;

    private:
        pt::ptree data;
    };

} // namespace responses
#endif //CBPRO_ACCOUNT_H