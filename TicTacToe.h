//
// Created by dalli on 8/3/2023.
//

#ifndef TIC_TAC_TOE_TICTACTOE_H
#define TIC_TAC_TOE_TICTACTOE_H

#include <iostream>
#include <string.h>
#include <sstream>


class TicTacToe {
private:
    char gameArray [9];
    bool isGameOver;

    //populates the array with empty squares
    void clearGame() {
        for (int i = 0; i < 9; ++i) {
            gameArray[i] = '-';
        }
    }

public:
    TicTacToe() {
        clearGame();
        isGameOver = false;
    }
    // Starts the game
    std::string startGame () {
        clearGame();
        std::stringstream out;

        out << "Welcome to Tic-Tac-Toe!\n";
        out << "Enter a square to begin:\n";
        out << "|  1  |  2  |  3  |\n";
        out << ">-----------------<\n";
        out << "|  4  |  5  |  6  |\n";
        out << ">-----------------<\n";
        out << "|  7  |  8  |  9  |\n";

        return out.str();
    }

    // takes the user's input and goes through their turn and the computer's turn
    std::string userTurn (std::string choice) {

        // checks if their input is valid
        if (!std::isdigit(choice[0])) {
            return "Not a valid option, choose a number 1-9 and try again!\n";
        }
        int newChoice = stoi(choice);
        if (newChoice > 9 || newChoice < 1 || gameArray[newChoice - 1] != '-') {
            return "Not a valid option, choose a number 1-9 and try again!\n";
        }
        gameArray[newChoice - 1] = 'X';
        std::cout << "You played square " << choice << "\n";

        // checks if the game is over
        if (isDraw()) {
            std::cout << "The game is a draw.\n";
            isGameOver = true;
            return outGame();
        }
        if (gameWon()) {
            std::cout << "You win. Good job!\n";
            isGameOver = true;
            return outGame();
            }

        computerTurn();
        return outGame();
    }

    // finds a move for the computer and plays it
    void computerTurn() {
        if (computerCanWin()) {
            return;
        }
        else if (playerCanWin()) {
            return;
        }
        else {
            // TODO make logic for the computer's turn if it's not blocking or winning
            for (int i = 0; i < 9; ++i) {
                if (gameArray[i] == '-') {
                    gameArray[i] = 'O';
                    std::cout << "The computer plays square " << (i + 1) << ". Your turn!\n";
                    return;
                }
            }
        }
    }

    // checks to see if the player can win, and blocks the win if so
    bool playerCanWin() {
        for (int i = 0; i < 9; ++i) {
            if (gameArray[i] == '-') {
                gameArray[i] = 'X'; // temporarily changes the square to 'X' to see if there is a win
                if (gameWon()) {
                    gameArray[i] = 'O';
                    std::cout << "The computer plays square " << (i + 1) << "\n";
                    return true;
                }
                gameArray[i] = '-'; // Reverts the move
            }
        }
        return false;
    }

    // checks to see if the game is ended in a draw
    bool isDraw() {
        if (gameArray[0] != '-' && gameArray[1] != '-' && gameArray[2] != '-'
        && gameArray[3] != '-' && gameArray[4] != '-' && gameArray[5] != '-'
        && gameArray[6] != '-' && gameArray[7] != '-' && gameArray[8] != '-') {
            return true;
        }
        else {
            return false;
        }
    }

    // Checks to see if the computer can win and plays the move if it can
    bool computerCanWin() {
        for (int i = 0; i < 9; ++i) {
            if (gameArray[i] == '-') {
                gameArray[i] = 'O'; // // temporarily changes the square to 'O' to see if there is a win
                if (gameWon()) {
                    std::cout << "The computer plays square " << (i + 1) << " and wins!\n";
                    isGameOver = true;
                    return true;
                }
                gameArray[i] = '-'; // Reverts the move
            }
        }
        return false;
    }

    // creates a string of the current board
    std::string outGame() const {
        std::stringstream out;
        out << "|  " << gameArray[0] << "  |  " << gameArray[1] << "  |  " << gameArray[2] << "  |\n";
        out << ">-----------------<\n";
        out << "|  " << gameArray[3] << "  |  " << gameArray[4] << "  |  " << gameArray[5] << "  |\n";
        out << ">-----------------<\n";
        out << "|  " << gameArray[6] << "  |  " << gameArray[7] << "  |  " << gameArray[8] << "  |\n";

        return out.str();
    }
    // Checks to see if the game is won
    bool gameWon() {
        if ((gameArray[0] == gameArray[1] && gameArray[0] == gameArray[2] && gameArray[0] != '-')
        || (gameArray[3] == gameArray[4] && gameArray[3] == gameArray[5] && gameArray[3] != '-')
        || (gameArray[6] == gameArray[7] && gameArray[6] == gameArray[8] && gameArray[6] != '-')
        || (gameArray[0] == gameArray[3] && gameArray[0] == gameArray[6] && gameArray[0] != '-')
        || (gameArray[1] == gameArray[4] && gameArray[1] == gameArray[7] && gameArray[1] != '-')
        || (gameArray[2] == gameArray[5] && gameArray[2] == gameArray[8] && gameArray[2] != '-')
        || (gameArray[0] == gameArray[4] && gameArray[0] == gameArray[8] && gameArray[0] != '-')
        || (gameArray[2] == gameArray[4] && gameArray[2] == gameArray[6] && gameArray[2] != '-')) {
            return true;
        }
        else {
            return false;
        }
    }

    void setGameOver (bool choice) {
        isGameOver = choice;
        return;
    }

    bool gameOver () {
        return isGameOver;
    }
};


#endif //TIC_TAC_TOE_TICTACTOE_H
