#include "Enemigos.h"

//LIBRERIAS DE SFML
#include<SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

//CLASE CREADA
#include "Plataformas.h"

#include <iostream>
using namespace sf;

Enemigos::Enemigos()
{
    txt_enemigo = new Texture;
    spr_enemigo = new Sprite;
}

void Enemigos::Imagen_sprite()
{
    txt_enemigo->loadFromFile("Imagenes/Personaje/Mario/marioderecha.png");
    spr_enemigo->setTexture(*txt_enemigo); //ctor

}

void Enemigos::vidas()
{
    vida=1;
}

Sprite Enemigos::devol_spr()
{
    return *spr_enemigo;
}



void Enemigos::Movimiento()
{

}

/*Enemigos::~Enemigos()
{
    delete txt_enemigo;
    delete spr_enemigo;//dtor
}*/

