//
// Created by Bradley Bottomlee on 2/23/21.
//

#ifndef CBPRO_TICKER_H
#define CBPRO_TICKER_H

#include <boost/property_tree/ptree.hpp>

namespace pt = boost::property_tree;

namespace responses {
    class ticker {
    public:
        explicit ticker(const pt::ptree &data);

        [[nodiscard]] std::string getTradeId() const;

        [[nodiscard]] std::string getPrice() const;

        [[nodiscard]] std::string getSize() const;

        [[nodiscard]] std::string getBid() const;

        [[nodiscard]] std::string getAsk() const;

        [[nodiscard]] std::string getVolume() const;

        [[nodiscard]] std::string getTime() const;

    private:
        pt::ptree data;
    };
} // namespace responses

#endif //CBPRO_TICKER_H
