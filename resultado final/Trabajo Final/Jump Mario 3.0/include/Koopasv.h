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
        void Colision(int &px, int &py, float &pdx, int* &vidas);
        Sprite devol_spr();
        int devo_puntos();
        int devo_puntos_iniciales();


        virtual ~Koopasv();
};

#endif // KOOPASV_H
