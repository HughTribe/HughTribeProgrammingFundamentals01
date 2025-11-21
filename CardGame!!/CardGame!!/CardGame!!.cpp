


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

Card Chomp ("Chomp", 1, 20, 0);
Card Smash ("Smash", 3, 59, 0);
Card Twerk ("Twerk", 2, 32, 0);
Card M16 ("M16", 4, 68, 0);
Card Groom ("Groom", 6, 100, 0);

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
        }
        if (Character == "Jack LLoyd")
        {
            vDeck.push_back(Chomp);
            vDeck.push_back(Smash);
            vDeck.push_back(Twerk);
            vDeck.push_back(M16);
            vDeck.push_back(Groom);
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
            if (Turn % 2 == 0) // enemy turn
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
                char key = _getch(); // Get user input without pressing Enter
                // If hand is empty, try to draw or skip input handling

                if (vHand.empty())
                {
                    if (!D.vDeck.empty())
                    {
                        DrawCard(D.vDeck); continue;
                    } // try to refill hand
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
                else if (key == 32) // Space toggles selection at current index
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
                else if (key == '\r') { // Enter: play selected cards
                    if (SelectedIndices.empty())
                    {
                        // nothing selected
                        Player.mana += ManaIndex;
                        ManaIndex++;
                        Turn++;
                        if (vHand.size() < 7)
                        {
                            DrawCard(D.vDeck);
                        }
                        continue;
                    }

                    // Build readable list and total damage and heal
                    string ListofSelectedCards = "";
                    int cSelectedDamage = 0;
                    int cSelectedHeal = 0;
                    // sort indices to build list in the order they were selected (optional)
                    // we can iterate SelectedIndices as-is; here we produce a readable list:
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
                
                    cout << Goblin.name << " has " << Goblin.eTakeDamage(cSelectedDamage) << " health remaining!" << endl;
                    Player.mana += ManaIndex;
                    ManaIndex++;
                    Turn++;

                    // Remove played cards by index. Erase in descending order to avoid shifting indices.
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
                Deck D(options[selected]);
                Hand H(options[selected], D.vDeck);
                H.PrintHand(D);

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
