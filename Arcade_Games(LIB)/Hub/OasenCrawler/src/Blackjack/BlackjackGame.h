#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <time.h>
#include <chrono>
#include <conio.h>
#include "BlackjackCard.h"
#include "BlackjackGame.h"

class BlackjackGame
{
	public:
		BlackjackGame(int gamblePoints);
		~BlackjackGame();
		std::vector<BlackjackCard*>createDeck();
		void gameloop();
		void playerRound();
		void dealerRound();
		void clearVector();
		void dealPlayer();
		void dealDealer();
		void dealDealerBack();
		void gamePrint();
		void deleteDeck();
		int getCredits();

	private:
		int credits;
		int limit;
		bool overdraftPlayer;
		int playerCardValGlobal;
		int win; //kein bool, da 3 Möglichkeiten // 0 = loss // 1 = win // 2 = tie
		int einsatz;

		//create empty card
		BlackjackCard* emptyCard = new BlackjackCard();
		std::vector<BlackjackCard*>playCards;
		std::vector<BlackjackCard*>player;
		std::vector<BlackjackCard*>dealer;

};

