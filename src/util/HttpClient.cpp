//
// Created by Bradley Bottomlee on 1/4/21.
//

#include <iostream>
#include "HttpClient.h"

HttpClient::HttpClient() = default;

HttpClient::~HttpClient() = default;

pt::ptree HttpClient::makeRequest(std::string endpoint, HttpClient::RequestType, Auth &auth) {
    return boost::property_tree::ptree();
}

pt::ptree HttpClient::makeRequest(const std::string &target, HttpClient::RequestType) {
    try {
        auto const host = "api-public.sandbox.pro.coinbase.com";
        auto const port = "80";
        int version = 11;

        // The io_context is required for all I/O
        net::io_context ioc;

        // These objects perform our I/O
        tcp::resolver resolver(ioc);
        beast::tcp_stream stream(ioc);

        // Look up the domain name
        auto const results = resolver.resolve(host, port);

        // Make the connection on the IP address we get from a lookup
        stream.connect(results);

        // Set up an HTTP GET request message
        http::request<http::string_body> req{http::verb::get, target, version};
        req.set(http::field::host, host);
        req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

        // Send the HTTP request to the remote host
        http::write(stream, req);

        // This buffer is used for reading and must be persisted
        beast::flat_buffer buffer;

        // Declare a container to hold the response
        http::response<http::dynamic_body> res;

        // Receive the HTTP response
        http::read(stream, buffer, res);

        // Write the message to standard out
        std::cout << res << std::endl;

        // Gracefully close the socket
        beast::error_code ec;
        stream.socket().shutdown(tcp::socket::shutdown_both, ec);

        // not_connected happens sometimes
        // so don't bother reporting it.
        //
        if (ec && ec != beast::errc::not_connected)
            throw beast::system_error{ec};

        // If we get here then the connection is closed gracefully
    }
    catch (std::exception const &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

std::string HttpClient::createSignature() {
    auto timeResp = makeRequest("/time", HttpClient::RequestType::GET); // json response from time endpoint

    return std::string();
}
