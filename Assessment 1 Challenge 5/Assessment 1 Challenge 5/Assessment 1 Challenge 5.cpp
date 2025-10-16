// Assessment 1 Challenge 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cctype>

// Checks if the input contains at least one alphabetic character
bool ContainsAlpha(const std::string& text) 
{
    for (char x : text)
    {
        if (std::isalpha(static_cast<unsigned char>(x)))
        {
            return true;
        }
    }
    return false;
}

// Returns a new string with all characters capitalized
std::string CapitalizeAll(const std::string& text)
{
    std::string result = text;
    for (char& c : result)
    {
        c = std::toupper(static_cast<unsigned char>(c));
    }
    return result;
}

int main()
{
    std::string input;
    do
    {
        std::cout << "Enter some text: ";
        std::getline(std::cin, input);
        std::cout << "ContainsAlpha = " << ContainsAlpha(input) << '\n'; // debug
    } while (input.empty() || ContainsAlpha(input) == false);

    std::cout << "Uppercase        => " << CapitalizeAll(input) << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
