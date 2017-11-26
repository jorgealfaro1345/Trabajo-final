#ifndef TEXTO_H
#define TEXTO_H

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

using namespace sf;


class Texto
{
    public:
        Texto();
        void mens_tam_pos(std::string Mensaje,int Tamanio,int x,int y);
        Text dev_text();

        virtual ~Texto();

    private:
        Font *fuente1;
        Text *text;
};

#endif // TEXTO_H
