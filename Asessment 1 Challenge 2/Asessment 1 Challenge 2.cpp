// Asessment 1 Challenge 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>


int main() 
{ 
    std::string name;
    std::string username;
    std::string clantag;
    unsigned int Exp = 200;
    
    std::cout << "What is your name?\n";
    std::cin >> name;
    std::cout << "What is your username?\n";
    std::cin >> username;
    std::cout << "What is your clantag?\n";
    std::cin >> clantag;
    do
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "How many experience points do you have?\n";
        std::cin >> Exp;
    } while (std::cin.fail() == true);
        
    
    int Level = Exp / 100;
    int ExpNeededToNextLevel = 100 * (Level + 1) - Exp;
    std::cout << "Your name is " << name << " and your in-game name is [ " << clantag << " ]" << username;
    std::cout << "\nYou have " << Exp << " experience points\n\n";
    std::cout << "You are currently level " << Level << '\n';
    std::cout << "You need " << ExpNeededToNextLevel << " points to reach the next level, which is " << (Level + 1);


        

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
