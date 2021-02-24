//
// Created by Bradley Bottomlee on 2/24/21.
//

#include <cbpro++/accounts/account.h>

namespace responses {

    std::string
    account::getId() const {
        return data.get<std::string>("id");
    }

    std::string
    account::getCurrency() const {
        auto currency = data.get_optional<std::string>("currency");
        return currency ? currency.value() : "";
    }

    std::string
    account::getBalance() const {
        return data.get<std::string>("balance");
    }

    std::string
    account::getAvailable() const {
        return data.get<std::string>("available");
    }

    std::string
    account::getHold() const {
        return data.get<std::string>("hold");
    }

    std::string
    account::getProfileId() const {
        auto profileId = data.get_optional<std::string>("profileId");
        return profileId ? profileId.value() : "";
    }

    bool
    account::getTradingEnabled() const {
        auto tradingEnabled = data.get_optional<bool>("trading_enabled");
        return tradingEnabled ? tradingEnabled.value() : true;
    }

    account::account(const pt::ptree &data) : data(data) {}

}

