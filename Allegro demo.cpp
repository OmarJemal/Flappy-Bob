#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "gameobject.h"



int main(){
 ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_BITMAP *image = NULL;
ALLEGRO_BITMAP *bob = NULL;
GameObject test(200,200,"BOB character art.bmp");
   al_init_image_addon();


if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }

display = al_create_display(640, 480);
   if(!display) {
      fprintf(stderr, "failed to create display!\n");

      return -1;
   }

image = al_load_bitmap("Background.bmp");
   if(!image) {
      fprintf(stderr, "failed to create image bitmap!\n");
      al_destroy_display(display);
      return -1;
   }

bob = al_load_bitmap("BOB character art.bmp");
if(!bob) {
      fprintf(stderr, "failed to create bob bitmap!\n");
      al_destroy_display(display);
      al_destroy_bitmap(image);
      return -1;
   }





al_convert_mask_to_alpha(bob, al_map_rgb(255,0,255));


   //for(int i = 620;i>0;i--){

    al_set_target_backbuffer(display);
    al_clear_to_color(al_map_rgb(0,0,0));

	al_draw_bitmap(image,0,0,0);
	al_draw_bitmap(bob,0,300,0);
	test.draw();

	al_flip_display();
   //}
getchar();

 //delete test;
al_destroy_bitmap(bob);
al_destroy_bitmap(image);
al_destroy_display(display);

return 0;

}
