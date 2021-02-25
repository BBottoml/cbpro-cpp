//
// Created by Bradley Bottomlee on 1/4/21.
//

#include <iostream>
#include <unordered_map>

#include "httpclient.h"

HttpClient::HttpClient(std::string &apiKey, std::string &apiSecret, std::string &passphrase,
                       bool mode) : apiKey(apiKey),
                                    apiSecret(apiSecret), passphrase(passphrase), mode(mode) {
    version = 11;

    ctx = std::make_shared<ssl::context>(ssl::context::sslv23);
    ioc = std::make_shared<net::io_context>();
    ctx->set_default_verify_paths();

    resolver = std::make_shared<tcp::resolver>((*ioc));
    auto const host = mode ? "api.pro.coinbase.com" : "api-public.sandbox.pro.coinbase.com";
    auto const port = "443";

    results = resolver->resolve(host, port);
}

HttpClient::~HttpClient() = default;

/**
 * Signed GET | POST request
 * @param target
 * @param body
 * @param rv
 * @return
 */
pt::ptree
HttpClient::makeRequest(const std::string &target, const std::string &body, HttpClient::RequestVerb rv) {
    http::verb boostVerb;
    std::string messageVerb;
    if (rv == HttpClient::RequestVerb::GET) {
        messageVerb = "GET";
        boostVerb = http::verb::get;
    } else if (rv == HttpClient::RequestVerb::POST) {
        messageVerb = "POST";
        boostVerb = http::verb::post;
    } else {
        messageVerb = "DELETE";
        boostVerb = http::verb::delete_;
    }

    // construct necessary signature
    // TODO: Replace need to hit time endpoint as it is highly inefficient
    auto timestamp = makeRequest("/time").get<std::string>("epoch");  // response from time endpoint
    auto message = timestamp + messageVerb + target + body;

    std::string postDecodeSecret;
    macaron::Base64::Decode(apiSecret, postDecodeSecret);

    char *key = strdup(postDecodeSecret.c_str());
    int key_len = strlen(key);

    const auto *data = (const unsigned char *) strdup(message.c_str());
    int data_len = strlen((char *) data);
    unsigned char *md = nullptr;
    unsigned int md_len = -1;

    md = HMAC(EVP_sha256(), (const void *) key, key_len, data, data_len, md, &md_len);

    const char *preEncodeSignature_c = strdup(reinterpret_cast<const char *>(md));
    std::string preEncodeSignature(preEncodeSignature_c);
    std::string postEncodeSignature = macaron::Base64::Encode(preEncodeSignature);

    free(key);
    free((char *) data);
    free((char *) preEncodeSignature_c);

    boost::replace_all(postEncodeSignature, "\n", "");

    try {

        beast::ssl_stream<beast::tcp_stream> stream(*ioc, *ctx);

        auto const host = mode ? "api.pro.coinbase.com" : "api-public.sandbox.pro.coinbase.com";

        if (!SSL_set_tlsext_host_name(stream.native_handle(), host)) {
            std::cerr << "Error: SNI host name set incorrectly" << std::endl;
        }

        beast::get_lowest_layer(stream).connect(results);

        stream.handshake(ssl::stream_base::client);

        http::request<http::string_body> req{boostVerb, target, version};
        req.set(http::field::host, host);
        req.set(http::field::content_type, "application/json");
        req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);
        req.set("CB-ACCESS-SIGN", postEncodeSignature);
        req.set("CB-ACCESS-TIMESTAMP", timestamp);
        req.set("CB-ACCESS-KEY", apiKey);
        req.set("CB-ACCESS-PASSPHRASE", passphrase);
        if (body.length() != 0) {
            req.body() = body;
            req.prepare_payload();
        }

        http::write(stream, req);

        beast::flat_buffer buffer;

        http::response<http::dynamic_body> res;

        http::read(stream, buffer, res);

        // std::cout << res.result_int() << std::endl;
        if (res.result_int() == 400 || res.result_int() == 404) {
            pt::ptree failResp;
            failResp.put("error", true);
            return failResp;
        }

        std::stringstream ss;
        ss << std::string(boost::asio::buffers_begin(res.body().data()),
                          boost::asio::buffers_end(res.body().data()));
        // std::cout << ss.str() << std::endl;

        pt::ptree resp;
        pt::read_json(ss, resp);

        // determine if IP whitelist is configured correctly
        auto msg = resp.get_optional<std::string>("message");
        if (msg) {
            if (msg.value() == "invalid signature") {
                std::cerr << "Coinbase Connectivity Error: Unknown exception" << std::endl;
                exit(EXIT_FAILURE);
            } else if (msg.value() == "IP does not match IP whitelist") {
                std::cerr << "Coinbase Connectivity Error: IP does not match IP whitelist. See README for details"
                          << std::endl;
                exit(EXIT_FAILURE);
            }
        }

        beast::error_code ec;
        stream.shutdown(ec);

        return resp;
    }
    catch (std::exception const &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

/**
 * Unsigned GET request
 * @param target
 * @return
 */
pt::ptree
HttpClient::makeRequest(const std::string &target) {
    try {

        beast::ssl_stream<beast::tcp_stream> stream(*ioc, *ctx);

        auto const host = mode ? "api.pro.coinbase.com" : "api-public.sandbox.pro.coinbase.com";

        if (!SSL_set_tlsext_host_name(stream.native_handle(), host)) {
            std::cerr << "Error: SNI host name set incorrectly" << std::endl;
        }

        beast::get_lowest_layer(stream).connect(results);

        stream.handshake(ssl::stream_base::client);

        http::request<http::string_body> req{http::verb::get, target, version};
        req.set(http::field::host, host);
        req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

        http::write(stream, req);

        beast::flat_buffer buffer;

        http::response<http::dynamic_body> res;

        http::read(stream, buffer, res);

        std::stringstream ss;
        ss << std::string(boost::asio::buffers_begin(res.body().data()),
                          boost::asio::buffers_end(res.body().data()));
        //std::cout << ss.str() << std::endl;

        pt::ptree resp;
        pt::read_json(ss, resp);

        beast::error_code ec;
        stream.shutdown(ec);

        return resp;
    }
    catch (std::exception const &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }
}
