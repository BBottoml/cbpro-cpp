//
// Created by Bradley Bottomlee on 1/4/21.
//

#include <cbpro++/Auth.h>

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#ifndef CBPRO_HTTPCLIENT_H
#define CBPRO_HTTPCLIENT_H

#endif //CBPRO_HTTPCLIENT_H

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = net::ip::tcp;
namespace ssl = boost::asio::ssl;       // from <boost/asio/ssl.hpp>

namespace pt = boost::property_tree;

class HttpClient {
private:

public:
    HttpClient();

    ~HttpClient();

    enum class RequestType {
        GET, POST, PUT
    }; // scoped enum

    pt::ptree makeRequest(std::string endpoint, HttpClient::RequestType,
                          Auth &auth); // return by value since it is declared within the function
    pt::ptree makeRequest(const std::string& endpoint, HttpClient::RequestType);

    std::string createSignature();


};