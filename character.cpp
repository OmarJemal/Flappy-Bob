#include "character.h"
#include <stdio.h>


character::character(float PosX,float PosY,float width, float height,float velX, float velY, const char *filename): GameObject(PosX,PosY,width,height, velX,  velY,filename)
{
 printf("constructed");
 isFalling = true;
 isJumping = false;
    //ctor
}

character::~character()
{

}

void character::draw(){
    al_convert_mask_to_alpha(object, al_map_rgb(255,0,255));
    al_draw_bitmap(object,PositionX,PositionY,0);

    if(isFalling){
        PositionY += velocityY;
        velocityY += 0.05;


    }else if(isJumping){
        PositionY += velocityY;
       // velocityY += -0.05;
    }

   RelativeY = PositionY + Height;

}

void character::Falling(){

//printf("%f\n",PositionY);


isJumping = false;
isFalling = true;
//velocityY = 2;
}

void character::Jump(){

//   printf("%f\n",RelativeY);

isFalling = false;
isJumping = true;
velocityY= -2;
}
