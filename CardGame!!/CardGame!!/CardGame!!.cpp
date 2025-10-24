// CardGame!!.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

struct player {
    int health;
	int mana;
    int strength;
	int agility;
    int armour;
};
player enemy{ 100, 5, 0, 10, 0};

bool IsDead(player p)
{
    if (p.health <= 0)
    {
        return true;
    }
    else
    {
		return false;
    }
}




int main()
{
	std::string input;
    std::cout <<  R"( 
 _    _      _                            _         ______          _           
| |  | |    | |                          | |        | ___ \        | |          
| |  | | ___| | ___ ___  _ __ ___   ___  | |_ ___   | |_/ /__ _  __| | ___  ___ 
| |/\| |/ _ \ |/ __/ _ \| '_ ` _ \ / _ \ | __/ _ \  |    // _` |/ _` |/ _ \/ __|
\  /\  /  __/ | (_| (_) | | | | | |  __/ | || (_) | | |\ \ (_| | (_| |  __/\__ \
 \/  \/ \___|_|\___\___/|_| |_| |_|\___|  \__\___/  \_| \_\__,_|\__,_|\___||___/
                                                                                
        )" << '\n';
    do
    {
        std::cout << "Your turn :) what will you do?\n";
		std::getline(std::cin,input);
        if (input == "attack")
        {
            std::cout << "which attack? :)\n";
            std::getline(std::cin, input);
            if (input == "headbutt")
            {
                enemy.health -= 10;
                std::cout << "You headbutted the enemy for 10 damage! Enemy health is now " << enemy.health << "\n";
            }    

        }

    } while (true);


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
