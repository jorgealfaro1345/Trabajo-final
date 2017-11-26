#include "Personaje.h"

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

using namespace sf;

Personaje::Personaje()
{
    txt_jugador = new Texture;
    spr_jugador = new Sprite;
    txt_jugador->loadFromFile("Imagenes/Personaje/Mario/marioderecha.png");
    spr_jugador->setTexture(*txt_jugador);
    vidas=3;
}

/*Personaje::Personaje(int x);

Personaje::Personaje(float x);

Personaje::Personaje(char x);*/

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void Personaje::agregar_movimiento()
{
    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        x+=3;
        txt_jugador->loadFromFile("Imagenes/Personaje/Mario/marioderecha.png");
    }
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        x-=3;
        txt_jugador->loadFromFile("Imagenes/Personaje/Mario/marioizquierda.png");
    }
    if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        y-=50;
    }

    if(x>600)
    {
        x=1;
    }

    if(x<0)
    {
        x=600;
    }

    dy+=0.2;//la velocidad en q baja
    y+=dy;// hace q baje el personaje

}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

Sprite Personaje::devol_spr()
{
    return *spr_jugador;
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void Personaje::pos_iniciales()
{
    x=100,y=100,h=200;
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

Personaje::~Personaje()
{
    delete txt_jugador;
    delete spr_jugador;
}
