//
// Created by Bradley Bottomlee on 1/22/21.
//
#include <cbpro++/marketdata/currencies.h>

namespace marketdata {
    namespace currencies {

        responses::currency getCurrency(Auth &auth, std::string &id) {
            const auto &httpClient = auth.getHttpClientPtr();

            std::string target = "/currencies/";
            target += id;
            auto resp = httpClient->makeRequest(target);

            responses::currency currency(resp);
            return currency;
        }

        std::vector<responses::currency> getCurrencies(Auth &auth) {
            const auto &httpClient = auth.getHttpClientPtr();
            auto resp = httpClient->makeRequest("/currencies");

            std::vector<responses::currency> currencies;
            for (const auto &curr : resp) {
                responses::currency currency(curr.second);
                currencies.push_back(currency);
            }

            return currencies;
        }

    } // namespace currencies
} // namespace marketdata



