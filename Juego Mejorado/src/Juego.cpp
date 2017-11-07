#include "Juego.h"
#include <SFML/Graphics.hpp>
#include <time.h>
#include<cstdlib>
#include <iostream>
using namespace sf;


Juego::Juego(int _ancho, int _alto,std::string _nombre)
{

    srand(time(0));
    fps=80;

    pantalla_de_juego = new RenderWindow(VideoMode(_ancho,_alto), _nombre);

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

    textura2->loadFromFile("marioderecha.png");

    textura3->loadFromFile("3.png");

// almacena el sprite en la textura

    sprite1->setTexture(*textura1);

    sprite2->setTexture(*textura2);

    sprite3->setTexture(*textura3);

//creacion de eventos

    evento1 = new Event;

//inicia el bucle del juego

    srand(time(0));
    pos_rand_plataformas();

    gameloop();//ctor
}

void Juego::gameloop()
{
    while(pantalla_de_juego->isOpen())
    {
        iniciar_eventos();
        agregar_movimiento();
        rebote_plataformas(x ,y ,dy );
        escenario(y, h, dy);
        //game_over(y);


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

    for (int i=0;i<10;i++)
    {
    sprite3->setPosition(plat[i].x,plat[i].y);
    pantalla_de_juego->draw(*sprite3);
    }

    //agregar_plataformas();

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
    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        x+=3;
        textura2->loadFromFile("marioderecha.png");
    }
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        x-=3;
        textura2->loadFromFile("marioizquierda.png");
    }

    if(x>600)
    {
        x=1;
    }

    if(x<0)
    {
        x=600;
    }

    dy+=0.2;//la velocidad en q sube
    y+=dy;// hace q suba el personaje

}


void Juego::pos_rand_plataformas(){
    for(int i = 0; i < 10; i++){
        plat[i].x = std::rand() % 600;
        plat[i].y = std::rand() % 697;
    }
}

// Bounce is initiated when acceleration is downward and doodle is
// touching a platform.
void Juego::rebote_plataformas(int &x, int &y, float &dy){
    for(int i = 0; i < 10; i++)
        if((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 107)
        && (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0))
            dy = -10;
}

void Juego::escenario(int &y, int &h, float &dy)
{
    if(y < h)
    {
        for(int i = 0; i < 10; i++){
            y = h; // doodle's y position set to 200

            plat[i].y = plat[i].y - dy; // all platform y values rerender with dy

        // When a platform goes below the view of the screen, it is redrawn at the
        // top of the screen with a random x coordinate.
            if(plat[i].y > 697){
                plat[i].y = 0;
                plat[i].x = std::rand() %600;
            }
        }
    }
}

/*void Juego::game_over(int &y)
{
    if(y>697)
    {
        Game_Over *perdiste;
                perdiste = new Game_Over(600,697,"Jump Mario!!");
    }
}


/*Juego::~Juego()
{
    //dtor
}*/
