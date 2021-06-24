#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <cmath>

#include "Ship.h"
#include "PlayerFK.h"
#include <conio.h>

HANDLE hConsole2;

Ship::Ship()
{
    posX = 3;
    posY = 7;
    hull = 0;
    size = 0;
    dmg = 0;
}

Ship::~Ship()
{
}

void Ship::setHull(int value)
{
    hull = value;
    if (hull < 0)
    {
        hull = 0;
    }
}

int Ship::getHull()
{
    return hull;
}

void Ship::setSize(int value)
{
    size = value;
}

int Ship::getSize()
{
    return size;
}

void Ship::setDmg(int value)
{
    dmg = value;
}

int Ship::getDmg()
{
    return dmg;
}

void Ship::setPosition(int x, int y)
{
    posX = x;
    posY = y;
}

int Ship::rollDice()
{
    return rand() % 10 + 1;
}

void Ship::queryPosition(std::shared_ptr<WorldFK> ocean, std::shared_ptr<PlayerFK> player)
{
    hConsole2 = GetStdHandle(STD_OUTPUT_HANDLE);
    char confirm = 'x';
    int tmpWorld[10][15] = {0};
    while (confirm != '\r')
    {
        system("cls");
        std::cout << "Schiff Typ:  " << shipType << "hinzugefugt" <<std::endl;
        std::cout << "Wahle Schiff Position " << std::endl;
        std::cout << "      	    [W]\n ";
        std::cout << "      	 [A][S][D]";
        SetConsoleTextAttribute(hConsole2, 119);
        std::cout << "\n ________________________________";
        for (int x = 0; x < 5; x++)
        {
            SetConsoleTextAttribute(hConsole2, 119);
            std::cout << "\n|";
            for (int y = 0; y < 15; y++)
            {
                SetConsoleTextAttribute(hConsole2, 48);
                if (posX == x && posY == y)
                {
                    SetConsoleTextAttribute(hConsole2, 58);
                    std::cout << " X";
                }
                else
                {
                    for (int i = 0; i < player->fleet.size(); i++)
                    {
                        if (player->fleet[i]->posX == x && player->fleet[i]->posY == y)
                        {
                            SetConsoleTextAttribute(hConsole2, 239);
                        }
                    }
                    if (rand() % 10 <= 7)
                    {
                        std::cout << " ~";
                    }
                    else
                    {
                        std::cout << "  ";
                    }
                    SetConsoleTextAttribute(hConsole2, 15);
                }
            }
            SetConsoleTextAttribute(hConsole2, 119);
            std::cout << " |";
        }
        SetConsoleTextAttribute(hConsole2, 119);
        std::cout << "\n|-------------------------------|";
        SetConsoleTextAttribute(hConsole2, 15);
        try
        {
             confirm = _getch();
            if ((confirm == 'w' && posX <= 0) || (confirm == 's' && posX >= 4) || (confirm == 'a' && posY <= 0) || (confirm == 'd' && posY >= 14))
            {
                confirm = 'x';
                throw(4);
            }
            if (confirm != 'w' && confirm != 's' && confirm != 'a' && confirm != 'd' && confirm != '\r')
            {
                throw (5);
            }
            switch (confirm)
            {
            case 'w':
                posX--;
                break;
            case 'a':
                posY--;
                break;
            case 's':
                posX++;
                break;
            case 'd':
                posY++;
                break;
            case '\r':
                if (confirm == '\r' && ocean->checkPos(posX, posY) == 1)
                {
                    std::cout << "\n\nPosition bereits besetzt.";
                    _getch();
                    confirm = 'x';
                }
                else
                {
                    ocean->setWorld(posX, posY, 1);
                    std::cout << "\n\nSchiff positioniert.";
                    _getch();
                }
                break;
            }
        }
        catch (int invalid_input2)
        {
            switch (invalid_input2)
            {
            case 3:
                std::cout << "\nEingabe Unbekannt.\n";
                break;
            case 4:
                std::cout << "\n[INFO] Keine Felder in dieser Richtung.\n";
                break;
            case 5:
                std::cout << "\nUngültige Eingabe.\n";
                break;
            }
        }
    }
}

std::string Ship::getShipType()
{
    return shipType;
}

void Ship::setShipType(std::string signation)
{
    shipType = signation;
}

int Ship::getDistance(std::shared_ptr<Ship> target)
{
    int distanceX = abs(posX - target->posX);
    int distanceY = abs(posY - target->posY);
    return distanceX + distanceY;
}

