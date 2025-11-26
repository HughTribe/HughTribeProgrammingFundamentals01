


#include <iostream>
#include <conio.h> // For _getch()
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

#define GREEN  "\033[32m"
#define RED  "\033[31m"
#define MAGENTA  "\033[35m"
#define BOLD  "\033[1m"
#define UNDERLINE  "\033[4m"
#define FLASHING  "\033[5m"
#define RESET  "\033[0m"

// Initialize random number generator
std::random_device rd; // Obtain a random seed
std::mt19937 gen(rd()); // Seed the generator

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
      int damage;

      enemy(string n, int h, int d) : name(n), health(h), damage(d) {}

     int eTakeDamage(int damage)
     {
         
        health -= damage;
		return health;
       
    };
  
};

enemy Goblin("Goblin", 30, 10);
enemy Orc("Orc", 50, 15);
enemy JohnStoke("John Stoke", 80, 25);



GameState IsDead(player& Player, enemy& Goblin, int& Round, int& Turn)
{
    if (Player.health <= 0)
    {
        system("cls");
        cout << "\n\n\n\n\t\t\tYOU DIED Press anything to restart\n\t\t\t\t";
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
    Card(string n, int m, int d, int h) 
    {

        Name = n;
        ManaCost = m;
        Damage = d;
        Heal = h;
    }
    string Name;
    int ManaCost;
    int Damage;  
	int Heal;
    friend bool operator== (const Card& lhs, const Card& rhs) 
    {
        return lhs.Name == rhs.Name
            && lhs.ManaCost == rhs.ManaCost
            && lhs.Damage == rhs.Damage;
    }
};
Card Curse1 ("Curse", 3, 9, 0);
Card Curse2 ("Curse", 3, 9, 0);
Card Curse3 ("Curse", 3, 9, 0);
Card Blaze1 ("Blaze", 2, 5, 0);
Card Blaze2 ("Blaze", 2, 5, 0);
Card Blaze3 ("Blaze", 2, 5, 0);
Card Shock1 ("Shock", 4, 11, 0);
Card Shock2 ("Shock", 4, 11, 0);
Card Shock3 ("Shock", 4, 11, 0);
Card Cough1 ("Cough", 1, 1, 0);
Card Cough2("Cough", 1, 1, 0);
Card Cough3("Cough", 1, 1, 0);
Card Cough4("Cough", 1, 1, 0);
Card LightSpam1 ("LightSpam", 1, 11, 0);
Card LightSpam2("LightSpam", 1, 11, 0);
Card Restore1("Restore", 2, 0, 10);
Card Restore2("Restore", 2, 0, 10);

Card Slice ("Slice", 2, 4, 0);
Card RKO ("RKO", 5, 12, 0);
Card Riposte ("Riposte", 2, 5, 0);
Card Brutalise("Brutalise", 4, 11, 0);
Card Stumble ("Stumble", 1, 1, 0);
Card Disco("Disco", 3, 0, 15);

Card Chomp ("Chomp", 1, 20, 0);
Card Smash ("Smash", 3, 59, 0);
Card Twerk ("Twerk", 2, 32, 0);
Card M16 ("M16", 4, 68, 0);
Card Groom1 ("Groom", 6, 100, 0);
Card Groom2("Groom", 6, 100, 0);
Card Groom3("Groom", 6, 100, 0);
Card ChugJug1("ChugJug", 2, 0, 50);
Card ChugJug2("ChugJug", 2, 0, 50);
Card ChugJug3("ChugJug", 2, 0, 50);

class Deck
{
 public:
	 vector<Card> vDeck;
    Deck(string Character)
    {
        
        if (Character == "Wizard")
        {
            vDeck.push_back(Curse1);
            vDeck.push_back(Curse2);
            vDeck.push_back(Curse3);
            vDeck.push_back(Blaze1);
            vDeck.push_back(Blaze2);
            vDeck.push_back(Blaze3);
            vDeck.push_back(Shock1);
            vDeck.push_back(Shock2);
            vDeck.push_back(Shock3);
            vDeck.push_back(Cough1);
            vDeck.push_back(Cough2);
            vDeck.push_back(Cough3);
            vDeck.push_back(Cough4);
            vDeck.push_back(LightSpam1);
            vDeck.push_back(LightSpam2);
			vDeck.push_back(Restore1);
			vDeck.push_back(Restore2);
        }
        if (Character == "Rogue")
        {
            vDeck.push_back(Slice);
            vDeck.push_back(RKO);
            vDeck.push_back(Riposte);
            vDeck.push_back(Brutalise);
            vDeck.push_back(Stumble);
			vDeck.push_back(Disco);
        }
        if (Character == "Jack LLoyd")
        {
            vDeck.push_back(Chomp);
            vDeck.push_back(Smash);
            vDeck.push_back(Twerk);
            vDeck.push_back(M16);
            vDeck.push_back(Groom1);
			vDeck.push_back(Groom2);  
			vDeck.push_back(Groom3);
			vDeck.push_back(ChugJug1);
            vDeck.push_back(ChugJug2);
            vDeck.push_back(ChugJug3);
		}
    }
};


class Hand
{
public:
    vector<Card> vHand;
    Hand(string Character, vector<Card>& vDeck)
    {
        // Shuffle the remaining deck using the existing RNG
        std::shuffle(vDeck.begin(), vDeck.end(), gen);

        // Draw up to 5 cards (or fewer if deck is smaller)
        for (int i = 0; i < 5 && !vDeck.empty(); ++i)
        {
            vHand.push_back(vDeck.back());
            vDeck.pop_back();
        }
    }


    void DrawCard(vector <Card>& vDeck)
    {
        if (vDeck.empty()) return; // guard: nothing to draw
        std::uniform_int_distribution<> distr(0, static_cast<int>(vDeck.size()) - 1); // Define range
        int randomIndex = distr(gen);
        vHand.push_back(vDeck.at(randomIndex));
        vDeck.erase(vDeck.begin() + randomIndex);
    }
    bool IsCardSelected(vector<Card> SelectedCards, vector<Card> Hand, int i)
    {

        for (int j = 0; j < SelectedCards.size(); j++)
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

    void PrintHand(Deck& D)
    {
        int cHover = 0;
        vector<int> SelectedIndices; // store indices instead of Card objects

        while (true)
        {
            enemy enemy("", 1, 1);

            if (Round == 1)
            {
                enemy.name = Goblin.name;
                enemy.health = Goblin.health;
                enemy.damage = Goblin.damage;
            }
            if (Round == 2)
            {
                enemy.name = Orc.name;
                enemy.health = Orc.health;
                enemy.damage = Orc.damage;
            }
            if (Round == 3)
            {
                enemy.name = JohnStoke.name;
                enemy.health = JohnStoke.health;
                enemy.damage = JohnStoke.damage;
            }
            if (Round > 3)
            {
                system("cls");
                cout << R"(
 _ _                    _       _  _  _ 
| | | ___  _ _   _ _ _ <_>._ _ | || || |
\   // . \| | | | | | || || ' ||_/|_/|_/
 |_| \___/`___| |__/_/ |_||_|_|<_><_><_>)";
                cout << "\n\n Press any key to go back to character selection screen";
				_getch();
				Round = 1;
				Turn = 1;
                break;
            }

            if (Turn % 2 == 0) // enemy turn
            {
              
                system("cls");
                cout << "Enemy's Turn! Press any key to continue..." << endl;
                _getch();
                system("cls");
                int enemyDamage = rand() % enemy.damage + 5; // Random damage based on which enemy
                cout << "The " << enemy.name << " attacks you for " << enemyDamage << " damage!" << endl;
                Player.pTakeDamage(enemyDamage);
                cout << "You have " << Player.health << " health remaining!" << endl;
                Turn++;
                IsDead(Player, enemy, Round, Turn);
                _getch();
                continue;
            }
            else // player turn
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
                        cout << GREEN << BOLD << '|' << RESET;
                    else
                        cout << '|';

                    int spaces = (9 - vHand.at(i).Name.length()) / 2;
                    for (int j = 0; j < spaces; j++) cout << " ";

                    bool isSelected = (std::find(SelectedIndices.begin(), SelectedIndices.end(), i) != SelectedIndices.end());

                    if (isSelected)
                        cout << UNDERLINE << RED << BOLD << FLASHING << vHand.at(i).Name << RESET;
                    else if (i == cHover)
                        cout << UNDERLINE << GREEN << BOLD << vHand.at(i).Name << RESET;
                    else
                        cout << vHand.at(i).Name;

                    for (int j = 0; j < spaces; j++) cout << " ";
                    if (i == cHover)
                        cout << GREEN << BOLD << "|   " << RESET;
                    else
                        cout << "|   ";
                }

                for (int r = 0; r < 3; r++)
                {
                    cout << "\n\t";
                    for (int j = 0; j < vHand.size(); j++)
                    {
                        if (j == cHover)
                            cout << GREEN << BOLD << "|         |   " << RESET;
                        else
                            cout << "|         |   ";
                    }
                }

                cout << "\n\t";
                for (int i = 0; i < vHand.size(); i++)
                {
                    if (i == cHover)
                        cout << GREEN << BOLD << "|_________|   " << RESET;
                    else
                        cout << "|_________|   ";
                }

                cout << "\n\n\t\t\t\t\t(" << Player.mana << ")\n";
                char key = _getch(); 

                if (vHand.empty())
                {
                    if (!D.vDeck.empty())
                    {
                        DrawCard(D.vDeck); continue;
                    } 
                    else
                    {
                        continue;
                    }
                }

                if (key == 75) { // Left arrow key
                    cHover = (cHover - 1 + vHand.size()) % vHand.size();
                }
                else if (key == 77) { // Right arrow key
                    cHover = (cHover + 1) % vHand.size();
                }
                else if (key == 32) 
                {
                    auto it = std::find(SelectedIndices.begin(), SelectedIndices.end(), cHover);
                    if (it != SelectedIndices.end())
                    {
                        // unselect
                        SelectedIndices.erase(it);
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
                        SelectedIndices.push_back(cHover);
                        Player.mana -= vHand.at(cHover).ManaCost;
                        continue;
                    }
                }
                else if (key == '\r') { 
                    if (SelectedIndices.empty())
                    {
                        
                        Player.mana += ManaIndex;
                        ManaIndex++;
                        Turn++;
                        if (vHand.size() < 7)
                        {
                            DrawCard(D.vDeck);
                        }
                        continue;
                    }

                    
                    string ListofSelectedCards = "";
                    int cSelectedDamage = 0;
                    int cSelectedHeal = 0;
                    
                    for (size_t k = 0; k < SelectedIndices.size(); ++k)
                    {
                        int idx = SelectedIndices[k];
                        if (k > 0 && k == SelectedIndices.size() - 1)
                            ListofSelectedCards += " and ";
                        else if (k > 0)
                            ListofSelectedCards += ", ";

                        ListofSelectedCards += vHand.at(idx).Name;
                        cSelectedDamage += vHand.at(idx).Damage;
                        cSelectedHeal += vHand.at(idx).Heal;
                    }

                    system("cls");
                    cout << "You played " << ListofSelectedCards;
                        if (cSelectedDamage > 0 )
                        {

                            cout << " dealing " << cSelectedDamage << " damage";
                        }
                        if (cSelectedDamage > 0 && cSelectedHeal > 0)
                        {
                            cout << " and";
                        }
                        if (cSelectedHeal > 0)
                        {
                            cout << " healing you for " << cSelectedHeal << " health!" << endl;
                        }
                        else
                        {
                            cout << "!" << endl;
						}
                        if (enemy.name == "Goblin")
                        {
                            Goblin.health = Goblin.eTakeDamage(cSelectedDamage);
                        }
                        if (enemy.name == "Orc")
                        {
                            Orc.health = Orc.eTakeDamage(cSelectedDamage);
						}
                        if (enemy.name == "John Stoke")
                        {
							JohnStoke.health = JohnStoke.eTakeDamage(cSelectedDamage);

						}
                        if(enemy.health <=0)
                        {
                            enemy.health = 0;
						}
                    cout << enemy.name << " has " << enemy.eTakeDamage(cSelectedDamage) << " health remaining!" << endl;
                    Player.mana += ManaIndex;
                    ManaIndex++;
                    Turn++;

                    std::sort(SelectedIndices.begin(), SelectedIndices.end(), std::greater<int>());
                    for (int idx : SelectedIndices)
                    {
                        // push the removed card back to deck
                        D.vDeck.push_back(vHand.at(idx));
                        vHand.erase(vHand.begin() + idx);
                    }

                    SelectedIndices.clear();

                    if (vHand.size() < 7)
                    {
                        DrawCard(D.vDeck);
                    }
                    _getch();
                    IsDead(Player, enemy, Round, Turn);
                    continue;
                }
            }
        }
    }
};


    void displayMenu(const string options[], int size, int selected, string extra)
    {
        system("cls"); 
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
                Deck D(options[selected]);
                Hand H(options[selected], D.vDeck);
                H.PrintHand(D);

               
            }
        }




    }


    int main()
    {

        const int optionCount = 3;
        string options[optionCount] = { "Start Game", "How to play", "Exit" };
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
                else if (options[selected] == "How to play")
                {
					system("cls");
                    cout << "How to Play:\n\n";
                    cout << "1. Select your character class: Rogue, Wizard, or Jack LLoyd.\n";
                    cout << "2. Each class has a unique deck of cards with different abilities.\n";
                    cout << "3. On your turn, you can play cards from your hand by selecting them using the space bar.\n";
                    cout << "4. Each card has a mana cost, ensure you have enough mana to play it.\n";
                    cout << "5. You can select multiple cards to play in one turn :)\n";
                    cout << "6. After playing cards, end your turn using the enter key.\n";
                    cout << "7. Defeat enemies to progress through rounds and win the game!\n\n";
                    cout << "Press any key to return to the main menu...";
					_getch();
                }
                else if (options[selected] == "Exit") {
                    break;
                }


                
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
