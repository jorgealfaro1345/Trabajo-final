#include "Goombas.h"
#include <iostream>

//CLASE CREADA
#include "Enemigos.h"

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

using namespace sf;

Goombas::Goombas() : Enemigos()
{

}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void Goombas::Imagen_sprite()
{

    txt_enemigo->loadFromFile("Imagenes/enemigos/Gombas/Gombas1.png");
    spr_enemigo->setTexture(*txt_enemigo);
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void Goombas::Movimiento()
{
    vel_x+=0.1;
    ex+=vel_x;
    mx=ex+76;
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

Sprite Goombas::devol_spr()
{
    if (vel_x>0)
    {
        txt_enemigo->loadFromFile("Imagenes/enemigos/Gombas/Gombas1.png");
        spr_enemigo->setTexture(*txt_enemigo);
    }
    else if(vel_x<0)
    {
        txt_enemigo->loadFromFile("Imagenes/enemigos/Gombas/Gombas4.png");
        spr_enemigo->setTexture(*txt_enemigo);
    }
    /*else if(ex>ex+107)
    {
        txt_enemigo->loadFromFile("Imagenes/enemigos/Cañones/Bala1.png");
        spr_enemigo->setTexture(*txt_enemigo);
    }*/

    return *spr_enemigo;
}


///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void Goombas::Colision(int &px, int &py, float &pdx)
{

    if((px + 50 > ex) && (px + 25 < ex + 29)
    && (py + 73 > ey) && (py + 73 < ey + 31) && (pdx > 0))
    {
        std::cout<<"colision"<<std::endl;
        puntos_enem+=0.8;
        txt_enemigo->loadFromFile("Imagenes/enemigos/Gombas/goombadead.png");
        pdx = -10;
    }
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

Goombas::~Goombas()
{
    delete txt_enemigo;
    delete spr_enemigo;

}
