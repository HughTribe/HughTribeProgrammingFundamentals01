// Assessment 1 challenge 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	float Number = 0;

	do
	{
		std::cout << ">>Please enter a number:  ";
		
		
		std::cin >> Number;
		if (std::cin.fail() == true)
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "\nThats not a number :p\n";
			continue;
		}
		else
		{
			break;
		}

	} while (true);

	std::cout << "\n>> neg(x): " << -Number << std::endl;
	std::cout << ">> abs(x): " << abs(Number) << std::endl;
	std::cout << ">> pow2(x): " << Number * Number << std::endl;
	std::cout << ">> pow3(x): " << Number * Number * Number << std::endl;
	std::cout << ">> sqrt(x): ";
	if (Number < 0)
	{
		Number = -Number;
		std::cout << sqrt(Number) << std::endl;
		Number = -Number;
	}
	else
	{
		std::cout << sqrt(Number) << std::endl;
	}
	std::cout << ">> floor(x): " << floor(Number) << std::endl;	
	std::cout << ">> ceil(x): " << ceil(Number) << std::endl;
	std::cout << ">> round(x): " << round(Number) << std::endl;
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
