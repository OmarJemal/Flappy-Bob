#ifndef CHARACTER_H
#define CHARACTER_H

#include "gameobject.h"


class character : public GameObject
{
    public:
        character(float PosX,float PosY,float width, float height,float velX, float velY, const char *filename);

        virtual ~character();
        void draw();
        void Falling();
        void Jump();

    protected:
        bool isFalling;
        bool isJumping;
        float distance;
    private:

};

#endif // CHARACTER_H
