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
	while (selected < 3 && confirm != 'q')
	{
		//system("cls");
		std::cout << " WELCOME BACK" << std::endl;
		std::cout << std::endl << "   Select Game: " << std::endl;
		if (selected <= 0)
		{
			selected = 0;
			std::cout << std::endl << "     Oasen_Crawler <-";
			std::cout << std::endl << "     Deep_Miner";
			std::cout << std::endl << "     Fight_Club" << std::endl;
		}
		else if (selected == 1)
		{
			std::cout << std::endl << "     Oasen_Crawler";
			std::cout << std::endl << "     Deep_Miner <-";
			std::cout << std::endl << "     Fight_Club" << std::endl;
		}
		else if (selected >= 2)
		{
			selected = 2;
			std::cout << std::endl << "     Oasen_Crawler";
			std::cout << std::endl << "     Deep_Miner";
			std::cout << std::endl << "     Fight_Club <-";
		}
		confirm = getchar();
		if (confirm == 'y')
		{
			if(selected == 0) { oasenCrawler::PlayOasenCrawler(); }
			if (selected == 1) { std::cout << "**Content will be available soon**"; }
			if(selected == 2) { std::cout << "**Content will be available soon**"; }
			confirm = getchar();
			confirm = getchar();
		}
		if (confirm == 's')
		{
			selected++;
		}
		else if (confirm == 'w')
		{
			selected--;
		}
	}
	delete scores;
	return 0;
}