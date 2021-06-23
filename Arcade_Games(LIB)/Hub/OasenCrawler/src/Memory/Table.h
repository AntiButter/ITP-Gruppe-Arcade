#ifndef Table_HEADER
#define Table_HEADER

#include <vector>
#include <string>
class Table {
public:
	Table(int difficulty);

	~Table();

	void shuffleCards();
	
	void printTable();

	void gameLoop();

	int getTries();

private:
	std::vector<char> cards;
	int difficulty, curserPos, open1, open2, solved, tries;
	char symbols[15] = {char(64), char(35), char(177), char(184), char(206), char(245), char(244), char(241), char(240), char(175), char(36), char(37), char(186), char(246), char(171) };
	char hidden = 254;
	char movement;
};


#endif
