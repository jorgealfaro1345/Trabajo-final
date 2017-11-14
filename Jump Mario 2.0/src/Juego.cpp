#include "Juego.h".

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

//CLASE CREADA
#include "Plataformas.h"
#include "Game_over.h"
#include "Enemigos.h"
#include "Goombas.h"
#include "Menu.h"

#include <iostream>
using namespace sf;


Juego::Juego(int _ancho, int _alto,std::string _nombre)
{
    srand(time(0));
    fps=80;

    pantalla_de_juego = new RenderWindow(VideoMode(_ancho,_alto), _nombre);

    pantalla_de_juego-> setFramerateLimit(fps);

//creacion de terturas

    txt_fondo = new Texture;

//creacion de sprites

    spr_fondo = new Sprite;

//carga una imagen a la textura

    txt_fondo->loadFromFile("Imagenes/Fondo/Fondo.png");

// almacena el sprite en la textura

    spr_fondo->setTexture(*txt_fondo);

    enem1= new Goombas;
    enem1->Imagen_sprite();
    cant_enem=rand()%3;
    G_over=new Game_over;


//sonido

    //buffer_fondo.loadFromFile("jump.wav");
    //sonido.setBuffer(buffer_fondo);
    //fondo.openFromFile("sonidofondo.ogg");
    //fondo.setVolume(60);
//creacion de eventos

    evento1 = new Event;

//inicia el bucle del juego

    plat_ladrillos.pos_rand_plataformas();

    gameloop();//ctor
}

void Juego::gameloop()
{
    while(pantalla_de_juego->isOpen())
    {
        //fondo.play();
        iniciar_eventos();
        Mario.agregar_movimiento();
        plat_ladrillos.rebote_plataformas(Mario.x ,Mario.y ,Mario.dy );
        plat_ladrillos.escenario(Mario.y, Mario.h, Mario.dy);
        for(int i=0;i<cant_enem;i++)
        {
            enem1->Movimiento(plat_ladrillos.plat[i].x,plat_ladrillos.plat[i].y-59);
        }
        //sonido.setVolume(35);
        //sonido.play();*/


        mostrar_and_setposicion();
    }

}



void Juego::mostrar_and_setposicion()
{
    pantalla_de_juego->clear();

    spr_fondo->setPosition(0,0);

    pantalla_de_juego->draw(*spr_fondo);

    Mario.spr_jugador->setPosition(Mario.x,Mario.y);

    pantalla_de_juego->draw(Mario.devol_spr());

    for (int i=0;i<10;i++)
    {
    plat_ladrillos.spr_plat->setPosition(plat_ladrillos.plat[i].x,plat_ladrillos.plat[i].y);
    pantalla_de_juego->draw(plat_ladrillos.dev_spr());

        for(int i=0;i<cant_enem;i++)
        {
            enem1->spr_enemigo->setPosition(plat_ladrillos.plat[i].x,plat_ladrillos.plat[i].y-59);
            pantalla_de_juego->draw(enem1->devol_spr());
        }
    }
    /*for(int i=0;i<rand()%3;i++)
    {
         enem1->spr_enemigo->setPosition(plat_ladrillos.plat[i].x,plat_ladrillos.plat[i].y-59);
         pantalla_de_juego->draw(enem1->devol_spr());
    }*/

    if(Mario.y>697)
    {
        fps=0;
        spr_fondo->setColor(Color::Red);
        pantalla_de_juego->draw(G_over->devo_text());

    }


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



/*Juego::~Juego()
{
    //dtor
}*/
