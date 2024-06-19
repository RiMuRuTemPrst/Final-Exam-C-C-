/**
 * @file user.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-06-18
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "user.hpp"

#include <iostream> 

user::user(const std::string& name, const std::string phone_number, const address& address_user)
    :name(name), phone_number(phone_number), address_user(address_user), number_of_deal(0) {
}

user::~user() {

}
void user::user_display() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Phone number: " << phone_number << std::endl;
    std::cout << "Address: " << address_user.province << ", " << address_user.city << ", "
        << address_user.ward << ", " << address_user.street_name << ", " << address_user.address_number << std::endl;
    std::cout << "Number of Deals: " << number_of_deal << std::endl;
}

void user::set_user(const std::string& name_param, const std::string& phone_number_param, const address& address_user_param) {
    name = name_param;
    phone_number = phone_number_param;
    address_user = address_user_param;
}

void user::get_user(std::string& name_param, std::string& phone_number_param, address& address_user_param) {
    name_param = name;
    phone_number_param = phone_number;
    address_user_param = address_user;
}


void user::add_deal(deal* newDeal) {
    number_of_deal++;
    available_deal.push_back(newDeal);
}


void user::view_deal_details() {
    std::cout << "View Deal Details:" << std::endl;
    if (available_deal.empty()) {
        std::cout << "No deal available." << std::endl;
    }
    else {
        // for (auto deal_view : available_deal) {
        //     deal_view->deal_display();
        //     std::cout << "----------------------" << std::endl;
        // }
    }
}

user user::create_user() {
    std::cout << "Enter your name: ";
    std::string name;
    std::cin >> name;
    std::cout << "Enter your phone number: ";
    std::string phone_number;
    std::cin >> phone_number;
    std::cout << "Enter your address: ";
    address address_user;
    std::cout << "Enter City/Province: ";
    std::cin >> address_user.province;
    std::cout << "Enter district: ";
    std::cin >> address_user.city;
    std::cout << "Enter ward: ";
    std::cin >> address_user.ward;
    std::cout << "Enter street name: ";
    std::cin >> address_user.street_name;
    std::cout << "Enter address number: ";
    std::cin >> address_user.address_number;
    user username(name, phone_number, address_user);
    return username;
}