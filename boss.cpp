
#include <stdio.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "character.h"
#include "boss.h"

Boss::Boss(float PosX,float PosY,float width, float height,float velX, float velY, const char *filename) : character(PosX,PosY,width,height, velX,  velY,filename)
{

   //ctor
    health = 100;
    isEntering = false;
    isExiting = false;
    isJumping = true;
    isFalling = false;
}

Boss::~Boss()
{
    //dtor
}

void Boss::draw(){

    al_convert_mask_to_alpha(object,al_map_rgb(255,0,255));
    al_draw_bitmap(object,PositionX,PositionY,0);

    if(isEntering){
        PositionX -= 1;
        RelativeX = PositionX + Width;

        if((640 - PositionX) == (Width + 30)){
            isEntering = false;
        }
    }

    if(isExiting){
        PositionX += 1;
        RelativeX = PositionX + Width;

        if(PositionX > 640){
            isExiting = false;
        }

    }

    if(!isExiting && !isEntering && !offScreen()){

        if(isFalling){
            PositionY += velocityY;
            velocityY = 2;
            RelativeY = PositionY + Height;
        }

        if(isJumping){
            PositionY += velocityY;
            velocityY = -2;
            RelativeY = PositionY + Height;
        }


        if(PositionY < 10){
            PositionY = 10;
            Falling();
        }

        if(RelativeY > 460){
            PositionY = RelativeY - Height;
            Jump();
        }

    }

}


void Boss::Entering(){
    isEntering = true;
}

void Boss::Exiting(){
    isExiting = true;
}
