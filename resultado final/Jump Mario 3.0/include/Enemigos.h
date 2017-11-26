#ifndef ENEMIGOS_H
#define ENEMIGOS_H

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

using namespace sf;

class Enemigos
{
    public:
        Texture *txt_enemigo;
        Sprite *spr_enemigo;
        int ex,ey,mx,pos_max;;
        float vel_x=0,vel_y=0;
        float puntos_enem;
        struct point{int ex,ey;};
        point enem[10];
        int cant_enem;

        Enemigos();
        virtual void vidas();
        virtual void Imagen_sprite();
        virtual void Movimiento();
        virtual Sprite devol_spr();
        virtual void Colision(int &px, int &py, float &pdx);
        virtual void pos_enem(std::vector <Enemigos *> enemigos);

        virtual ~Enemigos();

    protected:
        int vida;
};

#endif // ENEMIGOS_H
