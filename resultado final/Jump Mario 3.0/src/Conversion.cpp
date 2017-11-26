#include "Conversion.h"

#include "sstream"
#include "iostream"

//LIBRERIAS DE SFML
#include <SFML/Graphics.hpp>

Conversion::Conversion()
{



}

std::string Conversion::retornar(int x)
{
    std::stringstream ss;
    ss<<x;
    std::string x=ss.str();
    return x;
}

Conversion::~Conversion()
{

}
