#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "playerOC.h"
#include "monster.h"

class gameboard
{
public:
    enum gb {
        leer = 1, gefahr = 2, brunnen = 3, relikt = 4, test = 5
    };
    gameboard(player* pIn, monster* mIn);
    ~gameboard();
    int GetValue(int x, int y);
    void SetValue(int x, int y, gb val);

    int GetRelics();
    void SetRelics(int val);

    void generateBoard();
    void printBoard();


protected:

private:
    gb board[5][5];
    int relics = 0;
    int level = 1;
    player* p;
    monster* m;
};

#endif // GAMEBOARD_H
