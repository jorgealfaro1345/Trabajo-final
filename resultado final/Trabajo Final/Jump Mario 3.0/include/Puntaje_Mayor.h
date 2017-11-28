#ifndef PUNTAJE_MAYOR_H
#define PUNTAJE_MAYOR_H

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>


using namespace sf;

template <class TipoDato>


class Puntaje_Mayor
{
    public:
        Puntaje_Mayor(TipoDato _max_punt, TipoDato _punt_act);
        TipoDato Mayor();
        virtual ~Puntaje_Mayor();

    private:
        TipoDato max_punt;
        TipoDato punt_act;
};

#endif // PUNTAJE_MAYOR_H
