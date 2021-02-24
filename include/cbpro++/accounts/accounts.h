//
// Created by Bradley Bottomlee on 2/24/21.
//

#ifndef CBPRO_ACCOUNTS_H
#define CBPRO_ACCOUNTS_H

#include <cbpro++/auth.h>
#include <cbpro++/accounts/entry.h>
#include <cbpro++/accounts/account.h>
#include <cbpro++/accounts/hold.h>


namespace accounts {

    std::vector<responses::entry> getAccountHistory(Auth &auth, const std::string &accountId);

    std::vector<responses::account> getAccounts(Auth &auth);

    std::vector<responses::hold> getHolds(Auth &auth, const std::string &accountId);

    responses::account getAccount(Auth &auth, const std::string &accountId);

} // namespace accounts


#endif //CBPRO_ACCOUNTS_H
