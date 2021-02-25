Explanation: In this example we retrieve the full order book for the BTC-USD product (i.e., every bid and ask currently for the product). Once we have retrieved the order book, we simply output all order ids with a size greater than 5. 

Lastly, see the 4th argument for the Auth object. This argument takes an enum value of Auth::Mode which can either be SANDBOX or LIVE. SANDBOX refers to trading on the Coinbase Pro Sandbox exchange whereas LIVE refers to actual live trading (proceed with caution if live trading). 

[See on Coinbase](https://docs.pro.coinbase.com/?javascript#get-product-order-book)