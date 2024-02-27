#include <iostream>
#include <sstream>
#include <cctype>

// used to reject inappropriate input
bool isDecimal(const std::string& input) {
    for (char c : input) {
        if (!std::isdigit(c) && c != '.') {
            return false;
        }
    }
    return true;
}

int main() {
    std::string input;

    // checking the input
    do {
        std::cout << "Enter a decimal number: ";
        std::cin >> input;
    } while (!isDecimal(input));

    // conversion to integer
    std::stringstream ss(input);
    int decimalValue;
    ss >> decimalValue;

    // print values with showbase
    std::cout << "Hexadecimal value: " << std::showbase << std::hex << static_cast<int>(decimalValue) << "\n";
    std::cout << "Octal value: " << std::oct << static_cast<int>(decimalValue) << "\n\n";
}