#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>
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

	std::cout << (char)218 << "\n" << (char)179 << "\n" << (char)192 << std::endl;

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