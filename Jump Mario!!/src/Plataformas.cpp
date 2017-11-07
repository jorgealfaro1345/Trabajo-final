#include "Plataformas.h"
#include "Juego.h"
#include <SFML/Graphics.hpp>
#include <time.h>
#include<cstdlib>
#include <iostream>
using namespace sf;

Plataformas::Plataformas()
{
    point plat[20];
    srand(time(0));

    textura3 = new Texture;
    sprite3 = new Sprite;
    textura3->loadFromFile("3.png");

    for (int i=0;i<10;i++)//
      {//

        plat[i].x=rand()%593;
        plat[i].y=rand()%677;//posiciones vertical horizontal
      }
    dy+=0.2;
    if (y<h)//condicion para q se mueva elescenario
    for (int i=0;i<10;i++)//
    {//
      y=h;//hace q el escenario siga al personaje(escenario infinito)
      plat[i].y=plat[i].y-dy;//lo hace q sea preciso y no igual al personaje, q pase la pos_alt(escenario infinito)
      if (plat[i].y>697) {plat[i].y=0; plat[i].x=rand()%600;}//a medida de que subes crea plataformas
    }

    for (int i=0;i<11;i++)
    {
        if ((x+50>plat[i].x) && (x+20<plat[i].x+107) &&(y+70>plat[i].y) && (y+70<plat[i].y+14) && (dy>0)){
            dy=-10;//para que rebote en plataformas
        }
    }

    for (int i=0;i<10;i++)
    {
    sprite3->setPosition(plat[i].x,plat[i].y);
    pantalla_de_juego->draw(*sprite3);
    }//ctor
}

