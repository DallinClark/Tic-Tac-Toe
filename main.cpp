#include <iostream>
#include <istream>
#include <string.h>
#include "TicTacToe.h"

int main() {
    // sets up variables and TicTacToe class
    TicTacToe currGame;
    std::string userChoice = "none";
    bool playGame = true;

    std::cout << currGame.startGame();

    while (playGame) {
        // gets user input and starts the user's turn
        std::getline(std::cin, userChoice);
        std::cout << currGame.userTurn(userChoice);

        // deals with the game ending
        if (currGame.gameOver()) {
            std::string choice;
            std::cout << "Do you want to play again? (Y/N)\n";
            std::getline(std::cin, userChoice);

            if (userChoice == "Y") {
                // sets up a new game
                currGame.setGameOver(false);
                std::cout << currGame.startGame();
                continue;
            }
            else if (userChoice == "N") {
                std::cout << "Thanks for playing!";
                playGame = false;
            }
            else {
                std::cout << "Invalid choice, ending game";
                playGame = false;
            }
        }
    }
    return 0;

}
