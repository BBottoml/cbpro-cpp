//
// Created by Bradley Bottomlee on 2/24/21.
//

#ifndef CBPRO_OPTIONS_H
#define CBPRO_OPTIONS_H

#include <string>

namespace orders {
    class options {

    public:
        options();

        [[nodiscard]] const std::string &getClientOid() const;

        void setClientOid(const std::string &clientOid);

        [[nodiscard]] const std::string &getStp() const;

        void setStp(const std::string &stp);

        [[nodiscard]] const std::string &getStop() const;

        void setStop(const std::string &stop);

        [[nodiscard]] const std::string &getStopPrice() const;

        void setStopPrice(const std::string &stopPrice);

        [[nodiscard]] const std::string &getTimeInForce() const;

        void setTimeInForce(const std::string &timeInForce);

        [[nodiscard]] const std::string &getCancelAfter() const;

        void setCancelAfter(const std::string &cancelAfter);

        [[nodiscard]] bool isPostOnly() const;

        void setPostOnly(bool postOnly);

    private:
        std::string clientOid_;
        std::string stp_;
        std::string stop_;
        std::string stopPrice_;
        std::string timeInForce_;
        std::string cancelAfter_;
        bool postOnly_ = false;

    };
} // namespace orders

#endif //CBPRO_OPTIONS_H
