#ifndef KOOPASV_H
#define KOOPASV_H

//CLASE CREADA
#include "Enemigos.h"

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

using namespace sf;


class Koopasv : public Enemigos
{
    public:

        Koopasv();
        void Imagen_sprite();
        void Movimiento();
        void pos_enem(std::vector <Enemigos *> enemigos);
        void Colision(int &px, int &py, float &pdx);
        Sprite devol_spr();

        virtual ~Koopasv();
};

#endif // KOOPASV_H
