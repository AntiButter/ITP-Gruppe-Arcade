#pragma once
class Gamble
{
public:
	Gamble();
	~Gamble();

	/*
	const int lowVal1 = 5;
	const int lowVal2 = 10;
	const int lowVal3 = 15;
	const int medVal1 = 30;
	const int medVal2 = 50;
	const int bigVal1 = 200;
	*/

	//Gewinn Multiplikator
	const int valArray[7] = { 1, 2, 5, 10, 20, 30, 50};

	void getPoints();

	void showPoints();

	void savePoints();

	void slotMachine();

	int randomValue();

private:
	int points;
};

