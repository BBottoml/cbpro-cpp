//
// Created by Bradley Bottomlee on 1/4/21.
//

#include <iostream>
#include <unordered_map>

#include "httpclient.h"

// TODO:
/***
 * Refactor HttpClient constructor to take auth object
 * auth object has enum value (sandbox, live)
 * simple condition to assign host and port
 *
 * i.e., host and port are no longer members of httpclient
 *
 * figure out way to store results of resolve once
 *
 */

HttpClient::HttpClient(const Auth &auth) : auth(auth) {
    version = 11;

    ctx = std::make_shared<ssl::context>(ssl::context::sslv23);
    ioc = std::make_shared<net::io_context>();
    ctx->set_default_verify_paths();

    resolver = std::make_shared<tcp::resolver>((*ioc));
}

HttpClient::~HttpClient() = default;

auto HttpClient::resolveResults() {
    auto const host = auth.getMode() == Auth::Mode::SANDBOX ? "api-public.sandbox.pro.coinbase.com" : "NOT";
    auto const port = "443";

    return resolver->resolve(host, port);
}

pt::ptree
HttpClient::makeRequest(const std::string &target, const std::string &body, HttpClient::RequestVerb rv) {
    auto boostVerb = rv == HttpClient::RequestVerb::GET ? http::verb::get : http::verb::post;
    auto signature = createSignature(target, body, rv);
    std::unordered_map<std::string, std::string> headers; // initialize with expected headers
    // TODO: implement boost calls
    return {};
}

pt::ptree
HttpClient::makeRequest(const std::string &target) {
    try {

        beast::ssl_stream<beast::tcp_stream> stream(*ioc, *ctx);

        auto const host = auth.getMode() == Auth::Mode::SANDBOX ? "api-public.sandbox.pro.coinbase.com" : "NOT";
        auto const port = "443";

        if (!SSL_set_tlsext_host_name(stream.native_handle(), host)) {
            //beast::error_code ec{static_cast<int>(::ERR_get_error()), net::error::get_ssl_category()};
            //throw beast::system_error{ec};
            std::cerr << "SNI hostname could not be set correctly" << std::endl;
        }

        // TODO: Make results member of HttpClient=
        //auto const results = resolver->resolve(host, port);
        tcp::resolver resolver2(*ioc);

        //auto host2 = "api-public.sandbox.pro.coinbase.com";
        tcp::resolver::query query(tcp::v4(), host, port);
        auto const results = resolver->resolve(query);

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
        std::cout << ss.str() << std::endl;

        pt::ptree resp;
        pt::read_json(ss, resp);
        //std::cout << resp.get<std::string>("epoch") << std::endl;
        //std::cout << resp.get<std::string>("iso") << std::endl;

        beast::error_code ec;
        stream.shutdown(ec);

        /*
        if(ec == net::error::eof)
        {
            // Rationale:
            // http://stackoverflow.com/questions/25587403/boost-asio-ssl-async-shutdown-always-finishes-with-an-error
            ec = {};
        }
        if(ec)
            std::cout << "error" << std::endl;
        */

        return resp;
    }
    catch (std::exception const &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }
}

std::string HttpClient::createSignature(const std::string &target, const std::string &body,
                                        HttpClient::RequestVerb rv) {
    std::unordered_map<std::string, std::string> map;
    auto time = makeRequest("/time").get<std::string>(
            "epoch");  // json response from time endpoint
    auto message = time + (rv == HttpClient::RequestVerb::GET ? "GET" : "POST") + target + body;

    const std::string &preDecodeSecret = auth.getApiSecret();
    std::string postDecodeSecret;
    macaron::Base64::Decode(preDecodeSecret, postDecodeSecret);


    return std::string();
}


