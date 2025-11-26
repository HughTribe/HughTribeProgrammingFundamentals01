// Assessment 1 Challenge 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cctype>


bool ContainsAlpha(const std::string& text) {
    
    for (char x : text)
    {
        if (std::isalpha(static_cast<unsigned char>(x)))
        {
            return true;
        }
    }
    return false;
}


std::string CapitaliseAll(const std::string& text) {
    
    std::string result = text;
    for (char& c : result)
    {
        c = std::toupper(static_cast<unsigned char>(c));
    }
    return result;
}


std::string UncapitaliseAll(const std::string& text) {

    std::string result = text;
    for (char& c : result)
    {
        c = std::tolower(static_cast<unsigned char>(c));
    }
    return result;
}


std::string SentenceCase(const std::string& text) {

    std::string result = text;
    for (int i = 0; i < result.length(); i++)
    {
        if (std::isalpha(static_cast<unsigned char>(result[i])))
        {
            result[i] = std::toupper(static_cast<unsigned char>(result[i]));
            break;
        }
    }
    for (int i = 1; i < result.length(); i++)
    {
        if (result[i - 1] == '.' || result[i - 1] == '!' || result[i - 1] == '?')
        {
          
            while (i < result.length() && std::isspace(static_cast<unsigned char>(result[i])))
            {
                i++;
            }
           
            if (i < result.length() && std::isalpha(static_cast<unsigned char>(result[i])))
            {
                result[i] = std::toupper(static_cast<unsigned char>(result[i]));
            }
        }
        else
        {
           
            result[i] = std::tolower(static_cast<unsigned char>(result[i]));
        }
    }
    return result;
}


std::string AlternateCasing(const std::string& text) {

    std::string result = text;
    int c = 0;
    for (int i = 0; i < result.length(); i++)
    {
        if (std::isalpha(static_cast<unsigned char>(result[i])) && (c % 2 == 0))
        {
            c++;
            result[i] = std::toupper(static_cast<unsigned char>(result[i]));
            continue;
        }

        else if (std::isalpha(static_cast<unsigned char>(result[i])) && (c % 2 != 0))
        {
            c++;
            result[i] = std::tolower(static_cast<unsigned char>(result[i]));
            continue;
        }
        continue;
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
		//might use a switch statement but seems a bit overkill for this
        if (input.empty())
        {
			std::cerr << "Error: Input cannot be empty. Please try again.\n";
            continue;
        }
        if (!ContainsAlpha(input))
        {
			std::cerr << "Error: Input must contain at least one alphabetic character. Please try again.\n";
            continue;
        }
    } while (input.empty() || !ContainsAlpha(input));

    std::cout << "Uppercase        => " << CapitaliseAll(input) << std::endl;
    std::cout << "Lowercase        => " << UncapitaliseAll(input) << std::endl;
	std::cout << "Sentence case    => " << SentenceCase(input) << std::endl;
    std::cout << "Alternate casing => " << AlternateCasing(input) << std::endl;
	return 0;

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
