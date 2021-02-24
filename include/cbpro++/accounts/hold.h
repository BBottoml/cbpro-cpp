//
// Created by Bradley Bottomlee on 2/24/21.
//

#ifndef CBPRO_HOLD_H
#define CBPRO_HOLD_H

#include <string>
#include <vector>
#include <boost/property_tree/ptree.hpp>

namespace pt = boost::property_tree;

namespace responses {
    class hold {
    public:
        explicit hold(const pt::ptree &data);

        [[nodiscard]] std::string getId() const;

        [[nodiscard]] std::string getCreatedAt() const;

        [[nodiscard]] std::string getUpdatedAt() const;

        [[nodiscard]] std::string getAccountId() const;

        [[nodiscard]] std::string getAmount() const;

        [[nodiscard]] std::string getType() const;

        [[nodiscard]] std::string getRef() const;

    private:
        pt::ptree data;
    };
} // namespace responses

#endif //CBPRO_HOLD_H
