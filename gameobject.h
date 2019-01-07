#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class GameObject
{
    public:

        GameObject(int PosX,int PosY,const char *filename);
        virtual ~GameObject();
        int getYposition();
        int getXposition();
  //      bool isCollided();
  //      void falling();
  //      void jump();
        void draw();

    protected:

    private:
        ALLEGRO_BITMAP *object = NULL;
        int PositionX;
        int PositionY;
        int velocityX;
        int velocityY;
        int RelativeX;
        int RelativeY;

};

#endif // GAMEOBJECT_H
