#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "gameobject.h"
#include "allegro_utility_object.h"
#include "character.h"
#include "obstacle.h"
#include "boss.h"
#include <math.h>


int main(){

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_BITMAP *image = NULL;
    ALLEGRO_FONT *arial = NULL;
   // ALLEGRO_BITMAP *bob = NULL;
    int obstacleSet;
  //  int bossSet;
    int score = 0;
    obstacle **obstacles = new obstacle*[8];
    obstacles[0] = new obstacle(600.,0.,63.,50.,0.,0.,"number1.bmp");
    obstacles[1] = new obstacle(600.,151,63.,329.,0.,0.,"number2.bmp");
    obstacles[2] = new obstacle(600.,0,71,332,0.,0.,"number3.bmp");
    obstacles[3] = new obstacle(600.,449.,71.,30.,0,0,"number4.bmp");
    obstacles[4] = new obstacle(600.,0.,78.,195.,0.,0.,"number5.bmp");
    obstacles[5] = new obstacle(600.,322.,78.,158.,0,0,"number6.bmp");
    obstacles[6] = new obstacle(600.,0.,66.,116.,0.,0.,"number7.bmp");
    obstacles[7] = new obstacle(600.,256.,64.,224.,0.,0.,"number8.bmp");

    Boss *DJ = new Boss(641.0,240.0,126.0,88.0,0,0,"snake tongue image 1.bmp");

//    GameObject *test = new GameObject(200.,320.,23.,45.,0.,0.,"BOB character art.bmp");


    character *bob2 = new character(100.,100.,23.,45.,0.,0.,"BOB character art.bmp");
    Allegro_Utility_Object test2(640,480);
    DJ->Exiting();

    al_init_image_addon();

    al_init();
    if(!al_init()) {
          printf("failed to initialize allegro!\n");

    }


    image = al_load_bitmap("Background.bmp");
    if(!image) {
      printf( "failed to create image bitmap!\n");
      al_destroy_display(display);
      return -1;
    }
    al_init_font_addon();
    al_init_ttf_addon();
    arial = al_load_ttf_font("arial.ttf", 10, 0);


        bob2->Falling();

        obstacleSet = rand() % 4;

        obstacles[obstacleSet * 2]->draw();
        obstacles[(obstacleSet * 2) + 1]->draw();

    while(true){
        ALLEGRO_EVENT ev;
        al_wait_for_event(test2.getEventQueue(), &ev);


        if(ev.type == ALLEGRO_EVENT_TIMER) {
            test2.setDisplay();
            al_draw_bitmap(image,0,0,0);

    //        test->draw();
            bob2->draw();

            DJ->draw();

            /*
            if(abs(bob2->getXposition() - obstacles[obstacleSet * 2]->getRelativeX()) < 0.01){
                    printf("score!\n");
                score++;
            } */

            if(obstacles[obstacleSet * 2]->checkOffScreen()|| obstacles[(obstacleSet * 2)+1]->checkOffScreen()){
                score++;
                obstacles[obstacleSet * 2]->reset();
                obstacles[(obstacleSet * 2)+1]->reset();
                obstacleSet = rand() % 4;
               // printf("Set %d\n", obstacleSet);

            }

            if(score == 2){
                DJ->Entering();
            }


            obstacles[obstacleSet * 2]->draw();
            obstacles[(obstacleSet * 2) + 1]->draw();

            al_draw_textf(arial,al_map_rgb(0,0,0),325,10,0,"Score :%d",score);
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

        if(obstacles[obstacleSet*2]->isColliding(bob2) || obstacles[(obstacleSet*2)+1]->isColliding(bob2)){
          //  printf("true\n");
        }
   }
   // getchar();


    al_destroy_bitmap(image);
//    delete test;
    delete bob2;
    for( int i = 0; i <8 ; i++){
        delete obstacles[i];
    }
    delete obstacles;
    delete DJ;
    return 0;

}
