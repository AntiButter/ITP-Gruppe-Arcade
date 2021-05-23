#include <iostream>
#include <fstream>
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
	std::string filePath, readText;
	filePath = queryFileName();
	std::fstream MyReadFile(filePath);

	// F�r den ersten Knoten.

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

std::string Highscores::queryFileName()
{	/*
	std::string fileName = "x";
	char check = 'x';
	while (check != 'y')
	{
		std::cout << "Enter Name of save file: ";
		std::cin >> fileName;
		std::cout << "\nIs this correct?" << fileName << " \n[y]/[n]";
		std::cin >> check;
	}

	return fileName;
	*/
	return "Highscore.txt";
}

void Highscores::printScores()
{
	system("cls");
	std::cout << "Highscores:";
	for (int i = 0; i < gameScores.size(); i++)
	{
		std::cout << "\n\n" << gameNames[i] << " - " << gameScores[i] << " erzielt von " << scoreNames[i];
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
	if (previousScore > score)
		return;

	gameScores[gameNumber] = std::to_string(score);
	std::cout << "Sie haben einen neuen Highscore erzielt !\n\nBitte geben Sie ihren Namen ein: ";
	std::cin >> scoreNames[gameNumber];

	std::string filePath = queryFileName();
	std::ofstream outfile(filePath);
	int i = 0;
	while (i < gameNames.size())
	{
		outfile << gameNames[i] << "\n" << gameScores[i] << "\n" << scoreNames[i] << "\n";
		i++;
	}

	outfile.close();
}
