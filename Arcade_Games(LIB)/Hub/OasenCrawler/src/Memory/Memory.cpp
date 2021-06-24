#include "Memory.h"
#include <iostream>
#include "Table.h"
#include <windows.h>
#include <conio.h>

namespace memory {
	std::vector<int> PlayMemory() {
		int choice;
		std::cout << "Schwierigkeit 1, 2 , 3" << std::endl;
		std::cin >> choice;
		Table* table = new Table(choice);
		
		system("CLS");
		table->printTable();
		Sleep(5000);
		system("CLS");
		table->gameLoop();
		
		std::cout << "Du hast " << table->getTries() << " Versuche mehr gebraucht!" << std::endl;
		_getch();
		
		int points = (100 - table->getTries());
		std::vector<int> vector;
		vector.push_back(points);
		vector.push_back(points);

		return vector;
	}

}