//
// Created by Bradley Bottomlee on 2/23/21.
//

#ifndef CBPRO_TRADE_H
#define CBPRO_TRADE_H

#include <boost/property_tree/ptree.hpp>

namespace pt = boost::property_tree;

namespace responses {
    class trade {
    public:
        explicit trade(const pt::ptree &data);

        [[nodiscard]] std::string getTime() const;

        [[nodiscard]] std::string getTradeId() const;

        [[nodiscard]] std::string getPrice() const;

        [[nodiscard]] std::string getSize() const;

        [[nodiscard]] std::string getSide() const;


    private:
        pt::ptree data;
    };
} // namespace responses

#endif //CBPRO_TRADE_H
