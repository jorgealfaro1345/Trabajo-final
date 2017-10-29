#ifndef VELOCIDAD_H
#define VELOCIDAD_H
#include "Ventana.h"


class Velocidad : public Ventana
{
    public:
        int vel;
        Velocidad(int _ancho, int _alto,int _vel);

};

#endif // VELOCIDAD_H
