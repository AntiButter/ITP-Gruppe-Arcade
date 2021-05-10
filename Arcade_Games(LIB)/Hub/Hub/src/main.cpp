#include <iostream>
#include "OasenCrawler.h"
#include "HighScores.h"
#include "Gamble.h"

int main()
{
	//oasenCrawler::PrintMessage();
	//oasenCrawler::PlayOasenCrawler();
	//std::cout << "Fertig";

	Highscores* scores = new Highscores();
	Gamble* gamble = new Gamble();
	
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
		std::cout << std::endl << "     Fight_Club"; selected == 2 ? scores->printScoreSingle(selected) : void();
		std::cout << std::endl << "     Show Highscores"; selected == 3 ? std::cout << " < -" : std::cout << "";
		std::cout << std::endl << "     Slot Machine"; selected == 4 ? std::cout << " < -" : std::cout << "";
		std::cout << std::endl;

		gamble->showPoints();

		confirm = getchar();
		if (confirm == 'y')
		{
			if (selected == 0) { oasenCrawler::PlayOasenCrawler(); scores->saveScore(selected, 500/*returned value*/); } //im Oasencrawler anpassen dass der score returned wird  //hier noch Abfrage ob score > als bisheriger ==> wenn ja saveScore Funktion
			if (selected == 1) { std::cout << "**Content will be available soon**"; }
			if(selected == 2) { std::cout << "**Content will be available soon**"; }
			if (selected == 3) { scores->printScores(); }
			if (selected == 4) { gamble->slotMachine(); }
			confirm = getchar();
			confirm = getchar();
			back = true;
		}
		if (confirm == 's')
		{
			if (selected != 4) //increase when adding games
				selected++;
		}
		else if (confirm == 'w')
		{
			if(selected != 0)
				selected--;
		}

		//clears rest input //falls wir system cls nicht wieder einkommentieren
		/*
		std::cin.clear(); //this and line below are to prevent endless loop on wrong input (letters)
		std::cin.ignore(10, '\n');
		*/
	}
	delete scores;
	delete gamble;
	return 0;
}