#include "Plataformas.h"

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

using namespace sf;

Plataformas::Plataformas()
{
    txt_plat = new Texture;
    spr_plat = new Sprite;
    txt_plat->loadFromFile("Imagenes/Plataformas/Ladrillos.png");
    spr_plat->setTexture(*txt_plat);
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void Plataformas::pos_rand_plataformas()
{
    for(int i = 0; i < 10; i++){
        plat[i].x = std::rand() % 493;
        plat[i].y = std::rand() % 697;
    }
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void Plataformas::rebote_plataformas(int &x, int &y, float &dy)
{
    for(int i = 0; i < 10; i++)
    {
        if((x + 50 > plat[i].x) && (x + 25 < plat[i].x + 107)
        && (y + 73 > plat[i].y) && (y + 73 < plat[i].y + 20) && (dy > 0))
        {
            dy = -10;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void Plataformas::escenario(int &y, int &h, float &dy)
{
    if(y < h)
    {
        for(int i = 0; i < 10; i++)
        {
            y = h;
            plat[i].y = plat[i].y - dy;
            if(plat[i].y > 697)
            {
                plat[i].y = 0;
                plat[i].x = std::rand() %600;
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

Sprite Plataformas::dev_spr()
{
    return *spr_plat;
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

Plataformas::~Plataformas()
{
    delete txt_plat;
    delete spr_plat;//dtor
}