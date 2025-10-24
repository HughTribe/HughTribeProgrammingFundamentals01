// CardGame!!.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct player {
    int health;
	int mana;
    int strength;
	int agility;
    int armour;
};







int main()
{
    std::cout <<  R"( 
 _    _      _                            _         ______          _           
| |  | |    | |                          | |        | ___ \        | |          
| |  | | ___| | ___ ___  _ __ ___   ___  | |_ ___   | |_/ /__ _  __| | ___  ___ 
| |/\| |/ _ \ |/ __/ _ \| '_ ` _ \ / _ \ | __/ _ \  |    // _` |/ _` |/ _ \/ __|
\  /\  /  __/ | (_| (_) | | | | | |  __/ | || (_) | | |\ \ (_| | (_| |  __/\__ \
 \/  \/ \___|_|\___\___/|_| |_| |_|\___|  \__\___/  \_| \_\__,_|\__,_|\___||___/
                                                                                
                                                                                

              



        )" << '\n';
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
