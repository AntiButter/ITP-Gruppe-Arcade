#include <iostream>
#include "BlackjackGame.h"

namespace Blackjack 
{
	int playBlackjack(int gamblePoints)
	{
		srand(time(NULL));

		std::unique_ptr<BlackjackGame>game(new BlackjackGame(gamblePoints));

		gamblePoints = game->getCredits();

		return gamblePoints;
	}
}

