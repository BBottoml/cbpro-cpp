//
// Created by Bradley Bottomlee on 2/24/21.
//

#include <cbpro++/orders/orders.h>
#include <iostream>

namespace orders {
    bool cancelOrder(Auth &auth, const std::string &id, const std::string &productId, bool isClientOid) {
        const auto &httpClient = auth.getHttpClientPtr();

        std::string target = "/orders/";
        if (isClientOid) {
            target += "client:";
        }
        target += id;
        if (!productId.empty()) {
            target += "?product_id=";
            target += productId;
        }

        auto resp = httpClient->makeRequest(target, "", HttpClient::RequestVerb::E_DELETE);
        return !resp.get_optional<bool>("error");

    }

    std::vector<std::string> cancelAllOrders(Auth &auth, const std::string &productId) {
        const auto &httpClient = auth.getHttpClientPtr();

        std::string target = "/orders";
        if (productId.length() != 0) {
            target += "?product_id=";
            target += productId;
        }

        std::vector<std::string> orders;
        auto resp = httpClient->makeRequest(target, "", HttpClient::RequestVerb::E_DELETE);
        for (auto &order : resp) {
            orders.push_back(order.second.data());
        }
        return orders;
    }

    /**
     * Place a market order. One or both of size or funds must be specified
     * @param auth
     * @param productId
     * @param side
     * @param size
     * @param funds
     * @param opts
     * @return order object — getOrderOutcome tells whether order was placed successfully
     */
    responses::order
    placeMarketOrder(Auth &auth, const std::string &productId, orders::OrderSide side, const std::string &size,
                     const std::string &funds, const orders::options &opts) {
        if (size.length() == 0 && funds.length() == 0) {
            std::cerr << "Error: One or both of size or funds must be specified for market order." << std::endl;
            exit(EXIT_FAILURE);
        }

        const auto &httpClient = auth.getHttpClientPtr();
        std::string target = "/orders";

        pt::ptree body;
        body.put("product_id", productId);
        body.put("side", (side == orders::OrderSide::BUY ? "buy" : "sell"));
        if (size.length() != 0)
            body.put("size", size);
        if (funds.length() != 0)
            body.put("funds", funds);
        body.put("type", "market");

        if (!opts.getClientOid().empty()) {
            body.put("client_oid", opts.getClientOid());
        }
        if (!opts.getStp().empty()) {
            body.put("stp", opts.getStp());
        }

        if (!opts.getStopPrice().empty() && !opts.getStop().empty()) {
            body.put("stop_price", opts.getStopPrice());
            body.put("stop", opts.getStop());
        }

        std::basic_stringstream<char> jsonStream;
        pt::json_parser::write_json(jsonStream, body, false);

        auto jsonBody = jsonStream.str();
        boost::replace_all(jsonBody, "\n", "");

        auto resp = httpClient->makeRequest(target, jsonBody, HttpClient::RequestVerb::E_POST);
        responses::order order(resp);
        return order;
    }

    /**
     * Place a limit order
     * @param auth
     * @param productId
     * @param side
     * @param size
     * @param funds
     * @param opts
     * @return order object — getOrderOutcome tells whether order was placed successfully
     */
    responses::order
    placeLimitOrder(Auth &auth, const std::string &productId, orders::OrderSide side, const std::string &size,
                    const std::string &price, const orders::options &opts) {
        const auto &httpClient = auth.getHttpClientPtr();
        std::string target = "/orders";

        pt::ptree body;
        body.put("product_id", productId);
        body.put("side", (side == orders::OrderSide::BUY ? "buy" : "sell"));
        body.put("size", size);
        body.put("price", price);
        body.put("type", "limit");

        if (!opts.getClientOid().empty()) {
            body.put("client_oid", opts.getClientOid());
        }
        if (!opts.getStp().empty()) {
            body.put("stp", opts.getStp());
        }
        if (!opts.getTimeInForce().empty()) {
            body.put("time_in_force", opts.getTimeInForce());
        }

        if (!opts.getStopPrice().empty() && !opts.getStop().empty()) {
            body.put("stop_price", opts.getStopPrice());
            body.put("stop", opts.getStop());
        } else if (!opts.getStopPrice().empty() != !opts.getStop().empty()) {
            std::cerr << "Error: Both stop limit and stop price need to be specified or neither." << std::endl;
            exit(EXIT_FAILURE);
        }
        if (!opts.getCancelAfter().empty()) {
            if (opts.getTimeInForce() != "GTT") {
                std::cerr << "Error: Cancel after can only be specified if time in force is good till time (GTT)"
                          << std::endl;
                exit(EXIT_FAILURE);
            }
            body.put("cancel_after", opts.getCancelAfter());
        }
        if (opts.isPostOnly()) {
            if (opts.getTimeInForce() == "IOC" || opts.getTimeInForce() == "FOK") {
                std::cerr << "Error: Post only is only valid if time in force is GTC or GTT" << std::endl;
                exit(EXIT_FAILURE);
            }
            body.put("post_only", true);
        }

        std::basic_stringstream<char> jsonStream;
        pt::json_parser::write_json(jsonStream, body, false);

        auto jsonBody = jsonStream.str();
        boost::replace_all(jsonBody, "\n", "");

        auto resp = httpClient->makeRequest(target, jsonBody, HttpClient::RequestVerb::E_POST);
        responses::order order(resp);
        return order;
    }

    std::vector<responses::order>
    getOrders(Auth &auth, const std::string &productId, bool open, bool pending, bool active) {
        const auto &httpClient = auth.getHttpClientPtr();

        std::string target = "/orders?";
        std::string amp;

        if (open) {
            target += "status=open";
            amp = "&";
        }
        if (pending) {
            target += amp;
            target += "status=pending";
            amp = "&";
        }
        if (active) {
            target += amp;
            target += "status=active";
            amp = "&";
        }
        if (productId.length() != 0) {
            target += amp;
            target += "product_id=";
            target += productId;
        }

        std::vector<responses::order> orders;
        auto resp = httpClient->makeRequest(target, "", HttpClient::RequestVerb::E_GET);
        for (const auto &ord : resp) {
            responses::order order(ord.second);
            orders.push_back(order);
        }

        return orders;
    }

    responses::order
    getOrder(Auth &auth, const std::string &orderId, bool isClientOid) {
        const auto &httpClient = auth.getHttpClientPtr();

        std::string target = "/orders/";
        if (isClientOid) {
            target += "client:";
        }
        target += orderId;
        auto resp = httpClient->makeRequest(target, "", HttpClient::RequestVerb::E_GET);
        responses::order order(resp);
        return order;
    }

} // namespace orders
