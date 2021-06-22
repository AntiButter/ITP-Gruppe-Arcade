#pragma once
#include <iostream>
#include <string>

class BlackjackCard
{
	public:
		BlackjackCard();
		BlackjackCard(int);
		~BlackjackCard();

		void printBot();
		void printTop();
		void printMiddle();
		void printMiddle(int);
		void print(int);
		int getCardVal();
		void setAceVal();

	private:
		int cardVal;
		std::string cardSymbol;
};

