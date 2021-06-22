#include <iostream>
#include <vector>
#include <memory>
#include <conio.h>
#include "OasenCrawler/OasenCrawler.h"
#include "DeepMiner/DeepMiner.h"
#include "Flottenkampf/Flottenkampf.h"
#include "4wins/4wins.h"
#include "15Puzzle/15Puzzle.h"
#include "Blackjack/Blackjack.h"
#include "HighScores.h"
#include "Gamble.h"

void Breaker()
{
	system("cls");
	std::cout << "Sie haben leider nicht genuegend Punkte um dieses Spiel zu spielen !" << std::endl;
	std::cout << "\nDruecke etwas um fortzufahren!" << std::endl;
	_getch();
}

int main()
{
	//oasenCrawler::PrintMessage();
	//oasenCrawler::PlayOasenCrawler();
	//std::cout << "Fertig";

	std::unique_ptr<Highscores>scores(new Highscores());
	std::unique_ptr<Gamble>gamble(new Gamble());
	
	int selected = 0;
	bool cheatMenu = false;
	char confirm = 'z';
	while (confirm != 'q')
	{
		system("cls");

		std::cout << std::endl << "Waehlen Sie bitte eine Optionen aus: (W = HOCH, S = RUNTER, Y = BESTAETIGEN, Q = BEENDEN)" << std::endl;

		std::cout << std::endl << "     [$ 0] Oasen_Crawler"; selected == 0 ? scores->printScoreSingle(selected) : void();
		std::cout << std::endl << "     [$20] Deep_Miner"; selected == 1 ? scores->printScoreSingle(selected) : void();
		std::cout << std::endl << "     [$99] Flottenkampf"; selected == 2 ? scores->printScoreSingle(selected) : void();
		std::cout << std::endl << "     [$25] 15 Puzzle"; selected == 3 ? scores->printScoreSingle(selected) : void();
		std::cout << std::endl << "     [$ 0] 4 Gewinnt"; selected == 4 ? std::cout << " < -	Zu diesem Spiel gibt es keine Bestenliste !" : std::cout << "";
		//add new games here and increase value for highscore / slot machine
		std::cout << std::endl << "\n     Bestenliste"; selected == 5 ? std::cout << " < -" : std::cout << "";
		std::cout << std::endl << "     Einarmiger Bandit"; selected == 6 ? std::cout << " < -" : std::cout << "";
		std::cout << std::endl << "     Blackjack"; selected == 7 ? std::cout << " < -" : std::cout << "";
		std::cout << std::endl;
		
		gamble->showPoints();

		confirm = _getch();
		if (confirm == 'y')
		{
			if (selected == 0) 
			{ 
				auto vector = oasenCrawler::PlayOasenCrawler(); 
				scores->saveScore(selected, vector[0]); 
				gamble->addPoints(vector[1]);
			} 
			if (selected == 1) 
			{ 
				bool breaker = gamble->pay(20); 
				if (breaker) 
				{ 
					Breaker(); 
					continue;
				}
				auto vector = deepMiner::PlayDeepMiner(); 
				scores->saveScore(selected, vector[0]); gamble->addPoints(vector[1]); 
			}
			if (selected == 2) 
			{ 
				bool breaker = gamble->pay(99); 
				if (breaker)
				{
					Breaker();
					continue;
				}
				auto vector = Flottenkampf::PlayFlottenkampf(); 
				scores->saveScore(selected, vector[0]); 
				gamble->addPoints(vector[1]);
			}
			if (selected == 3) 
			{ 
				bool breaker = gamble->pay(25); 
				if (breaker)
				{
					Breaker();
					continue;
				}
				auto vector = Puzzle15::Play15Puzzle(); 
				scores->saveScore(selected, vector[0]); 
				gamble->addPoints(vector[1]);
			}
			if (selected == 4) {FourWins::PlayFourWins();}
			//add new games here and increase value for highscore / slot machine
			if (selected == 5) { scores->printScores(); }
			if (selected == 6) { gamble->slotMachine(0); }
			if (selected == 7) { int newScore = Blackjack::playBlackjack(gamble->getPoints()); gamble->setPoints(newScore);  }

			std::cout << "\nDruecke etwas um fortzufahren!" << std::endl;
			confirm = _getch();
		}
		if (confirm == 's')
		{
			if (selected != 7) //increase when adding games
				selected++;
			else
				selected = 0;
		}
		else if (confirm == 'w')
		{
			if (selected != 0)
				selected--;
			else
				selected = 7; //increase when adding games
		}
		else if (confirm == 'd')
		{
			std::cout << "\nDa ist ein versteckter hebel. Hebel aktivieren? y/n\n";
			confirm = _getch();
			if (selected = 7 && confirm == 'y')
			{
				std::cout << "\n*Click*";
				cheatMenu = true;
			}
		}

		//clears rest input //falls wir system cls nicht wieder einkommentieren
		/*
		std::cin.clear(); //this and line below are to prevent endless loop on wrong input (letters)
		std::cin.ignore(10, '\n');
		*/
	}
	return 0;
}