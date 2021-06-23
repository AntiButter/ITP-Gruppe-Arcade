#include "Memory.h"
#include <iostream>
#include "Table.h"
#include <windows.h>

namespace memory {
	void PlayMemory() {
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

	}

}