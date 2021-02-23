//
// Created by Bradley Bottomlee on 1/19/21.
//
#include <cbpro++/marketdata/products.h>


namespace marketdata {
    namespace products {

        std::vector<responses::product> getProducts(Auth &auth) {
            const auto &httpClient = auth.getHttpClientPtr();
            auto resp = httpClient->makeRequest("/products");

            std::vector<responses::product> products;
            for (const auto &prod : resp) {
                responses::product product(prod.second);
                products.push_back(product);
            }

            return products;
        }

        responses::product getProduct(Auth &auth, std::string &productId) {
            const auto &httpClient = auth.getHttpClientPtr();

            std::string target = "/products/";
            target += productId;
            auto resp = httpClient->makeRequest(target);

            responses::product product(resp);
            return product;
        }

        responses::ticker getTicker(Auth &auth, std::string &productId) {
            const auto &httpClient = auth.getHttpClientPtr();

            std::string target = "/products/";
            target += productId;
            target += "/ticker";
            auto resp = httpClient->makeRequest(target);

            responses::ticker ticker(resp);
            return ticker;
        }

        responses::stats getStats(Auth &auth, std::string &productId) {
            const auto &httpClient = auth.getHttpClientPtr();

            std::string target = "/products/";
            target += productId;
            target += "/stats";
            auto resp = httpClient->makeRequest(target);

            responses::stats stats(resp);
            return stats;
        }

        std::vector<responses::trade> getTrades(Auth &auth, std::string &productId) {
            const auto &httpClient = auth.getHttpClientPtr();
            std::string target = "/products/";
            target += productId;
            target += "/trades";
            auto resp = httpClient->makeRequest(target);

            std::vector<responses::trade> trades;
            for (const auto &tr : resp) {
                responses::trade currTrade(tr.second);
                trades.push_back(currTrade);
            }

            return trades;
        }

        template<class X, class Y>
        responses::book<X, Y> getOrderBook(Auth &auth, std::string &productId, std::string &level) {
            const auto &httpClient = auth.getHttpClientPtr();
            std::string target = "/products/";
            target += productId;
            target += "/book";
            target += level;

            auto resp = httpClient->makeRequest(target);

            std::vector<X> bids;
            std::vector<Y> asks;
            long sequence = resp.get<long>("sequence");

            // property tree limitations
            for (auto &bid : resp.get_child("bids")) {
                auto bidIter = bid.second.begin();
                auto price = bidIter->second.data();
                bidIter++;
                auto size = bidIter->second.data();
                bidIter++;
                auto thirdObj = bidIter->second.data();
                X currBid(price, size, thirdObj);
                bids.push_back(currBid);
            }

            for (auto &ask : resp.get_child("asks")) {
                auto askIter = ask.second.begin();
                auto price = askIter->second.data();
                askIter++;
                auto size = askIter->second.data();
                askIter++;
                auto thirdObj = askIter->second.data();
                Y currAsk(price, size, thirdObj);
                asks.push_back(currAsk);
            }

            responses::book<X, Y> currBook(bids, asks, sequence);
            return currBook;
        }

        responses::book<responses::bidLevel1_2, responses::askLevel1_2>
        getOrderBookLevelOne(Auth &auth, std::string &productId) {
            std::string level = "";
            return getOrderBook<responses::bidLevel1_2, responses::askLevel1_2>(auth, productId, level);
        }

        responses::book<responses::bidLevel1_2, responses::askLevel1_2>
        getOrderBookLevelTwo(Auth &auth, std::string &productId) {
            std::string level = "?level=2";
            return getOrderBook<responses::bidLevel1_2, responses::askLevel1_2>(auth, productId, level);
        }

        responses::book<responses::bidLevel3, responses::askLevel3>
        getOrderBookLevelThree(Auth &auth, std::string &productId) {
            std::string level = "?level=3";
            return getOrderBook<responses::bidLevel3, responses::askLevel3>(auth, productId, level);
        }


    } // namespace products
} // namespace marketdata