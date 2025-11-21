// Assessment 1 Challenge 7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <conio.h> //for _getch()
#include <vector>
using namespace std;	

int partysCoins = 100;

class Weapon
{

	public:
	Weapon(const string& n, const string& iT, const int& p, const int& d, const string& r)	
	{
		name = n;
		itemType = iT;
		price = p;
		damage = d;
		role = r;
	}
	string name;
	string itemType;
	int price = 0;
	int damage = 0;
	string role;
};

Weapon greatSword("Great Sword", "Sword", 40, 100, "Knight");
Weapon scimitar("Scimitar", "Sword", 35, 75, "Knight");
Weapon dagger("Dagger", "Sword", 10, 35, "Knight");
Weapon longbow("Longbow", "Bow", 20, 55, "Archer");
Weapon crossbow("Crossbow", "Bow", 40, 100, "Archer");
Weapon rustySpear("Rusty Spear", "Spear", 10, 35, "Spearman");
Weapon ironSpear("Iron Spear", "Spear", 20, 65, "Spearman");
Weapon nullWeapon("No Weapon", "None", 0, 0, "None");

vector<Weapon> shopInventory = { greatSword, scimitar, dagger, longbow, crossbow, rustySpear, ironSpear };



 struct Player
 {
	Player(string n, Weapon w, int c) : name(n), weapon(w), choice(c) {}// Use member initializer list to initialize all members

	string name;
	Weapon weapon;
	int choice;
 };
	
Player player1 ("player1", nullWeapon, 0);
Player player2 ("player2", nullWeapon, 0);
Player player3 ("player3", nullWeapon, 0);


Player PromptForAndOutputName(Player& player)
{
		cout << "- Enter " << player.name << "'s name: ";
		getline(cin, player.name);
		cout << '\n';
	  
	return player;
}
int main()
{
	PromptForAndOutputName(player1);
	PromptForAndOutputName(player2);
	PromptForAndOutputName(player3);
	bool HappyWithSelectionOfWeapons = false;
	do
	{

		std::cout << ">> welcome " << player1.name << ", " << player2.name << ", and " << player3.name << " to the shop!\n";
		std::cout << "You currently have 100 coins. You can buy the following items\n";
		for (int i = 0; i < shopInventory.size(); i++)
		{
			std::cout << ">> " << i + 1 << ". " << shopInventory.at(i).name << " (" << shopInventory.at(i).price << " coins, " << shopInventory.at(i).damage << " Damage)\n";
		}
		
		do
		{

			cout << "Player 1, please enter a weapon to buy: ";

			cin >> player1.choice;
			if(cin.fail())
			{
				cin.clear(); // clear the fail state
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
				cerr << "Invalid input, please enter a number.\n";
				continue;
			}
			if (player1.choice < 1 || player1.choice > 8)
			{
				cerr << "Invalid choice, please choose a valid weapon number.\n";
				continue;
			}
			if(partysCoins - shopInventory.at(player1.choice - 1).price < 0)
			{
				cerr << "Not enough coins to buy that weapon, please choose a different weapon.\n";
				continue;
			}

			player1.weapon = shopInventory.at(player1.choice - 1);
			partysCoins -= player1.weapon.price;
			cout << player1.name << " bought a " << player1.weapon.name << " for " << player1.weapon.price << " coins. The party now has " << partysCoins << " coins left.\n";
			break;
			
		} while (true);
		
		do   
		{

			cout << "Player 2, please enter a weapon to buy: ";
			cin >> player2.choice;
			if(cin.fail())
			{
				cin.clear(); // clear the fail state
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
				cerr << "Invalid input, please enter a number.\n";
				continue;
			}
			if (player2.choice < 1 || player2.choice > 8)
			{
				cerr << "Invalid choice, please choose a valid weapon number.\n";
				continue;
			}
			if(partysCoins - shopInventory.at(player2.choice - 1).price < 0)
			{
				cerr << "Not enough coins to buy that weapon, please choose a different weapon.\n";
				continue;
			}
			if(player2.choice == player1.choice || player2.choice == player3.choice)
			{
				cerr << "That weapon has already been chosen, choose a different weapon.\n";
				continue;
			}
			
			player2.weapon = shopInventory.at(player2.choice - 1);
			partysCoins -= player2.weapon.price;
			cout << player2.name << " bought a " << player2.weapon.name << " for " << player2.weapon.price << " coins. The party now has " << partysCoins << " coins left.\n";
			break;

		} while (true);
		
		do
		{

			cout << "Player 3, please enter a weapon to buy: ";
			cin >> player3.choice;
			if(cin.fail())
			{
				cin.clear(); // clear the fail state
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
				cerr << "Invalid input, please enter a number.\n";
				continue;
			}
			if (player3.choice < 1 || player3.choice > 8)
			{
				cerr << "Invalid choice, please choose a valid weapon number.\n";
				continue;
			}
			if(partysCoins - shopInventory.at(player3.choice - 1).price < 0)
			{
				cerr << "Not enough coins to buy that weapon, please choose a different weapon.\n";
				continue;
			}
			if(player3.choice == player1.choice || player3.choice == player2.choice)
			{
				cerr << "That weapon has already been chosen by please choose a different weapon.\n";
				continue;
			}
			
			player3.weapon = shopInventory.at(player3.choice - 1);
			partysCoins -= player3.weapon.price;
			cout << player3.name << " bought a " << player3.weapon.name << " for " << player3.weapon.price << " coins. The party now has " << partysCoins << " coins left.\n";
			break;

		} while (true);

		do
		{
			string userInput = "";
			cout << "Are you happy with your selection of weapons? (yes/no): ";
			cin >> userInput;
			
			if(userInput == "no")
			{
				HappyWithSelectionOfWeapons = false;
				partysCoins = 100;
				player1.weapon = nullWeapon;
				player2.weapon = nullWeapon;
				player3.weapon = nullWeapon;
				cout << "\n---------------------------------\n\n";
				break;
			}
			if(userInput == "yes")
			{
				HappyWithSelectionOfWeapons = true;
				break;
			}
			else
			{
				cerr << "\nPlease input <yes> or <no>\n";
				continue;
			}
		} while (true);

	} while (!HappyWithSelectionOfWeapons);

	cout << "\n\n The party:" << endl;
	cout << ">> - Player 1 (" << player1.name << "), Role: " << player1.weapon.role << ", Weapon: " << player1.weapon.name << ", Damage: " << player1.weapon.damage << endl;
	cout << ">> - Player 2 (" << player2.name << "), Role: " << player2.weapon.role << ", Weapon: " << player2.weapon.name << ", Damage: " << player2.weapon.damage << endl;
	cout << ">> - Player 3 (" << player3.name << "), Role: " << player3.weapon.role << ", Weapon: " << player3.weapon.name << ", Damage: " << player3.weapon.damage << endl;
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
