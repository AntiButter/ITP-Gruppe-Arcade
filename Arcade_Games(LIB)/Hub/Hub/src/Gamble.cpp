#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "Gamble.h"

Gamble::Gamble()
{
	readPoints();
}

Gamble::~Gamble()
{

}

void Gamble::readPoints()
{
	std::string pointsString;
	std::fstream MyReadFile("Gamble.txt");

	getline(MyReadFile, pointsString);
	
	points = stoi(pointsString);

	MyReadFile.close();
}

int Gamble::getPoints()
{
	return points;
}

void Gamble::setPoints(int newPoints)
{
	points = newPoints;
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

void Gamble::slotMachine(int einsatz)
{
	//um die Färbung zu ermöglichen
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	//check ob Einsatz nicht größer als Punkte ist bei einer WIederholung
	system("cls");
	if(einsatz != 0 && einsatz > points)
	{
		std::cout << "Sie besitzen leider zu wenig Punkte fuer diesen Einsatz !" << std::endl;
		einsatz = 0;
	}

	if(points == 0)
	{
		std::cout << "Ohne Punkte koennen Sie nicht gamblen! \nBitte spielen Sie zuerst eines unserer tollen Spiele um Punkte zu erlangen !" << std::endl;
		return;
	}

	if (einsatz == 0)
	{
		std::cout << "Bitte geben Sie ihren Einsatz an !" << " (derzeiter Credit - Stand: " << points << ")" << std::endl;
		bool looop = false;
		do
		{
			if(looop == true)
			{
				std::cout << "Fehlerhafte Eingabe! \nSie haben entweder einen falschen Wert eingegeben oder nicht genuegend Punkte dafuer \n(derzeiter Credit-Stand: "<< points << ")"<< std::endl;
				std::cin.clear(); //this and line below are to prevent endless loop on wrong input (letters)
				std::cin.ignore(10, '\n');
			}
			std::cin >> einsatz;
			looop = true;
		} while (einsatz > points || einsatz == 0);
	}

	srand(time(NULL));
	int x = 0;
	bool skip = false;
	int array1[3] = {}, array2[3] = {}, array3[3] = {};

	for (int loop = 0; loop < 51; loop++)
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

						if(loop > 29)
						{
							if (j == 3 && i == 2)
							{
								if (array1[0] == array2[0] && array2[0] == array3[0])
									SetConsoleTextAttribute(hConsole, 10);

								if (array1[0] < 10)
									std::cout << " " << array1[0];
								else
									std::cout << array1[0];
								continue;
							}
							if (j == 3 && i == 4)
							{
								if (array1[1] == array2[1] && array2[1] == array3[1])
									SetConsoleTextAttribute(hConsole, 10);

								if (array1[1] < 10)
									std::cout << " " << array1[1];
								else
									std::cout << array1[1];
								continue;
							}
							if (j == 3 && i == 6)
							{
								if (array1[2] == array2[2] && array2[2] == array3[2])
									SetConsoleTextAttribute(hConsole, 10);

								if (array1[2] < 10)
									std::cout << " " << array1[2];
								else
									std::cout << array1[2];
								continue;
							}
						}

						if (loop > 39)
						{
							if (j == 8 && i == 2)
							{
								if (array2[0] < 10)
									std::cout << " " << array2[0];
								else
									std::cout << array2[0];
								continue;
							}
							if (j == 8 && i == 4)
							{
								if (array2[1] < 10)
									std::cout << " " << array2[1];
								else
									std::cout << array2[1];
								continue;
							}
							if (j == 8 && i == 6)
							{
								if (array2[2] < 10)
									std::cout << " " << array2[2];
								else
									std::cout << array2[2];
								continue;
							}
						}
						//wip
						if (loop > 49)
						{
							if (j == 13 && i == 2)
							{
								if (array3[0] < 10)
									std::cout << " " << array3[0];
								else
									std::cout << array3[0];

								if (array1[0] == array2[0] && array2[0] == array3[0])
									SetConsoleTextAttribute(hConsole, 7);

								continue;
							}
							if (j == 13 && i == 4)
							{
								if (array3[1] < 10)
									std::cout << " " << array3[1];
								else
									std::cout << array3[1];

								if (array1[1] == array2[1] && array2[1] == array3[1])
									SetConsoleTextAttribute(hConsole, 7);

								continue;
							}
							if (j == 13 && i == 6)
							{
								if (array3[2] < 10)
									std::cout << " " << array3[2];
								else
									std::cout << array3[2];

								if (array1[2] == array2[2] && array2[2] == array3[2])
									SetConsoleTextAttribute(hConsole, 7);

								continue;
							}
						}

						int zahl = randomValue();
						if (zahl < 10)
							std::cout << " " << zahl;
						else
							std::cout << zahl;

						if(loop == 29)
						{
							if (j == 3 && i == 2)
								array1[0] = zahl;
							if (j == 3 && i == 4)
								array1[1] = zahl;
							if (j == 3 && i == 6)
								array1[2] = zahl;
						}

						if (loop == 39)
						{
							if (j == 8 && i == 2)
								array2[0] = zahl;
							if (j == 8 && i == 4)
								array2[1] = zahl;
							if (j == 8 && i == 6)
								array2[2] = zahl;
						}

						if (loop == 49)
						{
							if (j == 13 && i == 2)
								array3[0] = zahl;
							if (j == 13 && i == 4)
								array3[1] = zahl;
							if (j == 13 && i == 6)
								array3[2] = zahl;
						}
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
	
	winChecker(array1, array2, array3,einsatz);
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

void Gamble::winChecker(int* array1, int* array2, int* array3, int einsatz)
{
	//Abziehen des Einsatzes
	points -= einsatz;

	bool won = false;

	if (array1[0] == array2[0] && array2[0] == array3[0])
	{
		points += einsatz * array1[0];
		std::cout << "Sie haben "<< einsatz * array1[0]<< " Punkte in Linie 1 gewonnen"<< std::endl;
		won= true;
	}
	if (array1[1] == array2[1] && array2[1] == array3[1])
	{
		points += einsatz * array1[1];
		std::cout << "Sie haben " << einsatz * array1[1] << " Punkte in Linie 2 gewonnen" << std::endl;
		won = true;
	}
	if (array1[2] == array2[2] && array2[2] == array3[2])
	{
		points += einsatz * array1[2];
		std::cout << "Sie haben " << einsatz * array1[2] << " Punkte in Linie 3 gewonnen" << std::endl;
		won = true;
	}

	if(won == false)
		std::cout << "Sie haben leider nichts gewonnen :(" << std::endl;

	savePoints();

	std::cout << "\nIhr neuer Credit-Stand betraegt: " << points << std::endl;

	std::cout << "\nWollen Sie noch einmal ihr Glueck versuchen ? \n(y = noch einmal, r = noch einmal mit dem selbem Einsatz ("<< einsatz <<"), n = nein)" << std::endl;

	std::cin.clear(); //this and line below are to prevent endless loop on wrong input (letters)
	std::cin.ignore(10, '\n');

	char input = getchar();

	while (input != 'y' && input != 'r' && input != 'n')
	{
		std::cout << "Fehler ! Bitte geben Sie einen akzeptierten Input an !" << std::endl;
		getchar();
		input = getchar();
	}

	if (input == 'y')
		slotMachine(0);
	if (input == 'r')
		slotMachine(einsatz);
	if (input == 'n')
		return;
}

void Gamble::addPoints(int plus)
{
	std::cout << "\nSie haben " << plus << " Punkte erhalten!" << std::endl;

	points += plus;
	savePoints();
}
