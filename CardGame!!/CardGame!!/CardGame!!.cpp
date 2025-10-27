// CardGame!!.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
//#include <string>
//
//int turn = 1;
//
//struct player {
//	std::string name;
//    int health;
//	int mana;
//    int strength;
//	int agility;
//    int armour;
//};
//player enemy{ "enemy", 100, 5, 0, 10, 0 };
//player user{ "user", 100, 5, 0, 10, 0 };
//bool IsDead(player p)
//{
//    if (p.health <= 0)
//    {
//        return true;
//    }
//    else
//    {
//		return false;
//    }
//}
//void Burn(player p)
//{
//    p.health -= 5;
//    std::cout << p.name <<"'s burn deals 5 damage! Health is now " << p.health << "\n";
//    
//}
//
//
//
//
//int main()
//{
//	std::string input;
//    std::cout <<  R"( 
// _    _      _                            _         ______          _           
//| |  | |    | |                          | |        | ___ \        | |          
//| |  | | ___| | ___ ___  _ __ ___   ___  | |_ ___   | |_/ /__ _  __| | ___  ___ 
//| |/\| |/ _ \ |/ __/ _ \| '_ ` _ \ / _ \ | __/ _ \  |    // _` |/ _` |/ _ \/ __|
//\  /\  /  __/ | (_| (_) | | | | | |  __/ | || (_) | | |\ \ (_| | (_| |  __/\__ \
// \/  \/ \___|_|\___\___/|_| |_| |_|\___|  \__\___/  \_| \_\__,_|\__,_|\___||___/
//                                                                                
//        )" << '\n';
//    do
//    {
//        std::cout << "Your turn :) what will you do?\n";
//		std::getline(std::cin,input);
//        if (input == "attack")
//        {
//            std::cout << "which attack? :)\n";
//            std::getline(std::cin, input);
//            if (input == "headbutt" && user.mana >= 1)
//            {
//                enemy.health -= 10;
//                user.mana -= 1;
//                std::cout << "You headbutted the enemy for 10 damage! Enemy health is now " << enemy.health << "\n";
//				turn++;
//            }    
//            if (input == "blaze" && user.mana >= 2)
//            {
//				enemy.health -= 8;
//                user.mana -= 2;
//				std::cout << "You used blaze on the enemy for 8 damage! Enemy health is now " << enemy.health << "\n";
//				turn++;
//                for (turn; turn > 3;)
//                {
//                    Burn(enemy);
//                }
//                
//            }
//
//        }
//
//    } while (!IsDead(enemy));
//
//
//}

#include <iostream>
#include <conio.h> // For _getch()

using namespace std;

void displayMenu(const string options[], int size, int selected) {
    system("cls"); // Clear the console screen
    for (int i = 0; i < size; i++) {
        if (i == selected) {
            cout << " > " << options[i] << " < " << endl; // Highlight selected option
        }
        else {
            cout << "   " << options[i] << endl;
        }
    }
}

int main() {
    const int optionCount = 4;
    string options[optionCount] = { "Option 1", "Option 2", "Option 3", "Exit" };
    int selected = 0;

    while (true) {
        displayMenu(options, optionCount, selected);

        char key = _getch(); // Get user input without pressing Enter
        if (key == 72) { // Up arrow key
            selected = (selected - 1 + optionCount) % optionCount;
        }
        else if (key == 80) { // Down arrow key
            selected = (selected + 1) % optionCount;
        }
        else if (key == '\r') { // Enter key
            system("cls");
            cout << "You selected: " << options[selected] << endl;
            if (options[selected] == "Exit") break;
            system("pause");
        }
    }

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
