#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "gameobject.h"
#include "character.h"

class obstacle : public GameObject
{
    public:
        obstacle(float PosX,float PosY,float width, float height,float velX, float velY, const char *filename);
        virtual ~obstacle();
        void draw();
        void reset();
      //  void collision();
        bool checkOffScreen();
        bool isColliding(character *player);
        void setPosX(float posX);
        void setPosY(float posY);

    protected:

    private:
};

#endif // OBSTACLE_H
