#pragma once
#include <vector>
#include <string>

class Highscores
{
public:
	Highscores();
	~Highscores();

	void loadScores();

	std::string queryFileName();

	void printScores();

	std::vector<std::string> gameNames;

private:
	//Für Name des Spielers Tupel benutzen oder neuer Vektor.
	std::vector<std::string> gameScores;
};

