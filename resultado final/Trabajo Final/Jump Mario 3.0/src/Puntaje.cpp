#include "Puntaje.h"
#include "sstream"
#include "iostream"

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

//CLASE CREADA
#include "Texto.h"
#include "Enemigos.h"
#include "Plataformas.h"


using namespace sf;

template <typename T, typename U>
U sum(T a, U b)
{
    return a + b;
}


template <typename W>
W mayor(W a, W b)
{
    return (a > b ? a : b);
}


Puntaje::Puntaje()
{
    punt_pantalla=new Texto;
    score=new int;
    max_score=new int;
    *max_score=0;
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void Puntaje::Puntos(std::vector<Enemigos *> enemigos,Plataformas* x)
{
    for(int i=0;i<8;i++)
    {
        double xp= x->punt_plat_return();
        int cp= enemigos[i]->devo_puntos();
        //std::cout<<"xp : "<<cp<<std::endl;
        *score=sum(xp,cp);
    }

    std::stringstream ss;
    ss<<*score;
    std::string punt_pantext=ss.str();

    punt_pantalla->mens_tam_pos("Cuerrent score: "+punt_pantext,34,350,20);
}

int Puntaje::Puntaje_alto()
{
    *max_score=mayor(*score,*max_score);
    return *max_score;
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

Text Puntaje::devo_punt()
{
    return punt_pantalla->dev_text();
}

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

Puntaje::~Puntaje()
{
    delete punt_pantalla;
}

