#include "Ventana.h"
#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

Ventana::Ventana(int _ancho,int _alto,int _vel)
{
    ancho=_ancho;
    alto=_alto;
    vel=_vel;
    RenderWindow Game(VideoMode(_ancho,_alto),"Jump Mario!!");
    Game.setFramerateLimit(_vel);
    while(Game.isOpen()){
        Event x;
        while(Game.pollEvent(x)){
                if(x.type==Event::Closed){
                Game.close();
                }
            }
    }

    //ctor
}

