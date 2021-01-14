//
// Created by Bradley Bottomlee on 1/4/21.
//

#include <iostream>
#include "HttpClient.h"
#include "root_certificates.hpp"

HttpClient::HttpClient() = default;

HttpClient::~HttpClient() = default;

pt::ptree HttpClient::makeRequest(std::string endpoint, HttpClient::RequestType, Auth &auth) {
    return boost::property_tree::ptree();
}

pt::ptree HttpClient::makeRequest(const std::string &target, HttpClient::RequestType) {
    try {
        auto const host = "api-public.sandbox.pro.coinbase.com";
        auto const port = "443";
        int version = 11;


        net::io_context ioc;

        // The SSL context is required, and holds certificates
        ssl::context ctx(ssl::context::tlsv12_client);

        // This holds the root certificate used for verification
        load_root_certificates(ctx);

        // Verify the remote server's certificate
        ctx.set_verify_mode(ssl::verify_peer);

        // These objects perform our I/O
        tcp::resolver resolver(ioc);
        beast::ssl_stream<beast::tcp_stream> stream(ioc, ctx);

        // Set SNI Hostname (many hosts need this to handshake successfully)
        if(! SSL_set_tlsext_host_name(stream.native_handle(), host))
        {
            //beast::error_code ec{static_cast<int>(::ERR_get_error()), net::error::get_ssl_category()};
            //throw beast::system_error{ec};
            std::cerr << "SNI hostname could not be set correctly" << std::endl;
        }

        // Look up the domain name
        auto const results = resolver.resolve(host, port);

        // Make the connection on the IP address we get from a lookup
        beast::get_lowest_layer(stream).connect(results);

        // Perform the SSL handshake
        stream.handshake(ssl::stream_base::client);

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

        // Gracefully close the stream
        beast::error_code ec;
        stream.shutdown(ec);
        if(ec == net::error::eof)
        {
            // Rationale:
            // http://stackoverflow.com/questions/25587403/boost-asio-ssl-async-shutdown-always-finishes-with-an-error
            ec = {};
        }
        if(ec)
            throw beast::system_error{ec};

        // If we get here then the connection is closed gracefully
    }
    catch(std::exception const& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

std::string HttpClient::createSignature() {
    auto timeResp = makeRequest("/time", HttpClient::RequestType::GET); // json response from time endpoint

    return std::string();
}
