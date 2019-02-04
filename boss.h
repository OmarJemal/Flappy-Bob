#ifndef BOSS_H
#define BOSS_H
#include "character.h"

class Boss : protected character
{
    public:
        Boss(float PosX,float PosY,float width, float height,float velX, float velY, const char *filename);
        virtual ~Boss();
        void Entering();
        void Exiting();
        void draw();
        float getYposition();
        float getXposition();
        float getRelativeX();
        float getRelativeY();
        void setPosX(float PosX);
        void setPosY(float PosY);

    protected:

    private:
        int health;
        bool isEntering;
        bool isExiting;
};

#endif // BOSS_H
