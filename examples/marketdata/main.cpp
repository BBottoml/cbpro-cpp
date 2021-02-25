#include <iostream> 
#include <cbpro++/auth.h> 
#include <cbpro++/marketdata/products.h> 

int main() {
    Auth auth("<API-KEY>", "<API-SECRET>", "<PASSPHRASE>", Auth::Mode::SANDBOX);

    auto book = marketdata::products::getOrderBookLevelThree(auth, "BTC-USD");
    auto bids = book.getBids();

    for (auto &bid : bids) {
        if (std::stoi(bid.getSize()) > 5) {
            std::cout << bid.getOrderId() << std::endl; 
        }
    } 

    return 0; 
}
