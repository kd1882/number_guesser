// preprocesser director and header file
#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
   // Expression statements: Print welcome messsages to the terminal
    std::cout << "\n\nWelcome to the \"tricky\" number guessing game.  You are on level " << Difficulty;
    std::cout << "\nYou need to enter the correct numbers to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Declaration statements: Declare 3 number code
    const int CodeA = rand() %Difficulty + Difficulty;
    const int CodeB = rand() %Difficulty + Difficulty;
    const int CodeC = rand() %Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Expression statements: Print sum and product to the terminal
    std::cout << "+ There are 3 numbers to guess with...";
    std::cout << "\n+ The numbers must add-up to: " << CodeSum;
    std::cout << "\n+ The numbers must multiply to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cout << "+ Enter your best guess: ";
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou win!  Onto the next level.\n";
        return true;
    }
    else
    {
        std::cout << "You lose! Try again.\n";
        return false;
    }
}

// Main Function
int main()
{
    srand(time(NULL)); // Create new random sequence based on time of day

    int LevelDifficulty = 1;
    const int MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel) // Loop game until it is completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    std::cout << "\n****You have won the number guesser.";
    return 0;
}