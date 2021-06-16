#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include "Highscores.h"

Highscores::Highscores()
{
	loadScores();
	//printScores();
}

Highscores::~Highscores()
{
}

void Highscores::loadScores()
{
	std::string readText;
	std::fstream MyReadFile("Highscore.txt");

	// Für den ersten Knoten.

	while (getline(MyReadFile, readText))
	{
		gameNames.push_back(readText);
		getline(MyReadFile, readText);
		gameScores.push_back(readText);
		getline(MyReadFile, readText);
		scoreNames.push_back(readText);
	}
	std::cout << std::endl << "Scores loaded successfully." << std::endl;
	MyReadFile.close();
}

void Highscores::printScores()
{
	system("cls");
	std::cout << "Highscores:" << std::endl;
	for (int i = 0; i < gameScores.size(); i++)
	{
		std::cout << "\n" << gameNames[i] << " - " << gameScores[i] << " erzielt von " << scoreNames[i] << std::endl;
	}
}

void Highscores::printScoreSingle(int i)
{
	std::cout << " < -";
	std::cout << "	Highscore: " << gameScores[i] << " erzielt von " << scoreNames[i];
}

void Highscores::saveScore(int gameNumber, int score)
{
	//cancels if score is not higher than previous highscore
	int previousScore = stoi(gameScores[gameNumber]);
	if (previousScore >= score)
		return;

	gameScores[gameNumber] = std::to_string(score);

	char input ;
	char let1 = 'A';
	char let2 = 'A';
	char let3 = 'A';
	int horizontal = 1;

	//um die Färbung zu ermöglichen
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	do
	{
		system("cls");
		std::cout << "\nSie haben einen neuen Highscore erzielt !\n\nBitte geben Sie ihren Namen an: ";
		if (horizontal == 1) { SetConsoleTextAttribute(hConsole, 112); };
		std::cout << let1; SetConsoleTextAttribute(hConsole, 7);
		if (horizontal == 2) { SetConsoleTextAttribute(hConsole, 112); };
		std::cout << let2; SetConsoleTextAttribute(hConsole, 7);
		if (horizontal == 3) { SetConsoleTextAttribute(hConsole, 112); };
		std::cout << let3; SetConsoleTextAttribute(hConsole, 7);
		//let1++;
		input = _getch();

		switch (input) 
		{
			case 'w': 
				switch (horizontal)
				{
					case 1: if (let1 != 'A') { let1--; }; break;
					case 2: if (let2 != 'A') { let2--; } break;
					case 3: if (let3 != 'A') { let3--; } break;
				}	
				break;
			case 's': 		
				switch (horizontal)
				{
					case 1: if (let1 != 'Z') { let1++; }; break;
					case 2: if (let2 != 'Z') { let2++; } break;
					case 3: if (let3 != 'Z') { let3++; } break;
				}		
				break;
			case 'a': if (horizontal != 1) { horizontal--; }; break;
			case 'd': if (horizontal != 3) { horizontal++; }; break;
			default: break;
		}

	} while (input != '\r');

	std::string newName("");
	newName.push_back(let1);
	newName.push_back(let2);
	newName.push_back(let3);

	scoreNames[gameNumber] = newName;

	std::ofstream outfile("Highscore.txt");
	int i = 0;
	while (i < gameNames.size())
	{
		outfile << gameNames[i] << "\n" << gameScores[i] << "\n" << scoreNames[i] << "\n";
		i++;
	}

	outfile.close();
}
