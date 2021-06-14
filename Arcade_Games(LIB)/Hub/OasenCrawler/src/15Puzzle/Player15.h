#pragma once
#ifndef Player15_HEADER
#define Player15_HEADER
#include <vector>

class Player15 {
public:
	Player15();
	~Player15();

	void SetPx(int px);
	int GetPx() const;
	void SetPy(int py);
	int GetPy() const;

	int move(std::vector<std::vector<int>>& puzzle);
	void swap(std::vector<std::vector<int>>& puzzle, int swapper);


private:
	int px; 
	int py; 
};


#endif