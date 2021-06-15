#include <iostream>
#include <vector>
#include <memory>
#include "OasenCrawler/OasenCrawler.h"
#include "DeepMiner/DeepMiner.h"
#include "Flottenkampf/Flottenkampf.h"
#include "4wins/4wins.h"
#include "HighScores.h"
#include "Gamble.h"
#include "Memory/Memory.h"

int main()
{
	//oasenCrawler::PrintMessage();
	//oasenCrawler::PlayOasenCrawler();
	//std::cout << "Fertig";

	std::unique_ptr<Highscores>scores(new Highscores());
	std::unique_ptr<Gamble>gamble(new Gamble());
	
	int selected = 0;
	char confirm = 'z';
	bool back = false;
	while (confirm != 'q')
	{
		system("cls");
		if (back == true) {
			std::cout << "WELCOME BACK" << std::endl;
			back = false;
		}
		std::cout << std::endl << "Select Game: (W = UP, S = DOWN, Y = CONFIRM, Q = QUIT)" << std::endl;

		std::cout << std::endl << "     Oasen_Crawler"; selected == 0 ? scores->printScoreSingle(selected) : void();
		std::cout << std::endl << "     Deep_Miner"; selected == 1 ? scores->printScoreSingle(selected) : void();
		std::cout << std::endl << "     Flottenkampf"; selected == 2 ? scores->printScoreSingle(selected) : void();
		std::cout << std::endl << "     4 Gewinnt"; selected == 3 ? scores->printScoreSingle(selected) : void();
		std::cout << std::endl << "     Fight_Club"; selected == 4 ? scores->printScoreSingle(selected) : void();
		std::cout << std::endl << "     Memory"; selected == 5;
		//add new games here and increase value for highscore / slot machine
		std::cout << std::endl << "     Show Highscores"; selected == 6 ? std::cout << " < -" : std::cout << "";
		std::cout << std::endl << "     Slot Machine"; selected == 7 ? std::cout << " < -" : std::cout << "";
		std::cout << std::endl;

		gamble->showPoints();

		confirm = getchar();
		if (confirm == 'y')
		{
			if (selected == 0) { auto vector = oasenCrawler::PlayOasenCrawler(); scores->saveScore(selected, vector[0]); gamble->addPoints(vector[1]); } //hier noch Abfrage ob score > als bisheriger ==> wenn ja saveScore Funktion
			if (selected == 1) { auto vector = deepMiner::PlayDeepMiner(); scores->saveScore(selected, vector[0]); gamble->addPoints(vector[1]);  }
			if (selected == 2) { auto vector = Flottenkampf::PlayFlottenkampf(); scores->saveScore(selected, vector[0]); gamble->addPoints(vector[1]);  }
			if (selected == 3) {FourWins::PlayFourWins();}
			if(selected == 4) { std::cout << "**Content will be available soon**"; }
			if (selected == 5) { memory::PlayMemory(); }
			//add new games here and increase value for highscore / slot machine
			if (selected == 6) { scores->printScores(); }
			if (selected == 7) { gamble->slotMachine(0); }
			confirm = getchar();
			std::cout << "\nPress Enter to continue" << std::endl;
			confirm = getchar();
			back = true;
		}
		if (confirm == 's')
		{
			if (selected != 6) //increase when adding games
				selected++;
			else
				selected = 0;
		}
		else if (confirm == 'w')
		{
			if (selected != 0)
				selected--;
			else
				selected = 6; //increase when adding games
		}

		//clears rest input //falls wir system cls nicht wieder einkommentieren
		/*
		std::cin.clear(); //this and line below are to prevent endless loop on wrong input (letters)
		std::cin.ignore(10, '\n');
		*/
	}
	return 0;
}