#include "character.h"
#include <stdio.h>
#include <math.h>


character::character(float PosX,float PosY,float width, float height,float velX, float velY, const char *filename): GameObject(PosX,PosY,width,height, velX,  velY,filename)
{
 printf("constructed");
 isFalling = true;
 isJumping = false;
 distance = 4.0;
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
        distance = 4.0;


    }else if(isJumping){
        distance += 0.1;
        PositionY += int((sin(distance) + cos(distance)) * 8);

         velocityY = 0.8;
        if(distance >= 5.5){
          //  distance = 4.0;
            Falling();

        }

       // PositionY += velocityY;
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
//velocityY= -2;
}
