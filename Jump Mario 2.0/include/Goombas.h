#ifndef GOOMBAS_H
#define GOOMBAS_H

//CLASE CREADA
#include "Enemigos.h"

//LIBRERIAS DE SFML
#include<SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

#include <iostream>
using namespace sf;


class Goombas : public Enemigos
{
    public:
        Goombas();
        virtual ~Goombas();
        void Imagen_sprite();
        void Movimiento(int x,int y);

    protected:

    private:
};

#endif // GOOMBAS_H
