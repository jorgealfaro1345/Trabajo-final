#include "Jugador.h"
#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

Jugador::Jugador()
{
    Texture t1;
    t1.loadFromFile("imagenes\jugador\mario saltando.png");
    Sprite sBackground(t1);//ctor
}
