#ifndef CHARACTER_H
#define CHARACTER_H

#include "gameobject.h"


class character : public GameObject
{
    public:
        character(int PosX,int PosY,int width, int height,int velX, int velY, const char *filename);

        virtual ~character();
        void draw();
        void Falling();
        void Jump();

    protected:
        bool isFalling;
        bool isJumping;
    private:

};

#endif // CHARACTER_H
