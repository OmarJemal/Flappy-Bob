
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include "allegro_utility_object.h"
#include <stdio.h>

Allegro_Utility_Object::Allegro_Utility_Object( int Width,int Height)
{
    al_init();

    width = Width;
    height = Height;

    display = al_create_display(width, height);
    if(!display) {
        printf( "failed to create display!\n");
    }

     if(!al_install_keyboard()) {
          printf( "failed to initialize the keyboard!\n");

       }

    timer = al_create_timer(1.0 / 60);
    if(!timer) {
        printf("failed to create timer!\n");
    }

    event_queue = al_create_event_queue();

    if(!event_queue) {
        printf("failed to create event_queue!\n");
        al_destroy_timer(timer);
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue,al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_start_timer(timer);
}

Allegro_Utility_Object::~Allegro_Utility_Object()
{
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);
    al_destroy_display(display);
}

void Allegro_Utility_Object::setDisplay(){

    al_set_target_backbuffer(display);
    al_clear_to_color(al_map_rgb(0,0,0));

}

void Allegro_Utility_Object::update(){


    al_flip_display();

}

ALLEGRO_EVENT_QUEUE* Allegro_Utility_Object::getEventQueue(){

return event_queue;

}
