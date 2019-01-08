#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class GameObject
{
    public:

        GameObject(float PosX,float PosY,float width, float height,float velX, float velY, const char *filename);
        virtual ~GameObject();
        float getYposition();
        float getXposition();
        float getRelativeX();
        float getRelativeY();
  //      bool isCollided();

        void draw();
        bool offScreen();
        void setVelocityX(int velX);
        void setVelocityY(int velY);

    protected:
        float velocityX;
        float velocityY;
        float PositionX;
        float PositionY;
        ALLEGRO_BITMAP *object = NULL;
        float RelativeX;
        float RelativeY;
        float Width;
        float Height;
    private:





};


#endif // GAMEOBJECT_H
