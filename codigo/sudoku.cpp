#include "sudoku.h"
#include <iostream>

using namespace std;

Sudoku::Sudoku(int gameMatrix[]) {
    for(int i = 0; i < 81; i++) {
        baseMatrix[i] = gameMatrix[i];   
        this->gameMatrix[i] = gameMatrix[i];
    }
}

Sudoku::~Sudoku() {}

void Sudoku::printGame() {
    cout << "_________________\n";
    cout << "\nJogo Resolvido: \n\n";

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cout << baseMatrix[i * 9 + j] << " ";
        }
        cout << endl;
    }

    cout << "_________________\n";
}

bool Sudoku::isValidDigit(int digit, int line, int column) {
    for (int j = 0; j < 9; j++) {
        if (gameMatrix[line * 9 + j] == digit) {
            return false;
        }
    }

    for (int i = 0; i < 9; i++) {
        if (gameMatrix[i * 9 + column] == digit) {
            return false;
        }
    }

    int startRow = (line / 3) * 3;
    int startColumn = (column / 3) * 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int row = startRow + i;
            int column = startColumn + j;
            if (gameMatrix[row * 9 + column] == digit) {
                return false;
            }
        }
    }
    
    return true;
}

int Sudoku::findNextValidDigit(int startDigit, int position) {
    int position_i = (position / 9);
    int position_j = position - (9 * (position / 9));
    
    for(int i = startDigit + 1; i <= 9; i++) {
        if(isValidDigit(i, position_i, position_j)) {
            return i;
        }
    }

    return 0;
}

void Sudoku::solveGame() {
    bool test = true;
    int position = 0;

    while(test) {

        if(position >= 81) {
            test = false;
        }
        else {
            if(baseMatrix[position] == 0) {
                int nextValidDigit = findNextValidDigit(gameMatrix[position], position);
        
                if(nextValidDigit == 0) {
                    gameMatrix[position] = 0;
                    position --;
    
                    while(baseMatrix[position] != 0) {
                        position --;
                    }
                }
                else {
                    gameMatrix[position] = nextValidDigit;
                    position ++;
                }
            }
            else {
                gameMatrix[position] = baseMatrix[position];
                position ++;
            }
        }
    
    }
    
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            baseMatrix[i * 9 + j] = gameMatrix[i* 9 + j];   
        }
    }
}
