#ifndef GOOMBAS_H
#define GOOMBAS_H

//CLASE CREADA
#include "Enemigos.h"

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

using namespace sf;

class Goombas : public Enemigos
{
    public:

        Goombas();
        void Imagen_sprite();
        void Movimiento();
        Sprite devol_spr();
        void Colision(int &px, int &py, float &pdx);

        virtual ~Goombas();
};

#endif // GOOMBAS_H
