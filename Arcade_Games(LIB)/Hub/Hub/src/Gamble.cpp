#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "Gamble.h"

Gamble::Gamble()
{
	getPoints();
}

Gamble::~Gamble()
{

}

void Gamble::getPoints()
{
	std::string pointsString;
	std::fstream MyReadFile("Gamble.txt");

	getline(MyReadFile, pointsString);
	
	points = stoi(pointsString);

	MyReadFile.close();
}

void Gamble::showPoints()
{
	std::cout << "\nCredits: "<< points << std::endl;
}

void Gamble::savePoints()
{
	std::ofstream outfile("Gamble.txt");
	outfile << points;
	outfile.close();
}

void Gamble::slotMachine()
{
	srand(time(NULL));
	int x = 0;
	bool skip = false;

	for (int loop = 0; loop < 50; loop++)
	{
		system("cls");
		for (int i = 0; i < 9; i++)
		{
			if (i == 0)
			{
				std::cout << (char)218;
				for (int z = 0; z < 19; z++)
				{
					std::cout << (char)196;
				}
				std::cout << (char)191;
				std::cout << std::endl;
				continue;
			}

			if (i == 8)
			{
				std::cout << (char)192;
				for (int z = 0; z < 19; z++)
				{
					std::cout << (char)196;
				}
				std::cout << (char)217;
				std::cout << std::endl;
				continue;
			}

			for (int j = 0; j < 21; j++)
			{
				if (j == 0)
				{
					std::cout << (char)179;
					continue;
				}
				if (j == 20)
				{
					std::cout << (char)179;
					continue;
				}

				if (i == 2 || i == 4 || i == 6)
				{
					if (j == 3 || j == 8 || j == 13) {

						int zahl = randomValue();
						if (zahl < 10)
							std::cout << " " << zahl;
						else
							std::cout << zahl;

					}
					else
					{
						std::cout << " ";
					}
					if (j == 16)
					{
						std::cout << (char)179;
						break;
					}
				}
				else
				{
					std::cout << " ";
				}
			}
			std::cout << std::endl;
		}
		Sleep(50);
	}
	//mittlere Reihe Weis, äußere grau
}

int Gamble::randomValue()
{
	int random = rand() % 100;
	int symbol = 0;

	if (random < 30)
		symbol = valArray[0];
	else if (random < 50)
		symbol = valArray[1];
	else if (random < 70)
		symbol = valArray[2];
	else if (random < 85)
		symbol = valArray[3];
	else if (random < 94)
		symbol = valArray[4];
	else if (random < 98)
		symbol = valArray[5];
	else
		symbol = valArray[6];

	return symbol;
}


//Funktion Punkte auslesen