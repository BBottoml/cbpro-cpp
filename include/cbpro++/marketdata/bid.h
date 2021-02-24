//
// Created by Bradley Bottomlee on 2/11/21.
//

#ifndef CBPRO_BID_H
#define CBPRO_BID_H

#include <string>

namespace responses {
    class bidLevel1_2 {
    public:
        bidLevel1_2(std::string price, std::string size, std::string numOrders);

        [[nodiscard]] const std::string &getPrice() const;

        [[nodiscard]] const std::string &getSize() const;

        [[nodiscard]] const std::string &getNumOrders() const;

    private:
        std::string price;
        std::string size;
        std::string numOrders;

    };

    class bidLevel3 {
    public:
        bidLevel3(std::string price, std::string size, std::string orderId);

        [[nodiscard]] const std::string &getPrice() const;

        [[nodiscard]] const std::string &getSize() const;

        [[nodiscard]] const std::string &getOrderId() const;

    private:
        std::string price;
        std::string size;
        std::string orderId;
    };
} // namespace responses

#endif //CBPRO_BID_H
