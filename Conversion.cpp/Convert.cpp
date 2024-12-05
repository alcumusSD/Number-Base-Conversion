#include <iostream>
#include <string>
#include<math.h>
#include<cstring>

std::string decimalToBinary(int decimal)
{
    if (decimal == 0) {
        return "0";  
    }
    
    int digit = 0;
    std::string str;

   
    while (decimal > 0)
    {
        digit = decimal % 2;
        decimal = decimal / 2;
        str += std::to_string(digit); 
    }

    
    std::string rev;
    for (int i = static_cast<int>(str.length()) - 1; i >= 0; i--)
    {
        rev += str[i];
    }

    return rev; 
}

std::string decimalToHexadecimal(int decimal)
{
    std::string hexResult = "";

    char hexDigits[] = "0123456789ABCDEF";

    while (decimal > 0)
    {
       int remainder = decimal % 16;
        hexResult = hexDigits[remainder] + hexResult;
        decimal /= 16;
    }
    
    if (hexResult.empty()) {
        return "0";
    }
    else {
        return hexResult;
    }

    //return hexResult.empty() ? "0" : hexResult;
}

int hexadecimalToDecimal(std::string hex) {
    int sum = 0;
    int j = 0;

    for (int i = static_cast<int>(hex.length()) - 1; i >= 0; i--) {
        switch (hex[i]) {
        case '0':
            sum += 0 * static_cast<int>(pow(16, j));
            break;
        case '1':
            sum += 1 * static_cast<int>(pow(16, j));
            break;
        case '2':
            sum += 2 * static_cast<int>(pow(16, j));
            break;
        case '3':
            sum += 3 * static_cast<int>(pow(16, j));
            break;
        case '4':
            sum += 4 * static_cast<int>(pow(16, j));
            break;
        case '5':
            sum += 5 * static_cast<int>(pow(16, j));
            break;
        case '6':
            sum += 6 * static_cast<int>(pow(16, j));
            break;
        case '7':
            sum += 7 * static_cast<int>(pow(16, j));
            break;
        case '8':
            sum += 8 * static_cast<int>(pow(16, j));
            break;
        case '9':
            sum += 9 * static_cast<int>(pow(16, j));
            break;
        case 'A':
        case 'a':
            sum += 10 * static_cast<int>(pow(16, j));
            break;
        case 'B':
        case 'b':
            sum += 11 * static_cast<int>(pow(16, j));
            break;
        case 'C':
        case 'c':
            sum += 12 * static_cast<int>(pow(16, j));
            break;
        case 'D':
        case 'd':
            sum += 13 * static_cast<int>(pow(16, j));
            break;
        case 'E':
        case 'e':
            sum += 14 * static_cast<int>(pow(16, j));
            break;
        case 'F':
        case 'f':
            sum += 15 * static_cast<int>(pow(16, j));
            break;
        default:
            std::cout << "Invalid hex digit: " << hex[i] ;
            return -1; // Invalid input
        }
        j++;
    }

    return sum;
}

std::string hexadecimalToBinary(std::string hex) {
    int x = hexadecimalToDecimal(hex);
    std::string str = decimalToBinary(x);
    return str;
}

void Convert()
{
    int pick;
    int choice;
    int input;
    std::string input1;
    

    std::cout << "Please specify the number system of the input number. " << "\n"
        << "1) Base 10 (Decimal) " << "\n"
        << "2) Base 16 (Hexadecimal)" << "\n";
    std::cin >> pick;



    if (pick == 1)
    {
        std::cout << "Please enter the number: ";
        std::cin >> input;
        /* ----- Decimal into HexaDecimal ------*/
        std::string hexValue = decimalToHexadecimal(input);
        std::cout << "The hexadecimal representation is " << hexValue << "\n";

        /* ----- Decimal into Binary ------*/
        std::string binaryValue = decimalToBinary(input);
        std::cout << "The binary representation is  " << binaryValue << "\n";

    }
    else if (pick == 2)
    { 
        std::cout << "Please enter the number: ";
        std::cin >> input1;
        /* ----- HexaDecimal into Decimal ------*/
        int value = hexadecimalToDecimal(input1);
        std::cout << "The decimal representation is " << value << "\n";

        /* ----- HexaDecimal into Binary ------*/
        std::string binaryValue = hexadecimalToBinary(input1);
        std::cout << "The binary representation is   " << binaryValue << "\n";        
    }

    std::cout << "Press 3) if you would like to continue and 4) if you would like to quit. " << "\n"
        << "3) Continue " << "\n"
        << "4) Quit" << "\n";
    std::cin >> choice;
    if (choice == 3)
    {
        Convert();
    }
    else if (choice == 4)
    {
        exit(0);
    }
}