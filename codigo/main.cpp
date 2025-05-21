#include "sudoku.cpp"
#include <iostream>
#include <string>

using namespace std;

int main() {

    int game[9*9];
    string gameString;

    cout << "Insira uma matriz de um jogo válido (no formato: 0 1 2 0 ...)" << endl;

    for(int i = 0; i < 81 ; i++) {
        cin >> game[i];
    }

    Sudoku sudokuGame(game);    
    sudokuGame.solveGame();
    sudokuGame.printGame();

    return 0;
}
