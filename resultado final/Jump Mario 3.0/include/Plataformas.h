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
        int puntos_plat=0;

        Plataformas();
        void pos_rand_plataformas();
        void rebote_plataformas(int &x, int &y, float &dy, int &ex, int &ey, float &edy);
        void escenario(int &y, int &h, float &dy, std::vector <Enemigos *> enemigos);
        Sprite dev_spr();

        virtual ~Plataformas();

    private:
        Sonidos *snd_salto;
        int snd_num;
        std::string carpeta="Mario";

};

#endif // PLATAFORMAS_H

