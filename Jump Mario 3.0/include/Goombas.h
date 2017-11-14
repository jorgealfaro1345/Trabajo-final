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
        virtual ~Goombas();
        void Imagen_sprite();
        //void Movimiento();

};

#endif // GOOMBAS_H
