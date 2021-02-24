//
// Created by Bradley Bottomlee on 2/24/21.
//
#include <cbpro++/accounts/hold.h>

namespace responses {

    std::string
    hold::getId() const {
        return data.get<std::string>("id");
    }

    std::string
    hold::getAccountId() const {
        return data.get<std::string>("account_id");
    }

    std::string
    hold::getCreatedAt() const {
        return data.get<std::string>("created_at");
    }

    std::string
    hold::getUpdatedAt() const {
        return data.get<std::string>("updated_at");
    }

    std::string
    hold::getAmount() const {
        return data.get<std::string>("amount");
    }

    std::string
    hold::getType() const {
        return data.get<std::string>("type");
    }

    std::string
    hold::getRef() const {
        return data.get<std::string>("ref");
    }

    hold::hold(const pt::ptree &data) : data(data) {}

} // namespace responses

