#ifndef ENEMIGOS_H
#define ENEMIGOS_H

//CLASES CREADAS
#include "Plataformas.h"

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

using namespace sf;

class Enemigos :public Plataformas
{
    public:
        Texture *txt_enemigo;
        Sprite *spr_enemigo;
        Enemigos();
        virtual void vidas();
        virtual void Imagen_sprite();
        //virtual void Movimiento();
        virtual Sprite devol_spr();

        /*virtual ~Enemigos();*/

    protected:
        int enem_x,enem_y,enem_h;
        float ex,ey;
        int vida;


    private:
};

#endif // ENEMIGOS_H
