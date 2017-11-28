#ifndef SONIDOS_H
#define SONIDOS_H

//LIBRERIAS DE SFML
#include<SFML/Audio.hpp>

using namespace sf;

class Sonidos
{
    public:
        Sound sound;
        Sonidos(std::string carpeta,std::string cancion);
        void Reproducir();

        virtual ~Sonidos();

    protected:
        SoundBuffer buffer;
};

#endif // SONIDOS_H
