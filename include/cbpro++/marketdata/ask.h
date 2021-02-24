//
// Created by Bradley Bottomlee on 2/11/21.
//

#ifndef CBPRO_ASK_H
#define CBPRO_ASK_H

#include <string>

namespace responses {
    class askLevel1_2 {
    public:
        askLevel1_2(std::string price, std::string size, std::string numOrders);

        [[nodiscard]] const std::string &getPrice() const;

        [[nodiscard]] const std::string &getSize() const;

        [[nodiscard]] const std::string &getNumOrders() const;

    private:
        std::string price;
        std::string size;
        std::string numOrders;

    };

    class askLevel3 {
    public:
        askLevel3(std::string price, std::string size, std::string orderId);

        [[nodiscard]] const std::string &getPrice() const;

        [[nodiscard]] const std::string &getSize() const;

        [[nodiscard]] const std::string &getOrderId() const;

    private:
        std::string price;
        std::string size;
        std::string orderId;
    };
} // namespace responses
#endif //CBPRO_ASK_H
