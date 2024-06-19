/**
 * @file user.hpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-06-18
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef USER_HPP
#define USER_HPP


#include <string>
#include <vector>
#include "deal.hpp"

 /**
  * @brief Generate a random code for deal code
  * @param: No param
  * @return std::string
  */
std::string generate_code();

/**
 * @brief Address of a person includes of province/city and city/district, ward, street name and address number
 * @member: Province (string)
 * @member: City (string)
 * @member: Ward (string)
 * @member: Street name (string)
 * @member: Address number (int)
 */
typedef struct {
    std::string province;
    std::string city;
    std::string ward;
    std::string street_name;
    int address_number;
}address;

/**
 * @brief Class user, includes of name, phone number, address,
 * number of deal and list of deal
 */
class user {
private:
    std::string name;
    std::string phone_number;
    address address_user;
    int number_of_deal;
    std::vector<deal> available_deal;
public:
    /**constructor user*/
    user(const std::string& name = "", const std::string phone_number = "",
        const address& address_user = {});
    /**destructor */
    ~user();
    /** Display on screen User information of Address and Deal */
    void user_display() const;
    user create_user();
    /** Set user informaion */
    void set_user(const std::string& name_param, const std::string& phone_number_param, const address& address_user_param);
    /**Get user information */
    void get_user(std::string& name_param, std::string& phone_number_param, address& address_user_param);
    /**Add deal to user after completely crating deal */
    void add_deal(const deal& newDeal);
    /** View each deal details */
    void view_deal_details();

};

#endif
