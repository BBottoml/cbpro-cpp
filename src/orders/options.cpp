//
// Created by Bradley Bottomlee on 2/24/21.
//

#include <cbpro++/orders/options.h>

namespace orders {

    const std::string &options::getClientOid() const {
        return clientOid_;
    }

    void options::setClientOid(const std::string &clientOid) {
        options::clientOid_ = clientOid;
    }

    const std::string &options::getStp() const {
        return stp_;
    }

    void options::setStp(const std::string &stp) {
        options::stp_ = stp;
    }

    const std::string &options::getStop() const {
        return stop_;
    }

    void options::setStop(const std::string &stop) {
        options::stop_ = stop;
    }

    const std::string &options::getStopPrice() const {
        return stopPrice_;
    }

    void options::setStopPrice(const std::string &stopPrice) {
        options::stopPrice_ = stopPrice;
    }

    const std::string &options::getTimeInForce() const {
        return timeInForce_;
    }

    void options::setTimeInForce(const std::string &timeInForce) {
        options::timeInForce_ = timeInForce;
    }

    const std::string &options::getCancelAfter() const {
        return cancelAfter_;
    }

    void options::setCancelAfter(const std::string &cancelAfter) {
        options::cancelAfter_ = cancelAfter;
    }

    bool options::isPostOnly() const {
        return postOnly_;
    }

    void options::setPostOnly(bool postOnly) {
        options::postOnly_ = postOnly;
    }

    options::options() = default;
} // namsepace orders