#ifndef Bots_HEADER
#define Bots_HEADER

#include <vector>

class Bots {
public:
	~Bots();
	virtual std::vector<std::vector<std::vector<int>>> mine(std::vector<std::vector<std::vector<int>>> world) = 0;
	void move(int yLength, int xLength);
	void randMove(int yLength, int xLength);
	int getPosX() const;
	int getPosY() const;
	int getTotalPoints() const;

protected:
	int posX, posY, totalPoints;
};

#endif
