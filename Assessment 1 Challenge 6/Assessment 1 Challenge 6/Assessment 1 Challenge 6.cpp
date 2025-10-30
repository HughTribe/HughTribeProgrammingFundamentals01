// Assessment 1 Challenge 6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	/*int input = 0;
	while (input == NULL)
	{
		std::getline(std::cin, input);
		if (input == NULL)
		{
			std::cout << "input is invalid";
		}
	}
	
	
	
	std::cout << "You entered: " << input << "\n";*/

	int x = 0;
	std::string temp;
	do
	{
		std::getline(std::cin, temp);
		if (temp.empty())
		{
			std::cout << "input is invalid\n";
		}
	} while (temp.empty());
		x = std::stoi(temp);
	std::cout << "! " << x << std::endl;

	std::cin >> x;
	std::cout << x << std::endl;
	int input = 0;
	string IntToStr = "";
	while (IntToStr.empty())
	{
		std::cout << "Please enter an integer: ";
		cin >> input;
		IntToStr = to_string(input);
		if (IntToStr.empty())
		{
			cout << "input is invalid\n";
		}
	}

	cout << "You entered: " << input << "\n";

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
