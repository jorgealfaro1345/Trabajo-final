#include "Personaje.h"
#include "sstream"
#include "iostream"

//CLASE CREADA
#include "Texto.h"

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

using namespace sf;

Personaje::Personaje()
{
    txt_jugador = new Texture;
    spr_jugador = new Sprite;
    vidas=new int;
    *vidas= 3;
    vidast=new Texto;
}

void Personaje::pers_imagen()
{
    carpeta="Mario";
    imagen="marioderecha";
    imagen2="marioizquierda";
    txt_jugador->loadFromFile("Imagenes/Personaje/"+carpeta+"/"+imagen+".png");
    spr_jugador->setTexture(*txt_jugador);
}

void Personaje::pers_imagen(int x)
{
    carpeta="Luigi";
    imagen="luigiderecha";
    imagen2="luigiizquierda";
    txt_jugador->loadFromFile("Imagenes/Personaje/"+carpeta+"/"+imagen+".png");
    spr_jugador->setTexture(*txt_jugador);
}

void Personaje::pers_imagen(double x)
{
    carpeta="Conyoshi";
    imagen="conyoshiderecha";
    imagen2="conyoshiizquierda";
    txt_jugador->loadFromFile("Imagenes/Personaje/"+carpeta+"/"+imagen+".png");
    spr_jugador->setTexture(*txt_jugador);
}

void Personaje::pers_imagen(std:: string x)
{
    carpeta="Toad";
    imagen="toadderecha";
    imagen2="toadizquierda";
    txt_jugador->loadFromFile("Imagenes/Personaje/"+carpeta+"/"+imagen+".png");
    spr_jugador->setTexture(*txt_jugador);
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void Personaje::agregar_movimiento()
{
    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        x+=3;
        txt_jugador->loadFromFile("Imagenes/Personaje/"+carpeta+"/"+imagen+".png");
    }
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        x-=3;
        txt_jugador->loadFromFile("Imagenes/Personaje/"+carpeta+"/"+imagen2+".png");
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
    y+=dy;// hace q baje el personajeç

    std::stringstream ss;
    ss<<*vidas;
    std::string vidasstr=ss.str();

    vidast->mens_tam_pos("Lifes: "+vidasstr,34,10,653);


}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

Sprite Personaje::devol_spr()
{
    return *spr_jugador;
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void Personaje::posyvidas_iniciales()
{
    x=100,y=100,h=200;
    *vidas= 20;
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

int Personaje::return_vidas()
{
    return *vidas;
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

Text Personaje::devo_vidas()
{
    return vidast->dev_text();
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

Personaje::~Personaje()
{
    delete txt_jugador;
    delete spr_jugador;
}
