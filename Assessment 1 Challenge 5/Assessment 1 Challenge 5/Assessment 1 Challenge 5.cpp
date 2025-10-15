// Assessment 1 Challenge 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cctype>
std::string Text;
bool ValidInputCalculator(std::string Text) 
{
	for (char x : Text)
	{
		if (isalpha(x) == true)
		{
			return true;
		}
		
	}
	return false;
}
int main()
{ 
	do
	{
	std::cin.clear();
	std::cin.ignore(1000,  '\n');
	std::cout << "Enter some text\n";
	std::getline(std::cin, Text);

	} while ((Text.length() == 0) && (ValidInputCalculator(Text) == 0));
	std::cout << "ValidinputCalculator = " << ValidInputCalculator(Text);
	
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
