
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include "gameobject.h"
GameObject::GameObject(float PosX,float PosY,float width, float height,float velX, float velY, const char *filename)
{
    al_init();
    if(!al_init()) {
        printf("failed to initialize allegro!\n");
    }

    al_init_image_addon();
    if(!al_init_image_addon()) {
        printf("failed to initialize allegro image addon!\n");
    }

    PositionX = PosX;
    PositionY = PosY;
    Width = width;
    Height = height;
    RelativeX = PosX + width;
    RelativeY = PosY + height;
    velocityX = velX;
    velocityY = velY;

    object = al_load_bitmap(filename);

    if(!object){
        printf("failed to create %s bitmap!\n", filename);
        al_destroy_bitmap(object);
    }

}



GameObject::~GameObject()
{
   //dtor
printf("deleted\n");
    al_destroy_bitmap(object);

}



float GameObject::getXposition(){

return PositionX;

}

float GameObject::getYposition(){

return PositionY;

}

void GameObject::draw(){

al_init_image_addon();
al_convert_mask_to_alpha(object, al_map_rgb(255,0,255));
al_draw_bitmap(object,PositionY,PositionX,0);


}


bool GameObject::offScreen(){

if(PositionX < 0 || RelativeX > 640 || PositionY < 0 || RelativeY > 480){
    return true;
}
else{
    return false;
}

}

void GameObject::setVelocityX(int velX){

velocityX = velX;
}

void GameObject::setVelocityY(int velY){

velocityY = velY;
}

float GameObject::getRelativeX(){
return RelativeX;

}

float GameObject::getRelativeY(){

return RelativeY;
}


