//
// Created by Bradley Bottomlee on 2/23/21.
//
#include <cbpro++/marketdata/stats.h>

namespace responses {
    std::string
    stats::getOpen() const {
        return data.get<std::string>("open");
    }

    std::string
    stats::getHigh() const {
        return data.get<std::string>("high");
    }

    std::string
    stats::getLow() const {
        return data.get<std::string>("low");
    }

    std::string
    stats::getVolume() const {
        return data.get<std::string>("volume");
    }

    std::string
    stats::getLast() const {
        return data.get<std::string>("last");
    }

    std::string
    stats::getVolume30Day() const {
        return data.get<std::string>("volume_30day");
    }

    stats::stats(const pt::ptree &data) : data(data) {}
} // namespace responses