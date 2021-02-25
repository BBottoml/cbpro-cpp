#include <iostream> 
#include <cbpro++/Auth.h> 
#include <cbpro++/orders/orders.h> 

int main() {
    Auth auth("<API-KEY>", "<API-SECRET>", "<PASSPHRASE>", Auth::Mode::SANDBOX);

    auto tr1 = orders::placeMarketOrder(auth, "BTC-USD", orders::OrderSide::BUY, "", "150");
    std::cout << tr1.getId() << std::endl;

    orders::options opts;
    opts.setTimeInForce("GTT");
    opts.setCancelAfter("min");

    auto tr2 = orders::placeLimitOrder(auth, "BTC-USD", orders::OrderSide::BUY, "0.01", "40000", opts);
    std::cout << tr2.getId() << std::endl; 

    return 0; 
}