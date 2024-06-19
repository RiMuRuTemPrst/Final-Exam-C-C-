/**
 * @file deal.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-06-18
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef DEAL_HPP
#define DEAL_HPP


#include <string>
#include "user.hpp"

enum deal_status {
    at_sender,      /**Sender has not yet sent the item */
    in_transiting,  /**Is transiting to the warehouse */
    at_warehouse,   /**Arrived at warehouse */
    shipping,       /**is shipping to the receiver */
    received        /**receiver received the item */
};

class deal {
private:
    user sender;
    user receiver;
    std::string item_name;
    float item_weight;
    std::string deal_code;
    deal_status status;
public:

    /**constructor */
    deal(user& sender, user& receiver, const std::string& item_name,
        const float& item_weight, const std::string& deal_code, deal_status status);
    deal()
        : sender(), receiver(), item_name(""), item_weight(0.0f), deal_code(""), status(deal_status::at_sender) {
    }
    void deal_display() const;

    void creat_deal(user& sender, user& receiver);

};

#endif