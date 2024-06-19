/**
 * @file deal.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-06-18
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "deal.hpp"
#include <iostream>
#include <ctime>

std::string generate_code() {
    std::string character = "abcdefghiklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::string code;
    int length = 10;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = 0; i < length; ++i) {
        int randomIndex = std::rand() % character.length();
        code += character[randomIndex];
    }
    return code;
}

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

    void deal_display() const;

    void creat_deal();

};
deal::deal(user& sender, user& receiver, const std::string& item_name,
    const float& item_weight, const std::string& deal_code, deal_status status)
    :sender(sender), receiver(receiver), item_name(item_name),
    item_weight(item_weight), deal_code(deal_code), status(status) {
    sender.add_deal(*this);
    receiver.add_deal(*this);
}

void deal::deal_display() const {
    std::cout << "Deal Information:" << std::endl;
    std::cout << "Sender:" << std::endl;
    sender.user_display();
    std::cout << "Receiver:" << std::endl;
    receiver.user_display();
    std::cout << "Item Name: " << item_name << std::endl;
    std::cout << "Item Weight: " << item_weight << std::endl;
    std::cout << "Deal Code: " << deal_code << std::endl;
    std::cout << "Status: ";

    switch (status) {
    case at_sender:
        std::cout << "At Sender" << std::endl;
        break;
    case in_transiting:
        std::cout << "In Transiting" << std::endl;
        break;
    case at_warehouse:
        std::cout << "At Warehouse" << std::endl;
        break;
    case shipping:
        std::cout << "Shipping" << std::endl;
        break;
    case received:
        std::cout << "Received" << std::endl;
        break;
    default:
        std::cout << "Unknown" << std::endl;
        break;
    }
}

void deal::creat_deal(user& sender, user& receiver) {
    /**Item Information */
    float item_weight;
    std::string item_name;
    std::cout << "Enter Item Name: ";
    std::cin >> item_name;

    std::cout << "Enter Item Weight: ";
    std::cin >> item_weight;

    // Generate random deal code
    std::string deal_code = generate_code();

    // Create sender user object

    // Create receiver user object
    deal_status status = deal_status::at_sender;
    // Create deal object with users and item details
    const deal newDeal(sender, receiver, item_name, item_weight, deal_code, status);

    // Display deal information
    std::cout << "\nDeal created successfully!\n";
    newDeal.deal_display();
    sender.add_deal(newDeal);
    receiver.add_deal(newDeal);
}
