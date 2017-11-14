#include "Goombas.h"

//CLASE CREADA
#include "Enemigos.h"
#include"Juego.h".

//LIBRERIAS DE SFML
#include<SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

#include <iostream>
using namespace sf;

Goombas::Goombas() : Enemigos()
{
    //ctor
}

void Goombas::Imagen_sprite()
{
    txt_enemigo->loadFromFile("Imagenes/enemigos/Gombas/Gombas1.png");
    spr_enemigo->setTexture(*txt_enemigo);
}



void Goombas::Movimiento(int x,int y)
{
    ex+=0.2;
    enem_x+=ex;
    if(enem_x>=x+107)
    {
        txt_enemigo->loadFromFile("Imagenes/enemigos/Gombas/Gombas1.png");
        enem_x-=ex;

    }
    if(enem_x<=x)
    {
        txt_enemigo->loadFromFile("Imagenes/enemigos/Gombas/Gombas4.png");
        enem_x+=ex;

    }

}


Goombas::~Goombas()
{
    //dtor
}
