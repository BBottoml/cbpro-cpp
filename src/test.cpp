//
// Created by Bradley Bottomlee on 1/7/21.
//
#include <cbpro++/test.h>
#include "util/HttpClient.h"

test::test() = default;

void test::hitEndpoint() {
    HttpClient a;
    a.makeRequest("/time", HttpClient::RequestType::GET);
}

