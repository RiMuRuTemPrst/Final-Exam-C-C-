// #include "user.hpp"
// #include "deal.hpp"
#include <conio.h>
#include <iostream>
#include <string>
#include <map>

// std::map<std::string, deal> dealMap;

void user_choice(int &choice);

void find_deal_by_code();

int main()
{
    std::cout << "Welcome to the logistics management system." << std::endl;
    std::cout << "First, Please tell us your information" << std::endl;
    // user sender;
    // sender = sender.create_user();
    int choice = 0;
    while(1)
    {   
        choice = 0;
        user_choice(choice);
        switch (choice) 
        {
        case 1:
            {
                std::cout << "You chose to create a delivering deal." << std::endl;
                std::cout << "Please enter the information of the receiver" << std::endl;
                // user receiver;
                // receiver = receiver.create_user();
                // deal myDeal;
                // myDeal.creat_deal(sender, receiver);
                break;
            }
        
        case 2:
            {
                std::cout << "Check the deal" << std::endl;
                find_deal_by_code();
                break;
            }
        case 3:
            std::cout << "You chose to list current available deals." << std::endl;
            // sender.view_deal_details();
            break;
        case 4:
            std::cout << "You chose to view information about the app." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }

    std::cout << "Put ESC to exit." << std::endl;
    char ch = getch(); 
        if (ch == 27) 
        { 
            break; 
        }
    }
}


void user_choice (int &choice)
{
    std::cout << "Main Menu: (choice)" << std::endl;
    std::cout << "1. Create a delivering deal." << std::endl;
    std::cout << "2. Check the deal" << std::endl;
    std::cout << "3. List of current available deal." << std::endl;
    std::cout << "4. Infor of the app." << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
}

void find_deal_by_code()
{
    std::string code;
    std::cout << "Enter Deal Code: ";
    std::cin >> code;

    // auto it = dealMap.find(code); 

    // if (it != dealMap.end())
    // {
    //     deal foundDeal = it->second; 
    //     foundDeal.deal_display();
    // }
    // else
    // {
    //     std::cout << "Deal not found.\n";
    // }
}