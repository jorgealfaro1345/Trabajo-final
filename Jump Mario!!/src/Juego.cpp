#include "Juego.h"
#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;


Juego::Juego(int _ancho, int _alto,std::string _nombre)
{

    fps=80;

    pantalla_de_juego = new RenderWindow(VideoMode(_ancho,_alto), _nombre);

    //menu = new RenderWindow(VideoMode(_ancho,_alto), _nombre);

    pantalla_de_juego-> setFramerateLimit(fps);

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

//creacion de eventos

    evento1 = new Event;


//inicia el bucle del juego

    gameloop();//ctor
}

void Juego::gameloop()
{
    while(pantalla_de_juego->isOpen())
    {
        iniciar_eventos();
        agregar_movimiento();
        agregar_plataformas();

        mostrar_and_setposicion();
    }

}



void Juego::mostrar_and_setposicion()
{
    pantalla_de_juego->clear();

    sprite1->setPosition(0,0);

    sprite2->setPosition(x,y);

    pantalla_de_juego->draw(*sprite1);

    pantalla_de_juego->draw(*sprite2);

    agregar_plataformas();

    pantalla_de_juego->display();

}

void Juego::iniciar_eventos()
{
    while(pantalla_de_juego->pollEvent(*evento1))
    {
        switch(evento1->type)
        {
        case Event::Closed:
            pantalla_de_juego->close();
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
}


void Juego::agregar_plataformas()
{
    srand(time(NULL));
    point plat[20];

    for (int i=0;i<10;i++)//
      {//
       plat[i].x=rand()%593;
       plat[i].y=rand()%677;//posiciones vertical horizontal
      }//


    if (y<h)
    {
        for (int i=0;i<10;i++)//
        {
            y=h;//                escenario infinito
            plat[i].y=plat[i].y-dy;
                if (plat[i].y>697)
                {
                    plat[i].y=0;
                    plat[i].x= rand()%600;
                }//
        }//
    }


    for (int i=0;i<11;i++)
    {
        if ((x+50>plat[i].x) && (x+20<plat[i].x+107) &&(y+70>plat[i].y) && (y+70<plat[i].y+14) && (dy>0)){
            dy=-10;//para que rebote en plataformas
        }
    }

    for (int i=0;i<10;i++)
    {
    sprite3->setPosition(plat[i].x,plat[i].y);
    pantalla_de_juego->draw(*sprite3);
    }
}




