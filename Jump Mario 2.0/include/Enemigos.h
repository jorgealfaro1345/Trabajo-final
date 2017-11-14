#ifndef ENEMIGOS_H
#define ENEMIGOS_H

//CLASES CREADAS
#include "Plataformas.h"

//LIBRERIAS DE SFML
#include<SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

#include <iostream>
using namespace sf;

class Enemigos :public Plataformas
{
    public:
        Texture *txt_enemigo;
        Sprite *spr_enemigo;
        int num_enem ;
        Enemigos();
        virtual void vidas();
        virtual void Imagen_sprite();
        virtual void Movimiento();
        virtual Sprite devol_spr();

        /*virtual ~Enemigos();*/

    protected:
        //struct point{int x,y;};
        int enem_x,enem_y,enem_h;
        float ex,ey;
        int vida;


    private:
};

#endif // ENEMIGOS_H
