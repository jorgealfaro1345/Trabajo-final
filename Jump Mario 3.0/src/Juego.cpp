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
#include "Fondo.h"

using namespace sf;


Juego::Juego(int _ancho, int _alto,std::string _nombre)
{
    srand(time(0));
    fps=80;

    pantalla_de_juego = new RenderWindow(VideoMode(_ancho,_alto), _nombre);

    pantalla_de_juego-> setFramerateLimit(fps);

    juego_fond=new Fondo(nombre_carpeta,nombre_fondo);

    Mario=new Personaje;

    plat_ladrillos=new Plataformas;
    plat_ladrillos->pos_rand_plataformas();

    enem1= new Goombas;
    enem1->Imagen_sprite();
    cant_enem=rand()%3+1;


    G_over=new Game_over;


//sonido

    //buffer_fondo.loadFromFile("jump.wav");
    //sonido.setBuffer(buffer_fondo);
    //fondo.openFromFile("sonidofondo.ogg");
    //fondo.setVolume(60);

    evento1 = new Event;

    gameloop();
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void Juego::gameloop()
{
    while(pantalla_de_juego->isOpen())
    {
        //fondo.play();
        iniciar_eventos();
        Mario->agregar_movimiento();
        plat_ladrillos->rebote_plataformas(Mario->x ,Mario->y ,Mario->dy );
        plat_ladrillos->escenario(Mario->y, Mario->h, Mario->dy);
        //G_over->restart(Mario->y);
        //sonido.setVolume(35);
        //sonido.play();*/


        mostrar_and_setposicion();
    }

}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void Juego::mostrar_and_setposicion()
{
    pantalla_de_juego->clear();

    pantalla_de_juego->draw(juego_fond->dev_spr_fond());

    Mario->spr_jugador->setPosition(Mario->x,Mario->y);
    pantalla_de_juego->draw(Mario->devol_spr());

    for (int i=0;i<10;i++)
    {
        plat_ladrillos->spr_plat->setPosition(plat_ladrillos->plat[i].x,plat_ladrillos->plat[i].y);
        pantalla_de_juego->draw(plat_ladrillos->dev_spr());
    }


    for(int i=0;i<cant_enem;i++)
    {
         enem1->spr_enemigo->setPosition(plat_ladrillos->plat[i].x,plat_ladrillos->plat[i].y-29);
         pantalla_de_juego->draw(enem1->devol_spr());
    }


    if(Mario->y>697)
    {
        pantalla_de_juego->draw(G_over->devo_text());
        juego_fond->spr_fond->setColor(Color::Red);
    }


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

        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

/*Juego::~Juego()
{
    //dtor
}*/
