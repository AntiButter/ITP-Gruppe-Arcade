#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

#include "Flottenkampf.h"
#include "Ship.h"
#include "playerFK.h"
#include "Hunter.h"
#include "WorldFK.h"

HANDLE hConsole4;

void gameStartMessage(PlayerFK* newPlayer, PlayerFK* bot);
namespace Flottenkampf
{
	std::vector<int> PlayFlottenkampf()
	{
		srand(time(NULL));
		WorldFK* ocean = new WorldFK();
		PlayerFK* newPlayer = new PlayerFK(ocean);
		PlayerFK* bot = new PlayerFK(ocean, newPlayer->fleet.size());
		gameStartMessage(newPlayer, bot);
		while (newPlayer->fleet.size() > 0 && bot->fleet.size() > 0)
		{
			newPlayer->playerTurn(ocean, bot);
			for (int i = 9; i > -1; i--)
			{
				if ((i <= bot->fleet.size() - 1) && bot->fleet[i]->getHull() == 0)
				{
					ocean->setWorld(bot->fleet[i]->posX, bot->fleet[i]->posY, 0);
					bot->fleet.erase(bot->fleet.begin() + i, bot->fleet.begin() + i + 1);
				}
			}
			if (bot->fleet.size() > 0)
			{
				bot->botTurn(ocean, newPlayer);
				for (int i = 9; i > -1; i--)
				{
					if ((i <= newPlayer->fleet.size() - 1) && (newPlayer->fleet[i]->getHull() == 0))
					{
						ocean->setWorld(newPlayer->fleet[i]->posX, newPlayer->fleet[i]->posY, 0);
						newPlayer->fleet.erase(newPlayer->fleet.begin() + i, newPlayer->fleet.begin() + i + 1);
						_getch();
					}
				}
			}
		}
		delete (newPlayer);
		delete (bot);
		std::vector<int> vector;
		vector.push_back(5);
		vector.push_back(1);
		if (vector[1] > 100)
			vector[1] = 100;
		return vector;
	}
}

void gameStartMessage(PlayerFK* newPlayer, PlayerFK* bot)
{
	hConsole4 = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole4, 39);
	std::cout << "\n\n	Spiel Start.\n Captain ";
	std::cout << newPlayer->getName() << " VS. " << bot->getName() << "\n\n";
	SetConsoleTextAttribute(hConsole4, 15);
	_getch();
}