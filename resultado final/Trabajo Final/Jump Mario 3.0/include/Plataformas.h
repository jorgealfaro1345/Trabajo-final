#ifndef PLATAFORMAS_H
#define PLATAFORMAS_H

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

//CLASE CREADA
#include "Sonidos.h"
#include "Enemigos.h"
class Enemigos;

using namespace sf;


class Plataformas
{
    public:
        Texture *txt_plat;
        Sprite *spr_plat;
        struct point{int x,y;};
        point plat[20];
        int px,py;
        double *puntos_plat;

        Plataformas();
        void pos_rand_plataformas();
        void rebote_plataformas(int &x, int &y, float &dy, int pers);
        void escenario(int &y, int &h, float &dy, std::vector <Enemigos *> enemigos);
        Sprite dev_spr();
        double punt_plat_return();
        double punt_palt_inicial();

        virtual ~Plataformas();

    private:
        Sonidos *snd_salto;
        int snd_num;
        std::string carpeta;

};

#endif // PLATAFORMAS_H

