#include "sudoku.cpp"
#include <iostream>
#include <string>

using namespace std;

int main() {

    int game[9*9];
    string gameString;

    cout << "Insira uma matriz de um jogo válido (no formato: 0, 1, 2, 0, ...)" << endl;
    getline(cin, gameString);

    for(int i = 0; i < 81 ; i++) {
        game[i] = stoi(gameString.substr(i*3 , 1));
    }

    Sudoku sudokuGame(game);    
    sudokuGame.solveGame();
    sudokuGame.printGame();

    return 0;
}
