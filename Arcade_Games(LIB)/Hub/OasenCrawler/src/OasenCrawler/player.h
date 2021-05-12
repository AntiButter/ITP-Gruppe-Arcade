#pragma once
#ifndef PLAYER_H
#define PLAYER_H


class player
{
public:
    player(int hp);
    ~player();

    int GetHp();
    void SetHp(int val);

    int GetRelics();
    void SetRelics(int val);

    int GetPx();
    void SetPx(int val);

    int GetPy();
    void SetPy(int val);

    int GetStrength();
    void SetStrength(int val);

    int GetDefense();
    void SetDefense(int val);

    int GetAgility();
    void SetAgility(int val);

    void printStats();

protected:

private:
    int hp;
    int relics;
    int px;
    int py;
    int strength;
    int defense;
    int agility;
};

#endif // PLAYER_H
