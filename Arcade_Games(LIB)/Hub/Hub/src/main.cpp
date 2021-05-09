#include <iostream>
#include "OasenCrawler.h"
#include "HighScores.h"

int main()
{
	//oasenCrawler::PrintMessage();
	//oasenCrawler::PlayOasenCrawler();
	//std::cout << "Fertig";

	Highscores* scores = new Highscores();
	
	int selected = 0;
	char confirm = 'z';
	bool back = false;
	while (selected < 4 && confirm != 'q')
	{
		system("cls");
		if (back == true) {
			std::cout << "WELCOME BACK" << std::endl;
			back = false;
		}
		std::cout << std::endl << "Select Game: (W = UP, S = DOWN, Y = CONFIRM, Q = QUIT)" << std::endl;

		std::cout << std::endl << "     Oasen_Crawler"; selected == 0 ? scores->printScoreSingle(0) : void();
		std::cout << std::endl << "     Deep_Miner"; selected == 1 ? scores->printScoreSingle(1) : void();
		std::cout << std::endl << "     Fight_Club"; selected == 2 ? scores->printScoreSingle(2) : void();
		std::cout << std::endl << "     Show Highscores"; selected == 3 ? std::cout << " < -" : std::cout << "";
		std::cout << std::endl;

		confirm = getchar();
		if (confirm == 'y')
		{
			if(selected == 0) { oasenCrawler::PlayOasenCrawler(); }
			if (selected == 1) { std::cout << "**Content will be available soon**"; }
			if(selected == 2) { std::cout << "**Content will be available soon**"; }
			if (selected == 3) { scores->printScores(); }
			confirm = getchar();
			confirm = getchar();
			back = true;
		}
		if (confirm == 's')
		{
			if (selected != 3) //increase when adding games
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
	return 0;
}