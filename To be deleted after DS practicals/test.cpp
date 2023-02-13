#include <iostream>
#include <iomanip>
#include <string>

class Card
{
private:
    std::string sender;
    std::string recipient;
    std::string message;

public:
    Card(std::string sender, std::string recipient, std::string message) : sender(sender), recipient(recipient), message(message) {}

    void printCard()
    {
        std::cout << std::setfill('*') << std::setw(50) << "" << std::endl;
        std::cout << std::setfill(' ') << std::setw(20) << " "
                  << "Creative Card" << std::endl;
        std::cout << std::setfill('*') << std::setw(50) << "" << std::endl;
        std::cout << std::endl;
        std::cout << std::setw(10) << " "
                  << "From: " << sender << std::endl;
        std::cout << std::setw(10) << " "
                  << "To: " << recipient << std::endl;
        std::cout << std::endl;
        std::cout << std::setw(10) << " " << message << std::endl;
        std::cout << std::endl;
        std::cout << std::setfill('*') << std::setw(50) << "" << std::endl;
    }
};

int main()
{
    std::string sender;
    std::string recipient;
    std::string message;

    std::cout << "Enter sender name: ";
    std::getline(std::cin, sender);

    std::cout << "Enter recipient name: ";
    std::getline(std::cin, recipient);

    std::cout << "Enter message: ";
    std::getline(std::cin, message);

    Card card(sender, recipient, message);
    card.printCard();

    return 0;
}
