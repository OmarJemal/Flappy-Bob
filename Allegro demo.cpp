#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "gameobject.h"
#include "allegro_utility_object.h"
#include "character.h"


int main(){

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_BITMAP *image = NULL;
    ALLEGRO_BITMAP *bob = NULL;

    GameObject test(200.,320.,23.,45.,0.,0.,"BOB character art.bmp");


    character bob2(100.,100.,23.,45.,0.,0.,"BOB character art.bmp");
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



    while(true){
        ALLEGRO_EVENT ev;
        al_wait_for_event(test2.getEventQueue(), &ev);


        if(ev.type == ALLEGRO_EVENT_TIMER) {
        test2.setDisplay();
        al_draw_bitmap(image,0,0,0);

        test.draw();
        bob2.draw();
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
        if( bob2.getYposition() > 400){
        //    printf("falling : %f\n",bob2.getRelativeY());
            bob2.Jump();
        }else if(  bob2.getYposition() < 80){
       // printf("jumping : %f\n",bob2.getRelativeY());
            bob2.Falling();
        }

        }
        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }



   }
   // getchar();


    al_destroy_bitmap(image);




    return 0;

}
