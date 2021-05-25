#include <Windows.h>

#include "WorldFK.h"

HANDLE hConsole;

WorldFK::WorldFK()
{
    memset(world, 0, sizeof(int) * 10 * 15);
}

WorldFK::~WorldFK()
{
}

void WorldFK::printWorld(int cursorX, int cursorY)
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 119);
    std::cout << "\n ________________________________";
    SetConsoleTextAttribute(hConsole, 15);
    for (int x = 0; x < 10; x++)
    {
        SetConsoleTextAttribute(hConsole, 119);
        std::cout << "\n|";
        SetConsoleTextAttribute(hConsole, 15);
        for (int y = 0; y < 15; y++)
        {
            if (world[x][y] == 1)
            {
                SetConsoleTextAttribute(hConsole, 16);
                if (cursorX == x && cursorY == y)
                {
                    SetConsoleTextAttribute(hConsole, 64);
                }
                std::cout << " X";
            }
            else if (world[x][y] == 2)
            {
                SetConsoleTextAttribute(hConsole, 20);
                if (cursorX == x && cursorY == y)
                {
                    SetConsoleTextAttribute(hConsole, 64);
                }
                std::cout << " O";
            }
            else
            {
                SetConsoleTextAttribute(hConsole, 23);
                if (cursorX == x && cursorY == y)
                {
                    SetConsoleTextAttribute(hConsole, 71);
                }
                std::cout << " ~";
            }
            SetConsoleTextAttribute(hConsole, 15);
        }
        SetConsoleTextAttribute(hConsole, 119);
        std::cout << " |";
        SetConsoleTextAttribute(hConsole, 15);
    }
    SetConsoleTextAttribute(hConsole, 119);
    std::cout << "\n|-------------------------------|";
    SetConsoleTextAttribute(hConsole, 15);
}

void WorldFK::scanWorld(PlayerFK* player, PlayerFK* bot)
{
    for (int i = player->fleet.size() - 1; i > -1; i--)
    {
        world[player->fleet[i]->posX][player->fleet[i]->posY] = 1;
        world[bot->fleet[i]->posX][bot->fleet[i]->posY] = 2;
    }
}

void WorldFK::setWorld(int x, int y, int value)
{
    world[x][y] = value;
}

int WorldFK::checkPos(int x, int y)
{
    return world[x][y];
}
