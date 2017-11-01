#include "Juego.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Juego::Juego(int _ancho, int _alto,std::string _nombre)
{
    fps=60;

    ventana1 = new RenderWindow(VideoMode(_ancho,_alto), _nombre);

    ventana1-> setFramerateLimit(fps);

//creacion de terturas

    textura1 = new Texture;

    textura2 = new Texture;

    textura3 = new Texture;

//creacion de sprites

    sprite1 = new Sprite;

    sprite2 = new Sprite;

    sprite3 = new Sprite;

//carga una imagen a la textura

    textura1->loadFromFile("1.png");

    textura2->loadFromFile("2.png");

    textura3->loadFromFile("3.png");

// almacena el sprite en la textura

    sprite1->setTexture(*textura1);

    sprite2->setTexture(*textura2);

    sprite3->setTexture(*textura3);

    point plat[20];

    for (int i=0;i<10;i++)
      {
       plat[i].x=rand()%400;
       plat[i].y=rand()%533;
      }

//posiciones de inicio de los sprite

    sprite1->setPosition(0,0);

    //sprite2->setPosition(280,615);

    sprite2->setPosition(x,y);

    for (int i=0;i<10;i++)
      {
        sprite3->setPosition(plat[i].x,plat[i].y);
      }

/*     sprite3->setPosition(200,350);*/

    evento1 = new Event;


//inicia el bucle del juego

    gameloop();//ctor
}

void Juego::gameloop()
{
    while(ventana1->isOpen())
    {
        agregar_movimiento();
        iniciar_eventos();
        mostrar();
    }

}



void Juego::mostrar()
{
    ventana1->clear();

    ventana1->draw(*sprite1);

    ventana1->draw(*sprite2);

    ventana1->draw(*sprite3);

    ventana1->display();

}

void Juego::iniciar_eventos()
{
    while(ventana1->pollEvent(*evento1))
    {
        switch(evento1->type)
        {
        case Event::Closed:
            ventana1->close();
            exit(1);
            break;
        }
    }
}


void Juego::agregar_movimiento()
{
    if (Keyboard::isKeyPressed(Keyboard::Right)) x+=3;
    if (Keyboard::isKeyPressed(Keyboard::Left)) x-=3;

    dy+=0.2;//la velocidad en q sube
    y+=dy;// hace q suba el personaje
    if (y>600)  dy=-10;//indica desde donde va a rebotar

    sprite2->setPosition(x,y);//desde el 143 hasta aqui es el salto
}



