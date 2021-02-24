//
// Created by Bradley Bottomlee on 2/23/21.
//

#ifndef CBPRO_STATS_H
#define CBPRO_STATS_H

#include <boost/property_tree/ptree.hpp>

namespace pt = boost::property_tree;

namespace responses {
    class stats {
    public:
        explicit stats(const pt::ptree &data);

        [[nodiscard]] std::string getOpen() const;

        [[nodiscard]] std::string getHigh() const;

        [[nodiscard]] std::string getLow() const;

        [[nodiscard]] std::string getVolume() const;

        [[nodiscard]] std::string getLast() const;

        [[nodiscard]] std::string getVolume30Day() const;


    private:
        pt::ptree data;
    };
} // namespace responses

#endif //CBPRO_STATS_H
