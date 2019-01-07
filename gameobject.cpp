
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include "gameobject.h"
GameObject::GameObject(int PosX,int PosY,const char *filename)
{
al_init();
    al_init_image_addon();
    PositionX = PosX;
    PositionY = PosY;
    object = al_load_bitmap(filename);

    if(!object){
        printf("failed to create %s bitmap!\n", filename);
        al_destroy_bitmap(object);
    }

}



GameObject::~GameObject()
{
   //dtor
printf("destructor called");
    al_destroy_bitmap(object);

}



GameObject::getXposition(){

return PositionX;

}

GameObject::getYposition(){

return PositionY;

}

void GameObject::draw(){

//al_init_image_addon();
al_convert_mask_to_alpha(object, al_map_rgb(255,0,255));
al_draw_bitmap(object,PositionY,PositionX,0);

//printf("HIII");
}
