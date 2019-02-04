#include "obstacle.h"
#include "gameobject.h"
#include "character.h"
#include <stdio.h>
obstacle::obstacle(float PosX,float PosY,float width, float height,float velX, float velY, const char *filename): GameObject(PosX,PosY,width,height, velX,  velY,filename)
{



}

obstacle::~obstacle()
{
    //dtor
}

void obstacle::draw(){

    al_draw_bitmap(object,PositionX,PositionY,0);
    PositionX -= 4;
    RelativeX = PositionX + Width;

   // if(checkOffScreen()){
     //       reset();
     //   }

}

void obstacle::reset(){
PositionX=620;
}

bool obstacle::checkOffScreen(){
    bool isOff = false;

    if(PositionX < 0){
        isOff = true;
        printf("Yes");
    }
    else{
        isOff = false;
    }

    return isOff;
}

bool obstacle::isColliding(character *player){
    bool isOverLapping = true;

    if(player->getYposition() > getRelativeY() ){
        isOverLapping = false;
    }
    if(player->getRelativeY() < getYposition() ){
        isOverLapping = false;
    }

    if(player->getXposition() > getRelativeX()){
        isOverLapping = false;
    }

    if(player->getRelativeX() < getXposition()){
        isOverLapping = false;
    }

return isOverLapping;
}
