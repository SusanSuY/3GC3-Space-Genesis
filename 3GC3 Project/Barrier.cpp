/*
3GC3 Final Project - Space Genesis

David Hobson / hobsondd / 001412317
Jack Snopek / snopekjt / 001408851
Susan Yuen / yuens2 / 001416198
Thien Trandinh / trandit / 001420634
*/

#include "Barrier.h"

//constructor for barrier; requires an initial position
Barrier::Barrier(float positionX, float positionY, float positionZ) : GameObject(positionX, positionY, positionZ)
{
    hp = 4;     //intially set hp of barrier to max hp (which is 4)
    isDead = false;
}

int Barrier::getHp()
{
    return hp;
}

//decreases hp of barrier by 1
void Barrier::decreaseHp()
{
    hp--;

    if (hp <= 0)
    {
        isDead = true;
    }
}

void Barrier::drawBarrier()
{
    if (!isDead)
    {
        glPushMatrix();
        glTranslatef(position[0], position[1], position[2]);
        glutSolidCube(1);
        glPopMatrix();
    }
}

bool Barrier::isHit(float x, float y, float z)
{
    if (isDead)
    {
        return false;
    }

    if (position[0] < x-0.5 || position[0] > x+0.5)
    {
        return false;
    }

    if (position[1] < y-0.5 || position[1] > y+0.5)
    {
        return false;
    }

    return true;
}
