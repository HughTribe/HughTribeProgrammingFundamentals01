


#include <iostream>
#include <conio.h> // For _getch()
#include <vector>
#include <algorithm>

using namespace std;

#define GREEN  "\033[32m"
#define RED  "\033[31m"
#define MAGENTA  "\033[35m"
#define BOLD  "\033[1m"
#define UNDERLINE  "\033[4m"
#define FLASHING  "\033[5m"
#define RESET  "\033[0m"

enum GameState
{
    PlayerDead,
    EnemyDead,
    PlayerAlive,
    EnemyAlive
};
int Turn = 1;
int Round = 1;
int ManaIndex = 1;
int PositionOfSelectedCard;
class player
{ public:

    string name;
    int health;
    int mana;
    int strength;
    int agility;
	int armour;

    player(string n, int h, int m, int s, int a, int ar) : name(n), health(h), mana(m), strength(s), agility(a), armour(ar) {}
     int pTakeDamage(int damage)
     {
         
        health -= damage;
        return health;
       
	 };
};

player Player("Player", 100, 5, 0, 0, 0);

class enemy
{
  public:
    
      string name;
      int health;
      enemy(string n, int h) : name(n), health(h) {}

     int eTakeDamage(int damage)
     {
         
        health -= damage;
		return health;
       
    };
  
};

enemy Goblin("Goblin", 30);

GameState IsDead(player& Player, enemy& Goblin, int& Round, int& Turn)
{
    if (Player.health <= 0)
    {
        system("cls");
        cout << "\n\n\n\n\t\t\tYOU DIED\n\t\t\t\t";
        cout << R"(
                       uuuuuuuuuuuuuuuuuuuuu.
                   .u$$$$$$$$$$$$$$$$$$$$$$$$$$W.
                 u$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$Wu.
               $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$i
              $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
         `    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
           .i$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$i
           $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$W
          .$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$W
         .$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$i
         #$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$.
         W$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
$u       #$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$~
$#      `"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
$i        $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
$$        #$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
$$         $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
#$.        $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$#
 $$      $iW$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$!
 $$i      $$$$$$$#"" `"""#$$$$$$$$$$$$$$$$$#""""""#$$$$$$$$$$$$$$$W
 #$$W    `$$$#"            "       !$$$$$`           `"#$$$$$$$$$$#
  $$$     ``                 ! !iuW$$$$$                 #$$$$$$$#
  #$$    $u                  $   $$$$$$$                  $$$$$$$~
   "#    #$$i.               #   $$$$$$$.                 `$$$$$$
          $$$$$i.                """#$$$$i.               .$$$$#
          $$$$$$$$!         .   `    $$$$$$$$$i           $$$$$
          `$$$$$  $iWW   .uW`        #$$$$$$$$$W.       .$$$$$$#
            "#$$$$$$$$$$$$#`          $$$$$$$$$$$iWiuuuW$$$$$$$$W
               !#""    ""             `$$$$$$$##$$$$$$$$$$$$$$$$
          i$$$$    .                   !$$$$$$ .$$$$$$$$$$$$$$$#
         $$$$$$$$$$`                    $$$$$$$$$Wi$$$$$$#"#$$`
         #$$$$$$$$$W.                   $$$$$$$$$$$#   ``
          `$$$$##$$$$!       i$u.  $. .i$$$$$$$$$#""
             "     `#W       $$$$$$$$$$$$$$$$$$$`      u$#
                            W$$$$$$$$$$$$$$$$$$      $$$$W
                            $$`!$$$##$$$$``$$$$      $$$$!
                           i$" $$$$  $$#"`  """     W$$$$
                                                   W$$$$!
                      uW$$  uu  uu.  $$$  $$$Wu#   $$$$$$
                     ~$$$$iu$$iu$$$uW$$! $$$$$$i .W$$$$$$
             ..  !   "#$$$$$$$$$$##$$$$$$$$$$$$$$$$$$$$#"
             $$W  $     "#$$$$$$$iW$$$$$$$$$$$$$$$$$$$$$W
             $#`   `       ""#$$$$$$$$$$$$$$$$$$$$$$$$$$$
                              !$$$$$$$$$$$$$$$$$$$$$#`
                              $$$$$$$$$$$$$$$$$$$$$$!
                            $$$$$$$$$$$$$$$$$$$$$$$`
                             $$$$$$$$$$$$$$$$$$$$")";
		Turn = 1;
		Round = 1;
		Player.health = 100;
		Goblin.health = 30;
		Player.mana = 5;
		ManaIndex = 1;
        
        return PlayerDead;
    }
    if (Goblin.health <= 0)
    {
        system("cls");
        cout << "YOU OBLITERATED THE ENEMY" << endl;
        Goblin.health = 30;
		Turn = 1;
        Round++;
        Player.mana = 5;
        ManaIndex = 1;
		
        return EnemyDead;
    }
    return PlayerAlive;
    
}
class Card 
{
  public:
    Card(string n, int m, int d) 
    {

        Name = n;
        ManaCost = m;
        Damage = d;
    }
    string Name;
    int ManaCost;
    int Damage;  
    friend bool operator== (const Card& lhs, const Card& rhs) 
    {
        return lhs.Name == rhs.Name
            && lhs.ManaCost == rhs.ManaCost
            && lhs.Damage == rhs.Damage;
    }
};
Card Curse ("Curse", 3, 9);
Card Blaze ("Blaze", 2, 5);
Card Shock ("Shock", 4, 11);
Card Cough ("Cough", 1, 1);

Card Slice ("Slice", 2, 4);
Card RKO ("RKO", 5, 12);
Card Riposte ("Riposte", 2, 5);
Card Brutalise("Brutalise", 4, 11);
Card Stumble ("Stumble", 1, 1);

Card Chomp ("Chomp", 1, 20);
Card Smash ("Smash", 3, 59);
Card Twerk ("Twerk", 2, 32);
Card M16 ("M16", 4, 68);
Card Groom ("Groom", 6, 100);


class Hand
{
 public:
    Hand(string Character)
    {
        if (Character == "Wizard")
        {
            vHand.push_back(Curse);
            vHand.push_back(Blaze);
            vHand.push_back(Blaze);
            vHand.push_back(Shock);
            vHand.push_back(Cough);
        }
        if (Character == "Rogue")
        {
            vHand.push_back(Slice);
            vHand.push_back(RKO);
            vHand.push_back(Riposte);
            vHand.push_back(Brutalise);
            vHand.push_back(Stumble);
        }
        if (Character == "Jack LLoyd")
        {
            vHand.push_back(Chomp);
            vHand.push_back(Smash);
            vHand.push_back(Twerk);
            vHand.push_back(M16);
            vHand.push_back(Groom);
        }
    }
    bool IsCardSelected(vector<Card> SelectedCards, vector<Card> Hand, int i)
    {    

        for (int j = 0; j < SelectedCards.size(); j++ ) 
        {
            if (SelectedCards.at(j) == vHand.at(i))
            {
				PositionOfSelectedCard = j;
				return true;
            }
            
        }

		return false;
        
        
        /*auto target = vHand.at(i);
        auto it = std::find(SelectedCards.begin(), SelectedCards.end(), target);
        if (it != SelectedCards.end())
        {

            return true;
        }
        else
        {
            return false;
		}*/
    }
    vector<Card> vHand;
    void PrintHand(vector<Card> vHand)
    {

        int cHover = 0;
        vector<Card> SelectedCards;

        while (true)
        {

            if (Turn % 2 == 0)//enemy turn
            {

                system("cls");
                cout << "Enemy's Turn! Press any key to continue..." << endl;
                _getch();
                system("cls");
                int enemyDamage = rand() % 10 + 5; // Random damage between 5 and 15
                cout << "The " << Goblin.name << " attacks you for " << enemyDamage << " damage!" << endl;
                Player.pTakeDamage(enemyDamage);
                cout << "You have " << Player.health << " health remaining!" << endl;
                Turn++;
                IsDead(Player, Goblin, Round, Turn);
                 _getch();
                 continue;
                

            }
            else //player turn
            {
                system("cls");
                cout << endl << '\t';
                for (int i = 0; i < vHand.size(); i++)
                {
                    if (i == cHover)
                    {
                        cout << GREEN << BOLD << "___________   " << RESET;
                        continue;
                    }
                    else
                    {
                        cout << "___________   ";
                    }

                }
                cout << endl << '\t';
                for (int i = 0; i < vHand.size(); i++)
                {
                    if (i == cHover)
                    {
                        cout << GREEN << BOLD << "|   (" << vHand.at(i).ManaCost << ")   |   " << RESET;
                        continue;
                    }

                    else
                    {
                        cout << "|   (" << vHand.at(i).ManaCost << ")   |   ";
                    }
                }
                    cout << endl << '\t';
                    for (int i = 0; i < vHand.size(); i++)
                    {
                        if (i == cHover)
                        {
                            cout <<  GREEN << BOLD << '|' << RESET;
                        }
                        else
                        {    
                            cout << '|';
                        }

                        int spaces = (9 - vHand.at(i).Name.length()) / 2;

                        for (int j = 0; j < spaces; j++)
                        {
                            cout << " ";

                        }


                        
                        
                            
                            if (IsCardSelected(SelectedCards, vHand, i))
                            {

                                cout << UNDERLINE << RED << BOLD << FLASHING << vHand.at(i).Name << RESET;
                                
                            }
                        
                            else if (i == cHover)
                            {
                                cout << UNDERLINE << GREEN << BOLD << vHand.at(i).Name << RESET;
                            }

                            else
                            {
                                cout << vHand.at(i).Name;
                            }
                        

                        for (int j = 0; j < spaces; j++)
                        {
                            cout << " ";
                        }
                        if (i == cHover)
                        {
                            cout << GREEN << BOLD << "|   " << RESET;
                        }
                        else
                        {
                            cout << "|   ";
                        }
                    }

                    for (int i = 0; i < 3; i++)
                    {
                        cout << "\n\t";
                        for (int j = 0; j < vHand.size(); j++)
                        {
                            if (j == cHover)
                            {
                                cout << GREEN << BOLD "|         |   " << RESET;
                            }
                            else
                            {   
                                cout << "|         |   ";
							}
                           
                        }
                    }

                    cout << "\n\t";
                    for (int i = 0; i < vHand.size(); i++)
                    {
                        if (i == cHover)
                        {
                            cout << GREEN << BOLD << "|_________|   " << RESET;
                        }
                        else
                        {
                            cout << "|_________|   ";
                        }
                    }
                    
                    cout << "\n\n\t\t\t\t\t(" << Player.mana << ")\n";
                    char key = _getch(); // Get user input without pressing Enter
                    if (key == 75) { // Left arrow key
                        cHover = (cHover - 1 + vHand.size()) % vHand.size();
                    }
                    else if (key == 77) { // Right arrow key
                        cHover = (cHover + 1) % vHand.size();
                    }
                    else if (key == 32)
                    {
                        if (IsCardSelected(SelectedCards, vHand, cHover))
                        {
                            SelectedCards.erase(SelectedCards.begin() + PositionOfSelectedCard);
                            Player.mana += vHand.at(cHover).ManaCost;
                            continue;
                        }
                        else
                        {
                            if (Player.mana < vHand.at(cHover).ManaCost)
                            {
                                system("cls");
                                cout << "Not enough mana to play " << vHand.at(cHover).Name << "!" << endl;
                                _getch();
                                continue;
                            }
                            SelectedCards.push_back(vHand.at(cHover));
                            Player.mana -= vHand.at(cHover).ManaCost;
                            continue;
                        }
                        
                        

                    } // Space key

                    else if (key == '\r') { // Enter key
                        string ListofSelectedCards = ""; //names of selected cards
                        int cSelectedDamage = 0; //total damage of selected cards
                        int LastIndex = SelectedCards.size() - 1;
                        for (int i = 0; i < SelectedCards.size(); i++)
                        {
                            if (i == LastIndex - 1)
                            {
                                ListofSelectedCards += SelectedCards.at(i).Name + " and ";
                                
                            }
                            else if (i == LastIndex)
                            {
                                ListofSelectedCards += SelectedCards.at(i).Name;
                                
                            }
                            else
                            {
                                ListofSelectedCards += SelectedCards.at(i).Name + ", ";
                            }

                            cSelectedDamage += SelectedCards.at(i).Damage;
                            continue;
                        }

                        system("cls");
                        cout << "You played " << ListofSelectedCards << " dealing " << cSelectedDamage << " damage!" << endl;
                        cout << Goblin.name << " has " << Goblin.eTakeDamage(cSelectedDamage) << " health remaining!" << endl;
                        Player.mana += ManaIndex;
                        ManaIndex++;
                        Turn++;
                        SelectedCards.clear();
                        _getch();
                        IsDead(Player, Goblin, Round, Turn);
                            continue;
                        
                    }
                
            }
        }
    }
};



    void displayMenu(const string options[], int size, int selected, string extra)
    {
        system("cls"); // Clear the console screen
        cout << extra << '\n';
        for (int i = 0; i < size; i++)
        {
            if (i == selected) {
                cout << " > " << options[i] << " < " << endl; // Highlight selected option
            }
            else {
                cout << "   " << options[i] << endl;
            }
        }
    }

    void characterSelection()
    {
        const int optionCount = 4;
        string options[optionCount] = { "Rogue", "Wizard", "Jack LLoyd", "Exit" };
        int selected = 0;
        /* bool ChosenClass = true;*/
        while (true)
        {
            displayMenu(options, optionCount, selected, "");

            char key = _getch(); // Get user input without pressing Enter
            if (key == 72)
            { // Up arrow key
                selected = (selected - 1 + optionCount) % optionCount;
            }
            else if (key == 80)
            { // Down arrow key
                selected = (selected + 1) % optionCount;
            }
            else if (key == '\r') { // Enter key
                if (options[selected] == "Exit")
                {
                    break;
                }
                system("cls");
                Hand H(options[selected]);
                H.PrintHand(H.vHand);

                //game loop - move?
                while (true)
                {

                }


                /*if (options[selected] == "Exit") break;
                system("pause");*/
            }
        }




    }


    int main()
    {

        const int optionCount = 4;
        string options[optionCount] = { "Start Game", "Option 2", "Option 3", "Exit" };
        int selected = 0;

        string extra = R"( 
 _    _      _                            _         ______          _           
| |  | |    | |                          | |        | ___ \        | |          
| |  | | ___| | ___ ___  _ __ ___   ___  | |_ ___   | |_/ /__ _  __| | ___  ___ 
| |/\| |/ _ \ |/ __/ _ \| '_ ` _ \ / _ \ | __/ _ \  |    // _` |/ _` |/ _ \/ __|
\  /\  /  __/ | (_| (_) | | | | | |  __/ | || (_) | | |\ \ (_| | (_| |  __/\__ \
 \/  \/ \___|_|\___\___/|_| |_| |_|\___|  \__\___/  \_| \_\__,_|\__,_|\___||___/
                                                                                
       )";

        while (true) {
            displayMenu(options, optionCount, selected, extra);

            char key = _getch(); // Get user input without pressing Enter
            if (key == 72) { // Up arrow key
                selected = (selected - 1 + optionCount) % optionCount;
            }
            else if (key == 80) { // Down arrow key
                selected = (selected + 1) % optionCount;
            }
            else if (key == '\r') { // Enter key
                system("cls");
                if (options[selected] == "Start Game") {
                    //sselect character
                    characterSelection();
                }
                else if (options[selected] == "Exit") {
                    break;
                }

                /*cout << "You selected: " << options[selected] << endl;*/
                /*if (options[selected] == "Exit") break;
                system("pause");*/
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
