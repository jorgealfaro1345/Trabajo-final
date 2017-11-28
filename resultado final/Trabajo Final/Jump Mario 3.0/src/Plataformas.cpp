#include "Plataformas.h"
#include "sstream"
#include "iostream"
#include "time.h"

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

//CLASE CREADA
#include "Sonidos.h"

using namespace sf;

Plataformas::Plataformas()
{
    puntos_plat=new double;
    *puntos_plat=0.0;
    txt_plat = new Texture;
    spr_plat = new Sprite;
    txt_plat->loadFromFile("Imagenes/Plataformas/Ladrillos.png");
    spr_plat->setTexture(*txt_plat);
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void Plataformas::pos_rand_plataformas()
{
    srand(time(NULL));

    for(int i = 0; i < 10; i++)
    {
        plat[i].x = rand() % 493;
        plat[i].y = rand() % 697;
    }
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void Plataformas::rebote_plataformas(int &x, int &y, float &dy, int pers)
{
    for(int i = 0; i < 10; i++)
    {
        if((x + 50 > plat[i].x) && (x + 25 < plat[i].x + 107)
        && (y + 73 > plat[i].y) && (y + 73 < plat[i].y + 20) && (dy > 0))
        {

            *puntos_plat+=0.55;
            std::cout<<*puntos_plat<<std::endl;

            int r;
            switch(pers)
            {
                case 1: r=6;  carpeta="Mario"; break;
                case 2: r=9;  carpeta="Luigi"; break;
                case 3: r=9;  carpeta="Yoshi"; break;
                case 4: r=4;  carpeta="Toad"; break;
            }
            srand(time(NULL));
            snd_num=rand()%(r) + 1;

            std::stringstream ss;
            ss<<snd_num;
            std::string num_snd=ss.str();

            std::string snd="salto"+ num_snd ;
            snd_salto=new Sonidos(carpeta,snd);
            snd_salto->Reproducir();

            dy = -10;
        }

    }
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void Plataformas::escenario(int &y, int &h, float &dy, std::vector <Enemigos *> enemigos)
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
                plat[i].x = rand() %493;
            }
        }
    for(int i=4;i<8;i++)
    {
        y = h;
        enemigos[i]->mx-=dy;
        if(enemigos[i]->ey>697)
        {
            enemigos[i]->ex = rand() % 493;
            enemigos[i]->ey = (rand() %100) -100;
            enemigos[i]->mx=enemigos[i]->ey+10;
        }
    }

//possicion de enemigos tras posicionar de nuevo la plataforma

        for (int i=0;i<4;i++)
        {
            enemigos[i]->ex=plat[i].x+76;
            enemigos[i]->vel_x= -4;
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

double Plataformas::punt_plat_return()
{
    return *puntos_plat;
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

double Plataformas::punt_palt_inicial()
{
    *puntos_plat=0.0;
    return *puntos_plat;
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

Plataformas::~Plataformas()
{
    delete txt_plat;
    delete spr_plat;
}
