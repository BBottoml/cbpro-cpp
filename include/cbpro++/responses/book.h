//
// Created by Bradley Bottomlee on 2/7/21.
//

#ifndef CBPRO_BOOK_H
#define CBPRO_BOOK_H

#include <vector>
#include <string>
#include <cbpro++/responses/bid.h>
#include <cbpro++/responses/ask.h>


namespace responses {
    template <class X, class Y>
    class book {
    public:
        book(std::vector<X> bids, std::vector<Y> asks, long sequence) : bids(std::move(bids)),
                                                                        asks(std::move(asks)),
                                                                        sequence(sequence) {}
        const std::vector<X> &getBids() const {
            return bids;
        }

        const std::vector<Y> &getAsks() const {
            return asks;
        }

        long getSequence() const {
            return sequence;
        }

    private:
        std::vector<X> bids;
        std::vector<Y> asks;
        long sequence;
    };
}

#endif //CBPRO_BOOK_H
