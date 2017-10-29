#include "Velocidad.h"
#include <SFML/Graphics.hpp>
#include "Ventana.h"
#include <time.h>
using namespace sf;

Velocidad::Velocidad(int _ancho, int _alto,int _vel): Ventana(_ancho,_alto)
{
    vel=_vel;
    Game.setFramerateLimit(_vel);
    //ctor
}

