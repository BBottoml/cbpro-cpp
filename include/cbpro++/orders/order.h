//
// Created by Bradley Bottomlee on 2/24/21.
//

#ifndef CBPRO_ORDER_H
#define CBPRO_ORDER_H

#include <string>
#include <boost/property_tree/ptree.hpp>

namespace pt = boost::property_tree;

namespace responses {

    class order {
    public:
        order(const pt::ptree &data);

        [[nodiscard]] bool getOrderOutcome() const;

        [[nodiscard]] std::string getId() const;

        [[nodiscard]] std::string getPrice() const;

        [[nodiscard]] std::string getSize() const;

        [[nodiscard]] std::string getProductId() const;

        [[nodiscard]] std::string getSide() const;

        [[nodiscard]] std::string getStp() const;

        [[nodiscard]] std::string getType() const;

        [[nodiscard]] std::string getTimeInForce() const;

        [[nodiscard]] std::string getCreatedAt() const;

        [[nodiscard]] std::string getFillFees() const;

        [[nodiscard]] std::string getFilledSize() const;

        [[nodiscard]] std::string getExecutedValue() const;

        [[nodiscard]] std::string getStatus() const;

        [[nodiscard]] bool getPostOnly() const;

        [[nodiscard]] bool getSettled() const;

    private:
        pt::ptree data;

    };

} // namespace responses

#endif //CBPRO_ORDER_H
