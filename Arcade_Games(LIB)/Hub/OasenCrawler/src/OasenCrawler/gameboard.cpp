#include "gameboard.h"
#include <iostream>
#include <time.h>
#include "playerOC.h"

gameboard::gameboard(player* pIn, monster* mIn)
{
    p = pIn;
    m = mIn;
    //m = new monster();
    std::cout << "Gameboard created" << std::endl;
}

gameboard::~gameboard()
{

}

void gameboard::SetValue(int y, int x, gb value) {
    this->board[y][x] = value;
}

int gameboard::GetValue(int y, int x) {
    return this->board[y][x];
}

void gameboard::SetRelics(int relics) {
    this->relics = relics;
}

int gameboard::GetRelics() {
    return this->relics;
}


void gameboard::generateBoard() {

    int rnum;

    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {

            if (y == 0 && x == 0) {
                this->SetValue(x, y, gameboard::leer);
            }
            else {
                rnum = rand() % 10;
                if (rnum <= 3) {
                    this->SetValue(x, y, gameboard::leer);
                }
                else if (rnum > 3 && rnum < 8) {
                    this->SetValue(x, y, gameboard::gefahr);
                }
                else if (rnum == 8) {
                    this->SetValue(x, y, gameboard::brunnen);
                }
                else if (rnum == 9) {
                    this->SetValue(x, y, gameboard::relikt);
                    this->SetRelics(this->GetRelics() + 1); //Copyright Agile Averagepolshark
                }
            }
        }
    }

    if (this->GetRelics() == 0) {
        //this->board[rand() % 4 + 1][rand() % 4 + 1] == gameboard::relikt;
        this->SetValue(rand() % 4 + 1, rand() % 4 + 1, gameboard::relikt);
        this->SetRelics(1);
    }




}

void gameboard::printBoard() {

    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            std::cout << "[";

            if (x == p->GetPx() && y == p->GetPy()) {
                std::cout << "X";
            }
            else if (x == m->GetMx() && y == m->GetMy()) {
                std::cout << "M";
            }
            else {

                if (this->GetValue(y, x) == 1) {
                    std::cout << " ";
                }
                else if (this->GetValue(y, x) == 2) {
                    std::cout << " "; //G
                }
                else if (this->GetValue(y, x) == 3) {
                    std::cout << " "; //B
                }
                else if (this->GetValue(y, x) == 4) {
                    std::cout << " "; //R
                }
                else if (this->GetValue(y, x) == 5) {
                    std::cout << "TEST";
                }

            }

            std::cout << "]";
        }
        std::cout << std::endl;
    }
}
