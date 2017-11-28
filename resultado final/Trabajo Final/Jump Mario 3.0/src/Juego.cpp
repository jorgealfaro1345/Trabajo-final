#include "Juego.h".
#include "time.h"
#include "sstream"
#include "iostream"

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

//CLASE CREADA
#include "Plataformas.h"
#include "Game_over.h"
#include "Enemigos.h"
#include "Goombas.h"
#include "Koopasv.h"
#include "Menu.h"
#include "Fondo.h"
#include "Sonidos.h"
#include "Puntaje.h"

using namespace sf;

Juego::Juego(int _ancho, int _alto,std::string _nombre, int pers)
{
    srand(time(0));

    pantalla_de_juego = new RenderWindow(VideoMode(_ancho,_alto), _nombre);

    pantalla_de_juego-> setFramerateLimit(80);

    juego_fond=new Fondo("Fondo","Fondo1");

    personaje=new Personaje;

    switch(pers)
    {
        case 1: personaje->pers_imagen(); break;
        case 2: personaje->pers_imagen(1); break;
        case 3: personaje->pers_imagen(0.1); break;
        case 4: personaje->pers_imagen("toad"); break;
    }

    pers2=pers;

    spr_color=new Color;
    *spr_color=personaje->spr_jugador->getColor();

    plat_ladrillos=new Plataformas;
    plat_ladrillos->pos_rand_plataformas();

    enemigos.push_back(enem1);
    enemigos.push_back(enem2);
    enemigos.push_back(enem3);
    enemigos.push_back(enem4);
    enemigos.push_back(enem5);
    enemigos.push_back(enem6);
    enemigos.push_back(enem7);
    enemigos.push_back(enem8);

    for (int i=0;i<4;i++)
    {
        enemigos[i]=new Goombas;
        enemigos[i]->Imagen_sprite();
        enemigos[i]->ex=plat_ladrillos->plat[i].x+i*2;
        enemigos[i]->pos_max=plat_ladrillos->px+107;
    }

    for(int i=4;i<8;i++)
    {
        enemigos[i]=new Koopasv;
        enemigos[i]->Imagen_sprite();
    }

    G_over=new Game_over(puntos);
    puntos=new Puntaje;

    reloj=new Clock;
    tiempo=new float;
    reloj1= new Texto;

    evento1 = new Event;

    gameloop();
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void Juego::gameloop()
{
    while(pantalla_de_juego->isOpen())
    {
        *tiempo=reloj->getElapsedTime().asSeconds();
        std::stringstream ss;
        ss<<*tiempo;
        std::string tiempo1=ss.str();
        reloj1->mens_tam_pos("Time: "+tiempo1,34,10,10);


        iniciar_eventos();

        personaje->agregar_movimiento();

        for(int i=0;i<4;i++)
        {
            enemigos[i]->Movimiento();
        }
        for(int i=4;i<8;i++)
        {
            enemigos[i]->Movimiento();
        }

        plat_ladrillos->rebote_plataformas(personaje->x ,personaje->y ,personaje->dy,pers2);
        plat_ladrillos->escenario(personaje->y, personaje->h, personaje->dy,enemigos);

        for(int i=0;i<4;i++)
        {
            enemigos[i]->Colision(personaje->x ,personaje->y ,personaje->dy,personaje->vidas);
        }
        for(int i=4;i<8;i++)
        {
            enemigos[i]->Colision(personaje->x ,personaje->y ,personaje->dy,personaje->vidas);
        }

        puntos->Puntos(enemigos,plat_ladrillos);

        mostrar_and_setposicion();
    }

}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void Juego::mostrar_and_setposicion()
{
    pantalla_de_juego->clear();

    pantalla_de_juego->draw(juego_fond->dev_spr_fond());

    personaje->spr_jugador->setPosition(personaje->x,personaje->y);
    pantalla_de_juego->draw(personaje->devol_spr());

    for (int i=0;i<10;i++)
    {
        plat_ladrillos->px=plat_ladrillos->plat[i].x;
        plat_ladrillos->py=plat_ladrillos->plat[i].y;
        plat_ladrillos->spr_plat->setPosition(plat_ladrillos->px,plat_ladrillos->py);
        pantalla_de_juego->draw(plat_ladrillos->dev_spr());
    }

    for(int i=0;i<4;i++)
    {
        enemigos[i]->ey=plat_ladrillos->plat[i].y-31;
        enemigos[i]->spr_enemigo->setPosition(enemigos[i]->ex,enemigos[i]->ey);
        pantalla_de_juego->draw(enemigos[i]->devol_spr());
    }

    for(int i=4;i<8;i++)
    {
        enemigos[i]->spr_enemigo->setPosition(enemigos[i]->ex,enemigos[i]->ey);
        pantalla_de_juego->draw(enemigos[i]->devol_spr());
    }

    pantalla_de_juego->draw(puntos->devo_punt());

     if(personaje->y>697||personaje->return_vidas()<1)
    {
        personaje->spr_jugador->setColor(Color::Red);
        personaje->dy=+5;
        pantalla_de_juego->draw(G_over->devo_text());
        reloj->restart();
        pantalla_de_juego->draw(G_over->devo_text(1));
        std::cout<<"Highest score: "<<puntos->Puntaje_alto()<<std::endl;
    }

    pantalla_de_juego->draw(reloj1->dev_text());

    pantalla_de_juego->draw(personaje->devo_vidas());

    pantalla_de_juego->display();

}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

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

        case Event::KeyPressed:
            if(Keyboard::isKeyPressed(Keyboard::Tab))
            {
                personaje->spr_jugador->setColor(*spr_color);
                personaje->posyvidas_iniciales();
                plat_ladrillos->pos_rand_plataformas();
                for (int i=0;i<4;i++)
                {
                    enemigos[i]->ex=plat_ladrillos->plat[i].x+i*2;
                    enemigos[i]->pos_max=plat_ladrillos->px+107;
                    enemigos[i]->devo_puntos_iniciales();
                }
                for (int i=4;i<8;i++)
                {
                    enemigos[i]->pos_enem(enemigos);
                    enemigos[i]->devo_puntos_iniciales();
                }
                plat_ladrillos->punt_palt_inicial();
                break;
            }

            if(Keyboard::isKeyPressed(Keyboard::Escape))
            {
                pantalla_de_juego->close();
                exit(1);
                break;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

Juego::~Juego()
{
    delete pantalla_de_juego;
    delete juego_fond;
    delete personaje;
    delete plat_ladrillos;

    delete enem1;
    delete enem2;
    delete enem3;
    delete enem4;
    delete enem5;
    delete enem6;
    delete enem7;
    delete enem8;

    delete G_over;
    delete puntos;
    delete evento1;
}
