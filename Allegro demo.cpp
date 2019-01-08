#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "gameobject.h"
#include "allegro_utility_object.h"
#include "character.h"
#include "obstacle.h"


int main(){

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_BITMAP *image = NULL;
    ALLEGRO_BITMAP *bob = NULL;

    obstacle **obstacles = new obstacle*[2];
    obstacles[0] = new obstacle(600.,0.,63.,50.,0.,0.,"number1.bmp");
    obstacles[1] = new obstacle(600.,210,63.,329.,0.,0.,"number2.bmp");

    GameObject *test = new GameObject(200.,320.,23.,45.,0.,0.,"BOB character art.bmp");


    character *bob2 = new character(100.,100.,23.,45.,0.,0.,"BOB character art.bmp");
    Allegro_Utility_Object test2(640,480);

    al_init_image_addon();

    al_init();
    if(!al_init()) {
          printf("failed to initialize allegro!\n");

       }


    image = al_load_bitmap("Background.bmp");
       if(!image) {
          fprintf(stderr, "failed to create image bitmap!\n");
          al_destroy_display(display);
          return -1;
       }


        bob2->Falling();

    while(true){
        ALLEGRO_EVENT ev;
        al_wait_for_event(test2.getEventQueue(), &ev);


        if(ev.type == ALLEGRO_EVENT_TIMER) {
        test2.setDisplay();
        al_draw_bitmap(image,0,0,0);

        test->draw();
        bob2->draw();
        obstacles[0]->draw();
        obstacles[1]->draw();
        test2.update();
        /*
        if(bob2.offScreen() && bob2.getYposition() > 400){
            printf("falling : %f\n",bob2.getRelativeY());
            bob2.Jump();
        }else if( bob2.offScreen() && bob2.getYposition() < 80){
        printf("jumping : %f\n",bob2.getRelativeY());
            bob2.Falling();

        }
        */
        /*
        if( bob2->getYposition() > 400){
        //    printf("falling : %f\n",bob2.getRelativeY());
            bob2->Jump();
        }else if(  bob2->getYposition() < 80){
       // printf("jumping : %f\n",bob2.getRelativeY());
            bob2->Falling();
        }
        */
        }
        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }

        if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
            if(ev.keyboard.keycode == ALLEGRO_KEY_SPACE){
                bob2->Jump();
            }
        }

        if(ev.type == ALLEGRO_EVENT_KEY_UP){

            if(ev.keyboard.keycode == ALLEGRO_KEY_SPACE){

                bob2->Falling();
            }
        }

        if(obstacles[0]->isColliding(bob2) || obstacles[1]->isColliding(bob2)){
            printf("true\n");
        }
   }
   // getchar();


    al_destroy_bitmap(image);
    delete test;
    delete bob2;
    delete obstacles[0];
    delete obstacles[1];


    return 0;

}
