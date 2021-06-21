#pragma once
class Gamble
{
public:
	Gamble();
	~Gamble();



	//Gewinn Multiplikator
	const int valArray[7] = { 1, 2, 5, 10, 25};

	void readPoints();

	int getPoints();

	void setPoints(int);

	void showPoints();

	void savePoints();

	void slotMachine(int);

	int randomValue();

	void winChecker(int*,int*,int*,int);

	void addPoints(int);

	bool pay(int);

private:
	int points;
};

