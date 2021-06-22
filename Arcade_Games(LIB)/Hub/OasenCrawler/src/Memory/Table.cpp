#include "Table.h"
#include <iostream>
#include <random>
#include <Windows.h>
#include <conio.h>
//#include <stdlib.h> 
//#include <algorithm>

Table::Table(int difficulty) {
	switch (difficulty) {
	case 1:
		this->difficulty = 10;
		break;
	case 2:
		this->difficulty = 20;
		break;
	case 3:
		this->difficulty = 30;
		break;
	default:
		this->difficulty = 10;
	}

	shuffleCards();
	curserPos = 0;
	open1 = -1;
	open2 = -1;
	solved = 0;
}

Table::~Table() {

}

void Table::shuffleCards() {
	int z = 0;

	cards.clear();
	for (int i = 1; i <= difficulty; i++) {
		cards.push_back(symbols[z]);
		if (i % 2 == 0) {
			z++;
		}
	}
	auto rng = std::default_random_engine{ std::random_device{}() };
	std::shuffle(std::begin(cards), std::end(cards), rng);
}

void Table::printTable() {
	for (int i = 0; i < difficulty; i++) {
		std::cout << cards[i];
		std::cout << " ";
		if ((i + 1) % 5 == 0) {
			std::cout << std::endl;
		}
	}
}

void Table::printHidden() {
	bool reset = false;

	while (solved < (difficulty/2)) {
		for (int i = 0; i < difficulty; i++) {
			if (cards[i] == ' ') {
				std::cout << ' ';
			}
			else if (open1 == i) {
				std::cout << cards[i];
			}
			else if (open2 == i) {
				std::cout << cards[i];
				reset = true;
			}
			else {
				if (i == curserPos) {
					std::cout << 'X';
				}
				else {
					std::cout << hidden;
				}
			}

			std::cout << " ";
			if ((i + 1) % 5 == 0) {
				std::cout << std::endl;
			}
		}
		if (reset == true) {
			if (cards[open1] == cards[open2]) {
				cards[open1] = ' ';
				cards[open2] = ' ';
				solved++;
			}
			open1 = -1;
			open2 = -1;
			reset = false;
			Sleep(1500);
			system("CLS");
		}
		else {
			std::cout << "Mit 'F' bestaetigen, Cursor mit 'WASD' bewegen" << std::endl;
			movement = _getch();
			switch (movement) {
			case 's':
				if (curserPos < (difficulty - 5)) {
					curserPos += 5;

				}
				break;
			case 'w':
				if (curserPos > 4) {
					curserPos -= 5;
				}
				break;
			case 'a':
				if (curserPos > 0) {
					curserPos--;

				}
				break;
			case 'd':
				if (curserPos < (difficulty-1)) {
					curserPos++;
				}
				break;
			case 'f':
				//open
				break;
			}

			system("CLS");
			if (movement == 'f') {
				if (open1 != -1) {
					if (open1 != curserPos) {
						open2 = curserPos;
					}
				}
				else {
					open1 = curserPos;
				}
			}
			if (open1 != -1 && open2 != -1) {
				//??
			}
		}

	}
		
}
