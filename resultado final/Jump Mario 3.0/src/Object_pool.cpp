#include "Object_pool.h"

#include <string>
#include <list>
#include <iostream>

using namespace std;

Object_pool::Object_pool()
{

}

static Object_pool::Object_pool* getInstance()
{
    if (instance == 0)
    {
        instance = new Object_pool;
    }
    return instance;
}

Resource  Object_pool::getResource()
{
    if (resources.empty())
    {
        cout << "Creating new." << endl;
        return new Recursos;
    }
    else
    {
        cout << "Reusing existing." << endl;
        Recursos* Recurso = Recursos.front();
        Recursos.pop_front();
        return Recurso;
    }
}

void Object_pool::returnResource(Recursos* object)
{
    object->reset();
    Recursos.push_back(object);
}

Object_pool::~Object_pool()
{
    //dtor
}
