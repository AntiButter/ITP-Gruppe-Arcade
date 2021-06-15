#include "BlackjackGame.h"
BlackjackGame::BlackjackGame(int gamblePoints)
{
	//set to 100 at the beginnen ==> cost of entry also 100 (needs to be set)
	credits = gamblePoints;

	gameloop();

	std::cout << "\nVielen Dank fuers spielen !" << std::endl;
}

BlackjackGame::~BlackjackGame()
{
	delete(emptyCard);
}

std::vector<BlackjackCard*>BlackjackGame::createDeck()
{
	std::vector<BlackjackCard*> temp;

	//4 * 4 decks => 16 * 13 = 208 cards 
	for (int z = 0; z < 4; z++)
	{
		for (int i = 1; i < 14; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				BlackjackCard* card = new BlackjackCard(i);
				temp.push_back(card);
			}
		}
	}

	// obtain a time-based seed:
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine e(seed);

	std::shuffle(temp.begin(), temp.end(), e);

	return temp;
}

void BlackjackGame::gameloop()
{
	char input;
	einsatz = 0;
	do
	{
		//Deck reset
		playCards = createDeck();
		limit = playCards.size();

		//Einsatz
		if (einsatz == 0)
		{
			system("cls");
			std::cout << "Bitte geben Sie ihren Einsatz ein! (derzeit besitzen Sie " << credits << " credits)" << std::endl;
			bool loop = true;
			while (loop)
			{
				try
				{
					std::cin >> einsatz;
					if (std::cin.fail())
						throw 0;
					if (einsatz < 1)
						throw 1;
					if (einsatz > credits)
						throw 2;
					loop = false; // if nothing is thrown, the loop breaks;
				}
				catch (int myNum)
				{
					if (myNum == 0) {
						std::cout << "Bitte geben Sie eine Zahl an!" << std::endl;
						//to flush the input after a wrong input
						std::cin.clear();
						std::cin.ignore(10000, '\n');
					}
					if (myNum == 1)
						std::cout << "Geben Sie eine Zahl groesser als 0 ein !" << std::endl;
					if (myNum == 2)
						std::cout << "Sie besitzen nicht genuegend credits fuer diesen Einsatz !" << std::endl;
				}
			}
		}

		//dealing
		dealPlayer();
		dealPlayer();
		dealDealer();
		dealDealerBack();

		playerRound();

		if (overdraftPlayer == false)
			dealerRound();

		//Frage ob Game vorbei, noch ein game ? Einsatz ?
		std::cout << "Runde vorbei ! ";
		if (win == 1)
		{
			std::cout << "Sie haben gewonnen !" << std::endl;
			credits += einsatz;
		}
		else if (win == 0)
		{
			std::cout << "Sie haben leider verloren :(" << std::endl;
			credits -= einsatz;
		}
		else
		{
			std::cout << "Unentschieden, sie erhalten ihren Einsatz zurueck !" << std::endl;
		}

		std::cout << "Ihr neuer Credit-Stand betraegt " << credits << std::endl;
		if (credits != 0)
		{
			std::cout << "\nWollen Sie noch einmal ihr Glueck versuchen ? \n(y = noch einmal, r = noch einmal mit dem selbem Einsatz (" << einsatz << "), x = nein)" << std::endl;
			std::cin >> input;
			while (input != 'y' && input != 'x' && input != 'r') //und andere valide inputs
			{
				//to flush the input after a wrong input
				std::cin.clear();
				std::cin.ignore(10, '\n');

				std::cout << "Bitte geben Sie einen validen input ein !" << std::endl;
				std::cin >> input;
			}

			if (input == 'y')
				einsatz = 0;

			//Für r kann alles so gelassen werden
		}
		else
		{
			std::cout << "\nSie haben leider all ihre Credits verloren !\nSpiel wird beendet." << std::endl;
			input = 'x';
		}

		clearVector();
		deleteDeck();
	} while (input != 'x');
}

void BlackjackGame::playerRound()
{
	int playerVal;
	char input;
	overdraftPlayer = false;

	while (1)
	{
		system("cls");
		gamePrint();
		playerVal = 0;

		int size = player.size();
		for (int j = 0; j < size; j++)
		{
			playerVal += player[j]->getCardVal();
			if (player[j]->getCardVal() == 1)//ace check
			{
				std::cout << "Sie haben ein ASS gezogen !" << std::endl;
				std::cout << "Bitte waehlen Sie den Wert des Asses aus: 'a' = 1 || 'b' = 11" << std::endl;
				std::cin >> input;
				while (input != 'a' && input != 'b') //und andere valide inputs
				{
					//to flush the input after a wrong input
					std::cin.clear();
					std::cin.ignore(10, '\n');

					std::cout << "Bitte geben Sie einen validen input ein !" << std::endl;
					std::cin >> input;
				}

				if (input == 'b')
				{
					playerVal += 10;	//da schon oben der cardVal von +1 dazugerechnet wurde
					player[j]->setAceVal(); //Überschreibt den Wert der Karte
				}
			}
		}

		std::cout << "Ihr derzeitiger Kartenwert betraegt: " << playerVal << std::endl;

		if (playerVal > 21)
		{
			std::cout << "BUST! Sie haben einen Kartenwert von ueber 21 erreicht" << std::endl;
			win = 0;
			playerCardValGlobal = playerVal;
			overdraftPlayer = true;
			break;
		} 
		else if (playerVal == 21)
		{
			playerCardValGlobal = playerVal;
			break;
		}


		std::cout << "\n'x' = Stand || 'y' = Karte ziehen" << std::endl;
		std::cin >> input;
		while (input != 'x' && input != 'y') //und andere valide inputs
		{
			//to flush the input after a wrong input
			std::cin.clear();
			std::cin.ignore(10, '\n');

			std::cout << "Bitte geben Sie einen validen input ein !" << std::endl;
			std::cin >> input;
		}

		if (input == 'x')
		{
			playerCardValGlobal = playerVal;
			break;
		}

		dealPlayer();
	}
}

void BlackjackGame::dealerRound()
{
	int dealerVal;
	char input;

	dealer.pop_back(); //entfernt die placeholder Karte
	dealDealer();

	while (1)
	{
		system("cls");
		gamePrint();
		dealerVal = 0;

		int size = dealer.size();
		for (int j = 0; j < size; j++)
		{
			dealerVal += dealer[j]->getCardVal();
			if (dealer[j]->getCardVal() == 1)//ace check
			{
				if ((dealerVal + 10) >= 17 && (dealerVal + 10) <= 21)  //falls er durch das ASS = 11 einen Wert über 16 erreicht (und nicht über 21), wird es als 11 gezählt, ansonsten als 1
				{
					dealerVal += 10;
					dealer[j]->setAceVal(); //Überschreibt den Wert der Karte
				}
			}
		}

		std::cout << "Der derzeitige Kartenwert des Dealers betraegt: " << dealerVal << std::endl;

		if (dealerVal > 21)
		{
			std::cout << "BUST! Der Dealer hat einen Kartenwert von ueber 21 erreicht" << std::endl;
			win = 1;
			break;
		}
		else if (dealerVal == 21)
		{
			win = 0;
			break;
		}

		if (dealerVal < 17)	//stand at 17 or above, if at 16 or below dealer will keep drawing
		{
			dealDealer();
			std::cout << "Druecken Sie eine Taste um fortzufahren !" << std::endl;
			_getch();
		}
		else
		{
			if (dealerVal > playerCardValGlobal)
				win = 0;
			else if (dealerVal < playerCardValGlobal)
				win = 1;
			else
				win = 2;

			break;
		}
	}
}

void BlackjackGame::clearVector()
{
	
	int size = player.size();

	for (int j = 0; j < size; j++)
	{
		delete(player[j]);
	}

	size = dealer.size();

	for (int j = 0; j < size-1; j++) //// jetzt nu´r für Testfall 1 weniger, weil empty card nicht gefreed werden soll
	{
		delete(dealer[j]);
	}
	

	player.clear();
	dealer.clear();
}

void BlackjackGame::dealPlayer()
{
	int randomCard = (rand() % limit+1);

	player.push_back(playCards[randomCard]);

	//delete(playCards[randomCard]);
	playCards.erase(playCards.begin() + randomCard);


	limit = playCards.size();
}

void BlackjackGame::dealDealer()
{
	int randomCard = (rand() % limit + 1);

	dealer.push_back(playCards[randomCard]);

	//delete(playCards[randomCard]);
	playCards.erase(playCards.begin() + randomCard);


	limit = playCards.size();
}

void BlackjackGame::dealDealerBack()
{
	int randomCard = (rand() % limit + 1);

	dealer.push_back(emptyCard);
}

void BlackjackGame::gamePrint()
{
	std::cout << "Derzeitger Einsatz: " << einsatz << "\n" << std::endl;
	int size = dealer.size();
	std::cout << "Dealer: "<< std::endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < size; j++)
		{
			dealer[j]->print(i);
		}
		std::cout << std::endl;
	}

	size = player.size();
	std::cout << "\n\nPlayer: " << std::endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < size; j++)
		{
			player[j]->print(i);
		}
		std::cout << std::endl;
	}
}

void BlackjackGame::deleteDeck()
{
	for (int j = 0; j < limit; j++)
	{
		delete(playCards[j]);
	}
}

int BlackjackGame::getCredits()
{
	return credits;
}

