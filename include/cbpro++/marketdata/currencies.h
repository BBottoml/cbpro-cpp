//
// Created by Bradley Bottomlee on 1/22/21.
//

#ifndef CBPRO_CURRENCIES_H
#define CBPRO_CURRENCIES_H

#include <cbpro++/auth.h>
#include <cbpro++/responses/currency.h>


namespace marketdata {
    namespace currencies {

        responses::currency getCurrency(Auth &auth, std::string &id);

        std::vector<responses::currency> getCurrencies(Auth &auth);


    } // namespace currencies
} // namespace marketdata

#endif //CBPRO_CURRENCIES_H
