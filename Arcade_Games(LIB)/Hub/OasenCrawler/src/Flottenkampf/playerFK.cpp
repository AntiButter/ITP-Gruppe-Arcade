#include <iostream>
#include <conio.h>
#define NOMINMAX
#include <Windows.h>

#include "playerFK.h"
#include "Hunter.h"
#include "Destroyer.h"
#include "Battleship.h"
#include "WorldFK.h"

HANDLE hConsole3;

PlayerFK::PlayerFK(std::shared_ptr<WorldFK> ocean)
{
	cursor[0] = 5;
	cursor[1] = 8;
	queryName();
}

PlayerFK::PlayerFK(std::shared_ptr<WorldFK> ocean, int fleetSize)
{
	setName(nameGenerator());
}

PlayerFK::~PlayerFK()
{
}

void PlayerFK::createBotFleet(int fleetSize, std::shared_ptr<WorldFK> ocean)
{
	for (int i = fleetSize; i > 0; i--)
	{
		addShip(rand() % 3);
	}
	for (int i = 0; i < fleetSize; i++)
	{
		fleet[i]->posX = rand() % 5 + 5;
		fleet[i]->posY = i+rand() % 3 + 1;
		while (fleet[i]->posY >= 15)
		{
			fleet[i]->posY = i + rand() % 3 + 1;
		}
		ocean->setWorld(fleet[i]->posX, fleet[i]->posY, 2);
	}
}

void PlayerFK::createFleet(int fleetSize, std::shared_ptr<WorldFK> ocean)
{
	for (int i = 0; i < fleetSize; i++)
	{
		queryNewShip(ocean);
	}
}

void PlayerFK::queryName()
{
	std::string name;
	std::cout << std::endl << "\nCaptain's Name: ";
	std::cin >> name;
	setName(name);
}

void PlayerFK::setName(std::string newName)
{
	name = newName;
}

int PlayerFK::getStarterFleetSize()
{
	return fleetSize;
}

int PlayerFK::queryFleetSize()
{
	int mode = 0;
	std::cout << "\nWie gross soll die Flotte sein? [1-9]\n";
	while (mode < 1 || mode > 9)
	{
		try
		{
			std::cin >> mode;
			if (std::cin.fail())
			{
				throw(1);
			}
			if (mode < 1 && mode > 10)
			{
				throw(2);
			}
		}
		catch (int error)
		{
			switch(error)
			{
			case 1:
				std::cout << std::endl << "Ungultige Eingabe\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			case 2:
				std::cout << "\n[INFO] Nur die Ziffern 1-9 sind erlaubt.\n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
	}
	fleetSize = mode;
	return mode;
}

void PlayerFK::queryNewShip(std::shared_ptr<WorldFK> ocean)
{
	hConsole3 = GetStdHandle(STD_OUTPUT_HANDLE);
	char input = 'x';
	int ship = 0;
	while (input != '\r')
	{
		system("cls");
		std::cout << "Wahle neues Mitglied. Schiff Position " << fleet.size()+1 << std::endl;
		std::cout << "		[W]\n->";
		switch (ship)
		{
		case 0:
			std::cout << " Jaeger";
			std::cout << "\n		[S]\n";
			std::cout << "\n HP  [75]  [";
			SetConsoleTextAttribute(hConsole3, 68);
			std::cout << "#####";
			SetConsoleTextAttribute(hConsole3, 15);
			std::cout << "] \n DMG [30]  [";
			SetConsoleTextAttribute(hConsole3, 102);
			std::cout << "###";
			SetConsoleTextAttribute(hConsole3, 15);
			std::cout << "]\n LN  [4]   [";
			SetConsoleTextAttribute(hConsole3, 136);
			std::cout << "####";
			SetConsoleTextAttribute(hConsole3, 15);
			std::cout << "]\n";
			std::cout << "\nFahigkeit: Kritische Treffer verursachen DMG * 2.";
			break;
		case 1:
			std::cout << " Zerstorer";
			std::cout << "\n		[S]\n";
			std::cout << "\n HP  [150] [";
			SetConsoleTextAttribute(hConsole3, 68);
			std::cout << "##########";
			SetConsoleTextAttribute(hConsole3, 15);
			std::cout << "] \n DMG [60]  [";
			SetConsoleTextAttribute(hConsole3, 102);
			std::cout << "######";
			SetConsoleTextAttribute(hConsole3, 15);
			std::cout << "]\n LN  [6]   [";
			SetConsoleTextAttribute(hConsole3, 136);
			std::cout << "######";
			SetConsoleTextAttribute(hConsole3, 15);
			std::cout << "]\n";
			std::cout << "\nFahigkeit: +20% waffen genauigkeit.";
			break;
		case 2:
			std::cout << " Kreuzer";
			std::cout << "\n		[S]\n";
			std::cout << "\n HP  [250] [";
			SetConsoleTextAttribute(hConsole3, 68);
			std::cout << "################";
			SetConsoleTextAttribute(hConsole3, 15);
			std::cout << "] \n DMG [50]  [";
			SetConsoleTextAttribute(hConsole3, 102);
			std::cout << "#####";
			SetConsoleTextAttribute(hConsole3, 15);
			std::cout << "]\n LN  [8]   [";
			SetConsoleTextAttribute(hConsole3, 136);
			std::cout << "########";
			SetConsoleTextAttribute(hConsole3, 15);
			std::cout << "]\n";
			std::cout << "\nFahigkeit: Treffer erlauben einen weiteren Angriff auf das selbe Ziel.";
			break;
		}

		if (fleet.size() > 0)
		{
			int index = fleet.size();
			std::cout << "\nNeuen \"" << fleet[index-1]->getShipType() << "\" hinzugefugt.";
		}
		input = _getch();
		if (input == 'w' && ship != 0) { ship--; }
		if (input == 's' && ship != 2) { ship++; }
	}
	addShip(ship);
	fleet[fleet.size() - 1]->queryPosition(ocean, shared_from_this());
	ocean->setWorld(fleet[fleet.size() - 1]->posX, fleet[fleet.size() - 1]->posY, 1);
}

void PlayerFK::addShip(int type)
{
	if (type == 0)
	{
		 fleet.emplace_back(std::make_shared<Hunter>());
	}
	if (type == 1)
	{
		fleet.emplace_back(std::make_shared<Destroyer>());
	}
	if (type == 2)
	{
		fleet.emplace_back(std::make_shared<Battleship>());
	}
}

std::string PlayerFK::nameGenerator()
{
	std::string botName = "Captain ";
	switch (rand() % 8 + 1)
	{
	case 1:
		return botName + "Karl";
	case 2:
		return botName + "Max";
	case 3:
		return botName + "Subaru";
	case 4:
		return botName + "Larry";
	case 5:
		return botName + "Timon";
	case 6:
		return botName + "Byorn";
	case 7:
		return botName + "Gunner";
	case 8:
		return botName + "Gunter";
	}
	return "Name Fail";
}

std::string PlayerFK::getName()
{
	return name;
}

void PlayerFK::playerTurn(std::shared_ptr<WorldFK> ocean, std::shared_ptr<PlayerFK> enemy)
{
	moveShip(shared_from_this()->fleet[queryAttackShip(shared_from_this(), ocean)], ocean);
	fleet[queryAttackShip(shared_from_this(), ocean)]->special(enemy->fleet[queryAttackShip(enemy, ocean)]);
}

void PlayerFK::moveShip(std::shared_ptr<Ship> target, std::shared_ptr<WorldFK> ocean)
{
	char lastMove;
	int moves = 0;
	char direction = 'x';
	while (direction != '\r' && moves < 3)
	{
		system("cls");
		std::cout << "		    [w] \n";
		std::cout << "		 [a][s][d] \n";
		std::cout << "\nCaptain" << name << " ist am Zug\n";
		std::cout << "\nBewege dein Schiff " << moves << "/3\n";
		try
		{
			ocean->printWorld(target->posX, target->posY);
			ocean->setWorld(target->posX, target->posY, 0);
			lastMove = direction;
			direction = _getch();
			if ((direction == 'w' && cursor[0] <= 0) || (direction == 's' && cursor[0] >= 9) || (direction == 'a' && cursor[1] <= 0) || (direction == 'd' && cursor[1] >= 14))
			{
				direction = 'x';
				throw(4);
			}
			if (direction != 'w' && direction != 's' && direction != 'a' && direction != 'd' && direction != '\r')
			{
				throw (5);
			}
			if ((direction == 'w' && ocean->checkPos(cursor[0] - 1, cursor[1]) != 0) || 
				(direction == 's' && ocean->checkPos(cursor[0] + 1, cursor[1]) != 0) ||
				(direction == 'a' && ocean->checkPos(cursor[0], cursor[1] - 1) != 0) ||
				(direction == 'd' && ocean->checkPos(cursor[0], cursor[1] + 1) != 0))
			{
				moves--;
				direction = 'x';
				throw(6);
			}
		}

		catch (int invalid_input2)
		{
			switch (invalid_input2)
			{
			case 3:
				std::cout << "\nEingabe Unbekannt.\n";
				std::cin.clear();
				break;
			case 4:
				std::cout << "\n[INFO] Ein echter Captain versucht keine Flucht.\n";
				_getch();
				break;
			case 5:
				std::cout << "\nUngültige Eingabe.\n";
				_getch();
				break;
			case 6:
				std::cout << "\nPositon nicht frei.";
				_getch();
				break;
			}
		}
		switch (direction)
		{
		case 'w':
			cursor[0]--;
			target->posX--;
			break;
		case 'a':
			cursor[1]--;
			target->posY--;
			break;
		case 's':
			cursor[0]++;
			target->posX++;
			break;
		case 'd':
			cursor[1]++;
			target->posY++;
			break;
		}
		moves++;
		ocean->setWorld(target->posX, target->posY, 1);
	}
}

int PlayerFK::queryAttackShip(std::shared_ptr<PlayerFK> target, std::shared_ptr<WorldFK> ocean)
{
	int selected = 0;
	char direction = 'x';
	while (direction != '\r')
	{
		system("cls");
		std::cout << "	    [w] \n";
		std::cout << "	 [a][s][d] \n";
		std::cout << "\nCaptain " << name << " ist am Zug\n";
		std::cout << "\nWahle ein Schiff für den Angriff / als Ziel.\n";
		try
		{
			moveCursor(direction);
			ocean->printWorld(cursor[0], cursor[1]);
			printFleet(target, cursor[0], cursor[1]);
			direction = _getch();
			if ((direction == 'w' && cursor[0] <= 0) || (direction == 's' && cursor[0] >= 9) || (direction == 'a' && cursor[1] <= 0) || (direction == 'd' && cursor[1] >= 14))
			{
				direction = 'x';
				throw(4);
			}
			if (direction != 'w' && direction != 's' && direction != 'a' && direction != 'd' && direction != '\r')
			{
				throw (5);
			}
			if (direction == '\r')
			{
				for (int i = 0; i < target->fleet.size(); i++)
				{
					if (target->fleet[i]->posX == cursor[0] && target->fleet[i]->posY == cursor[1])
					{
						return i;
					}
				}
				throw (6);
			}
		}
		catch (int invalid_input2)
		{
			switch (invalid_input2)
			{
			case 3:
				std::cout << "\nEingabe Unbekannt.\n";
				std::cin.clear();
				break;
			case 4:
				std::cout << "\n[INFO] Es gibt keine feindlichen Schiffe in dieser Richtung.\n";
				break;
			case 5:
				std::cout << "\nUngültige Eingabe.\n";
				break;
			case 6:
				direction = 'x';
				std::cout << "\n Wahle ein Schiff.";
			}
		}
	}
}

void PlayerFK::printFleet(std::shared_ptr<PlayerFK> target, int x, int y)
{
	hConsole3 = GetStdHandle(STD_OUTPUT_HANDLE);
	int hp = 0;
	std::cout << "\n\n"<< target->name << "'s Flotte.\n";
	for (unsigned int i = 0; i < target->fleet.size(); i++)
	{
		std::cout << "\n " << target->fleet[i]->getShipType() << " " << target->fleet[i]->getHull() << "HP ";
		if (x == target->fleet[i]->posX && y == target->fleet[i]->posY) 
		{ 
			SetConsoleTextAttribute(hConsole3, 68);
			for (int j = target->fleet[i]->getHull() / 10; j > 1; j--)
			{
				std::cout << "#";
			}
			SetConsoleTextAttribute(hConsole3, 15);

			std::cout << " <-\n";
		}
		else
		{
			std::cout << "\n";
		}
	}
}

void PlayerFK::moveCursor(char direction)
{
	//std::cout << "\nWelches Schiff soll bewegt werden?";
	if (direction == 'a')
	{
		cursor[1]--;
	}
	if (direction == 'd')
	{
		cursor[1]++;
	}
	if (direction == 'w')
	{
		cursor[0]--;
	}
	if (direction == 's')
	{
		cursor[0]++;
	}
}

void PlayerFK::botTurn(std::shared_ptr<WorldFK> ocean, std::shared_ptr<PlayerFK> newPlayer)
{
	int randShip = rand() % fleet.size();
	system("cls");
	std::cout << "\nCaptain" << name << " ist am Zug\n";
	ocean->printWorld(20,20);
	moveBot(randShip, ocean);
	ocean->printWorld(20,20);
	fleet[randShip]->special(newPlayer->fleet[rand() % newPlayer->fleet.size()]);
}

void PlayerFK::moveBot(int randShip, std::shared_ptr<WorldFK> ocean)
{
	for (int i = 0; i < 3; i++)
	{
		ocean->setWorld(fleet[randShip]->posX, fleet[randShip]->posY, 0);
		switch (rand() % 5)
		{
		case 0:
			if(fleet[randShip]->posX != 0 && ocean->checkPos(fleet[randShip]->posX - 1, fleet[randShip]->posY) == 0)
			{
				fleet[randShip]->posX--;
			}
			break;
		case 1:
			if (fleet[randShip]->posX != 9 && ocean->checkPos(fleet[randShip]->posX + 1, fleet[randShip]->posY) == 0)
			{
				fleet[randShip]->posX++;
			}
			break;
		case 2:
			if (fleet[randShip]->posY != 0 && ocean->checkPos(fleet[randShip]->posX, fleet[randShip]->posY - 1) == 0)
			{
				fleet[randShip]->posY--;
			}
			break;
		case 3:
			if (fleet[randShip]->posY != 0 && ocean->checkPos(fleet[randShip]->posX, fleet[randShip]->posY + 1) == 0)
			{
				fleet[randShip]->posY++;
			}
			break;
		case 4:
			break;
		}
		ocean->setWorld(fleet[randShip]->posX, fleet[randShip]->posY, 2);
	}

}