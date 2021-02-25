# Examples/usage

To get started, there are only a handful of header files you need to familarize yourself with. Namely: 
* cbpro++/marketdata/products.h 
* cbpro++/marketdata/currencies.h
* cbpro++/accounts/accounts.h
* cbpro++/orders/orders.h
* cbpro++/auth.h

(As the library expands and covers more functionality, there may be additional headers). 

When you make a request, typically an object (or a vector of objects) encapsulating the Coinbase response is returned. You don't need to 
concern yourself with the various response types (simply use auto). Within the following directories are select examples of what can be 
done with the library. 
