#include <iostream>
#include <sstream>
#include <cctype>
#include <bitset>

// used to reject inappropriate input
bool isDecimal(const std::string& input) {
    for (char c : input) {
        if (!std::isdigit(c) && c != '.') {
            return false;
        }
    }
    return true;
}

std::string hexDigitToBinary(char hexDigit) {
    std::string binary;
    int hexValue;

    // conversion from hexadecimal digit to integer
    if (std::isdigit(hexDigit)) {
        hexValue = hexDigit - '0';
    } else {
        hexValue = std::toupper(hexDigit) - 'A' + 10;
    }

    // conversion from integer to binary string
    for (int i = 3; i >= 0; i--) {
        binary += ((hexValue >> i) & 1) ? '1' : '0';
    }

    return binary;
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

    // hexadecimal string
    std::stringstream ss_hex;
    ss_hex << std::hex << decimalValue;
    std::string hexadecimalValue = ss_hex.str();

    // print values
    std::cout << "Hexadecimal value: 0x" << hexadecimalValue << "\n";
    std::cout << "Octal value: " << std::showbase << std::oct << static_cast<int>(decimalValue) << "\n";
    std::cout << "Binary equivalent: ";
    for (char hexDigit : hexadecimalValue) {
        std::cout << hexDigitToBinary(hexDigit) << " ";
    }
    std::cout << "\n\n";
}