// Assessment 1 Challenge 7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <conio.h> //for _getch()

std::string PromptForAndOutputName(std::string player)
{
		std::cout << "Enter " << player << "'s name: ";
		std::cin >> player;
		std::cout << '\n';
	  
	return player;
}
int main()
{
	std::string player1 = "player1";
	std::string player2 = "player2";
	std::string player3 = "player3";
	bool HappyWithSelectionOfWeapons = false;
	do
	{	
		PromptForAndOutputName(player1);
		PromptForAndOutputName(player2);
		PromptForAndOutputName(player3);

		std::cout << "welcome " << player1 << ", " << player2 << ", and " << player3 << " to the shop!\n";
		std::cout << "You currently have 100 coins. You can buy the following items";
	} while (!HappyWithSelectionOfWeapons);
	
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
