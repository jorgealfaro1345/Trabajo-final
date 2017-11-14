#ifndef FONDO_H
#define FONDO_H

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

using namespace sf;

class Fondo
{
    public:
        Sprite *spr_fond;

        Fondo(std::string nombre_carpeta,std::string nombre_imagen);
        Sprite dev_spr_fond();
        virtual ~Fondo();

    private:
        Texture *txt_fond;

};

#endif // FONDO_H
