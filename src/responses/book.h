//
// Created by Bradley Bottomlee on 2/7/21.
//

#ifndef CBPRO_BOOK_H
#define CBPRO_BOOK_H

#include <vector>
#include <string>

namespace responses {
    class book {
    public:
        book(std::vector<std::vector<std::string>> bids, std::vector<std::vector<std::string>> asks,
             long sequence);

        [[nodiscard]] const std::vector<std::vector<std::string>> &getBids() const;

        [[nodiscard]] const std::vector<std::vector<std::string>> &getAsks() const;

        [[nodiscard]] long getSequence() const;

    private:
        std::vector<> bids;
        std::vector<std::vector<std::string>> asks;
        long sequence;
    };
}

#endif //CBPRO_BOOK_H
