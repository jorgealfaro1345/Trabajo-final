#include "Puntaje_Mayor.h"
#include "sstream"
#include "iostream"

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>

//CLASE CREADA
#include "Texto.h"

template <class TipoDato>



Puntaje_Mayor::Puntaje_Mayor(TipoDato _max_punt,TipoDato _punt_act)
{
    max_punt=_max_punt;
    punt_act=_punt_act;
}

TipoDato Puntaje_Mayor<TipoDato>::Mayor()
{
    return (max_punt>punt_act? max_punt: punt_act);
}

Puntaje_Mayor::~Puntaje_Mayor()
{
    //dtor
}
