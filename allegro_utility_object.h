#ifndef ALLEGRO_UTILITY_OBJECT_H
#define ALLEGRO_UTILITY_OBJECT_H

#include <allegro5/allegro5.h>

class Allegro_Utility_Object
{
    public:
        Allegro_Utility_Object( int Width,int Height);
        virtual ~Allegro_Utility_Object();
        void update();
    //    void showMenu();
   //     void showPopup();
        void setDisplay();
        float getTime();
        ALLEGRO_EVENT_QUEUE* getEventQueue();

    protected:

    private:
        ALLEGRO_DISPLAY *display = NULL;
        ALLEGRO_EVENT_QUEUE *event_queue = NULL;
        ALLEGRO_TIMER *timer = NULL;
        int width;
        int height;
};

#endif // ALLEGRO_UTILITY_OBJECT_H
