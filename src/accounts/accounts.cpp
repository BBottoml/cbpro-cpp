//
// Created by Bradley Bottomlee on 2/24/21.
//
#include <cbpro++/accounts/accounts.h>

namespace accounts {
    std::vector<responses::entry> getAccountHistory(Auth &auth, const std::string &accountId) {
        const auto &httpClient = auth.getHttpClientPtr();

        std::string target = "/accounts/";
        target += accountId;
        target += "/ledger";
        auto resp = httpClient->makeRequest(target, "", HttpClient::RequestVerb::GET);

        std::vector<responses::entry> entries;
        for (const auto &item : resp) {
            responses::entry entry(item.second);
            entries.push_back(entry);
        }

        return entries;
    }

    std::vector<responses::account> getAccounts(Auth &auth) {
        const auto &httpClient = auth.getHttpClientPtr();

        std::string target = "/accounts";
        auto resp = httpClient->makeRequest(target, "", HttpClient::RequestVerb::GET);

        std::vector<responses::account> accounts;
        for (const auto &item : resp) {
            responses::account account(item.second);
            accounts.push_back(account);
        }

        return accounts;
    }

    responses::account getAccount(Auth &auth, const std::string &accountId) {
        const auto &httpClient = auth.getHttpClientPtr();
        std::string target = "/accounts/";
        target += accountId;
        auto resp = httpClient->makeRequest(target, "", HttpClient::RequestVerb::GET);

        responses::account account(resp);
        return account;
    }

    std::vector<responses::hold> getHolds(Auth &auth, const std::string &accountId) {
        const auto &httpClient = auth.getHttpClientPtr();

        std::string target = "/accounts/";
        target += accountId;
        target += "/holds";
        auto resp = httpClient->makeRequest(target, "", HttpClient::RequestVerb::GET);

        std::vector<responses::hold> holds;
        for (const auto &item : resp) {
            responses::hold hold(item.second);
            holds.push_back(hold);
        }

        return holds;
    }
} // namespace accounts
