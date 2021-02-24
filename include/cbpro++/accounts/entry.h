//
// Created by Bradley Bottomlee on 2/24/21.
//

#ifndef CBPRO_ENTRY_H
#define CBPRO_ENTRY_H

#include <string>
#include <vector>
#include <boost/property_tree/ptree.hpp>

namespace pt = boost::property_tree;

namespace responses {
    class entry {
    public:
        explicit entry(const pt::ptree &data);

        [[nodiscard]] std::string getId() const;

        [[nodiscard]] std::string getCreatedAt() const;

        [[nodiscard]] std::string getAmount() const;

        [[nodiscard]] std::string getBalance() const;

        [[nodiscard]] std::string getType() const;

        [[nodiscard]] std::string getOrderId() const;

        [[nodiscard]] std::string getTradeId() const;

        [[nodiscard]] std::string getProductId() const;

    private:
        pt::ptree data;
    };
} // namespace responses

#endif //CBPRO_ENTRY_H
