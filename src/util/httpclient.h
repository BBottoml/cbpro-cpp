//
// Created by Bradley Bottomlee on 1/4/21.
//

#ifndef CBPRO_HTTPCLIENT_H
#define CBPRO_HTTPCLIENT_H

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <boost/asio/buffers_iterator.hpp>
#include <boost/asio/buffers_iterator.hpp>
#include <boost/algorithm/string.hpp>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <openssl/hmac.h>
#include <openssl/evp.h>

#include "Base64.h"

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = net::ip::tcp;
namespace ssl = boost::asio::ssl;       // from <boost/asio/ssl.hpp>

namespace pt = boost::property_tree;

class HttpClient {
public:
    HttpClient(std::string &apiKey, std::string &apiSecret, std::string &passphrase, bool mode);

    ~HttpClient();

    enum class RequestVerb {
        GET, POST, DELETE
    }; // scoped enum

    pt::ptree makeRequest(const std::string &target);

    pt::ptree makeRequest(const std::string &target, const std::string &body, HttpClient::RequestVerb);

private:
    std::shared_ptr<net::io_context> ioc;
    std::shared_ptr<ssl::context> ctx;
    std::shared_ptr<tcp::resolver> resolver;
    boost::asio::ip::tcp::resolver::results_type results;
    // std::shared_ptr<beast::ssl_stream<beast::tcp_stream>> stream;

    std::string apiKey;
    std::string apiSecret;
    std::string passphrase;
    bool mode;
    int version;

};

#endif //CBPRO_HTTPCLIENT_H