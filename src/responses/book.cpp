//
// Created by Bradley Bottomlee on 2/7/21.
//

#include "book.h"

#include <utility>

responses::book::book(std::vector<std::vector<std::string>> bids, std::vector<std::vector<std::string>> asks,
                      long sequence) : bids(std::move(bids)), asks(std::move(asks)), sequence(sequence) {}

const std::vector<std::vector<std::string>> &responses::book::getBids() const {
    return bids;
}

const std::vector<std::vector<std::string>> &responses::book::getAsks() const {
    return asks;
}

long responses::book::getSequence() const {
    return sequence;
}
