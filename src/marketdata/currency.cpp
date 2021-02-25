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

    std::string
    currency::getDisplayName() const {
        auto details = data.get_child("details");
        auto displayName = data.get_optional<std::string>("display_name");
        return displayName ? displayName.value() : "";
    }

    /**
     *
     * @return processing time in seconds or -1 if not provided in response
     */
    long
    currency::getProcessingTime() const {
        auto details = data.get_child("details");
        auto processingTime = data.get_optional<long>("processing_time_seconds");
        return processingTime ? processingTime.value() : -1;
    }

    /**
     *
     * @return min withdrawal amount or -1 if not provided in response
     */
    long
    currency::minWithdrawalAmount() const {
        auto details = data.get_child("details");
        auto amount = data.get_optional<long>("min_withdrawal_amount");
        return amount ? amount.value() : -1;
    }

    /**
     *
     * @return max withdrawal amount or -1 if not provided in response
     */
    long
    currency::maxWithdrawalAmount() const {
        auto details = data.get_child("details");
        auto amount = data.get_optional<long>("max_withdrawal_amount");
        return amount ? amount.value() : -1;
    }

    currency::currency(const pt::ptree &data) : data(data) {}
} // namespace responses