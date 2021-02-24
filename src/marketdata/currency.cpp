//
// Created by Bradley Bottomlee on 2/23/21.
//

#include <cbpro++/marketdata/currency.h>

namespace responses {

    std::string
    currency::getId() const {
        return data.get<std::string>("id");
    }

    std::string
    currency::getName() const {
        return data.get<std::string>("name");
    }

    std::string
    currency::getMinSize() const {
        return data.get<std::string>("min_size");
    }

    std::string
    currency::getStatus() const {
        return data.get<std::string>("status");;
    }

    std::string
    currency::getMessage() const {
        return data.get<std::string>("message");;
    }

    std::string
    currency::getMaxPrecision() const {
        return data.get<std::string>("max_precision");
    }

    std::string
    currency::getType() const {
        auto details = data.get_child("details");
        return details.get<std::string>("type");
    }

    std::string
    currency::getSymbol() const {
        auto details = data.get_child("details");
        return details.get<std::string>("symbol");
    }

    std::string
    currency::getNetworkConfirmations() const {
        auto details = data.get_child("details");
        return details.get<std::string>("network_confirmations");
    }

    std::string
    currency::getSortOrder() const {
        auto details = data.get_child("details");
        return details.get<std::string>("sort_order");
    }

    std::string
    currency::getCryptoAddressLink() const {
        auto details = data.get_child("details");
        return details.get<std::string>("crypto_address_link");
    }

    std::string
    currency::getCryptoTransactionLink() const {
        auto details = data.get_child("details");
        return details.get<std::string>("crypto_transaction_link");
    }

    currency::currency(const pt::ptree &data) : data(data) {}
} // namespace responses