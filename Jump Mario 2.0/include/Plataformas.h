#ifndef PLATAFORMAS_H
#define PLATAFORMAS_H

//LIBRERIAS DE SFML
#include<SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

#include <iostream>
using namespace sf;


class Plataformas
{
    public:
        Texture *txt_plat;
        Sprite *spr_plat;
        struct point{int x,y;};
        point plat[20];


        Plataformas();
        void pos_rand_plataformas();
        void rebote_plataformas(int &x, int &y, float &dy);
        void escenario(int &y, int &h, float &dy);
        Sprite dev_spr();
        virtual ~Plataformas();

    /*protected:
        Texture *txt_plat;
        Sprite *spr_plat;
        struct point{int x,y;};
        point plat[20];*/

    private:
};

#endif // PLATAFORMAS_H

