#ifndef MONSTER_H
#define MONSTER_H


class monster
{
public:
    monster(int val1, int val2);
    ~monster();

    int GetHp();
    void SetHp(int val);

    int GetMx();
    void SetMx(int val);

    int GetMy();
    void SetMy(int val);

    void MoveMonster(int px, int py);



protected:

private:
    int hp;
    int mx;
    int my;
};

#endif // MONSTER_H
