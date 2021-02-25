# cbpro++
A Coinbase Pro API client library for C++ (C++17). 

## Summary
cbpro++ allows users to easily connect to and trade on the Coinbase Pro exchange. The library has minimal dependencies 
and enables users to get started quickly. Note: This library is still in active development so it is advised to rigorously 
test any implementation in Sandbox mode prior to live trading. Additionally, HTTP is currently the only connection 
method supported by the library (all HTTP calls are made synchronously). WebSocket support is currently in development 
with FIX support being explored. Any and all contributions, issues, and feedback are welcome. Lastly, this library is 
intended for UNIX based systems (i.e., Linux, MacOS) and has not been tested on Windows.

## Dependencies
The library has two primary dependencies: 
1. Boost (v1.72.0+)
1. libssl-dev

When building the library, it is expected that these dependencies are installed globally. If these dependencies are not 
installed globally, you will need to set certain CMake variables (this is demonstrated below).

## Building and Installing
```
$ git clone https://github.com/BBottoml/cbpro-cpp.git
$ cd cbpro-cpp
$ mkdir build
$ cd build
$ cmake .. -DCMAKE_BUILD_TYPE=Release -DOPENSSL_ROOT_DIR=<OPEN_SSL_ROOT_HERE> -DBOOST_ROOT=<BOOST_ROOT_HERE>
$ make && make install
```
Remark: The latter two CMake variables are only necessary if the two respective dependencies are not installed globally.

To use the library:
```
find_package(cbpro++ REQUIRED)
target_link_libraries(<YOUR_EXECUTABLE> PRIVATE cbpro++::cbpro++)
```

## Usage 
To see how to use the library, visit the examples directory to view a number of use cases. Additionally, it is still 
recommended that you familiarize yourself with the [Coinbase Pro API documentation](https://docs.pro.coinbase.com/).

## Remarks
* IP Whitelist issue. Although this is not a library specific issue, you may still encouter this issue. When whitelisting your IPs, whitelist both your IPv6 and IPv4 addresses (if applicable) using [CIDR notation](https://en.wikipedia.org/wiki/Classless_Inter-Domain_Routing#CIDR_notation). 
* Numeric values as strings. Throughout the library, you may notice that certain values that one would anticipate to be a numeric type (e.g., double, long) are represented as strings. Although this may seem like an inconvenience, [Coinbase](https://docs.pro.coinbase.com/#types) recommends using strings to maintain precision when sending requests. Additionally, numeric values are returned as strings from coinbase. Since it is a trivial matter to convert strings to numeric types using standard library functions (e.g., std::stod for string to double) and vice versa, this is left to the user. 

## Features
- [x] Market data: product(s) retrieval
- [x] Market data: order book retrieval  
- [x] Market data: ticker retrieval 
- [x] Market data: trade retrieval
- [x] Market data: 24 hr stats
- [x] Market data: currency + currencies retrieval
- [ ] Market data: historical stats    
- [ ] WebSocket support

## Misc
- [ ] Improve error handling 
- [ ] Investigate moving from property tree to actual json parser 


## Contributors 
* [BBottoml](https://github.com/BBottoml) (Principal maintainer)

Read more about this project [here](https://bottomlee.dev/cbpro)
