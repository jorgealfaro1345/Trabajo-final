#include "Juego.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Juego::Juego(int _ancho, int _alto,std::string _nombre)
{
    fps=60;

    ventana1 = new RenderWindow(VideoMode(_ancho,_alto), _nombre);

    ventana1-> setFramerateLimit(fps);

    gameloop();//ctor
}

void Juego::gameloop()
{
    while(ventana1->isOpen()){
          mostrar();
          }

}



void Juego::mostrar()
{
    ventana1->clear();

    ventana1->display();
}
