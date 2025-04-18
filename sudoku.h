#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku {
    private:
        int baseMatrix[9*9];
        int gameMatrix[9*9];

    public:
        Sudoku(int gameMatrix[]);
        ~Sudoku();

        void printGame();

        bool isValidDigit(int digit, int position_i, int position_j);
        int findNextValidDigit(int startDigit, int position);

        void solveGame();

};

#endif