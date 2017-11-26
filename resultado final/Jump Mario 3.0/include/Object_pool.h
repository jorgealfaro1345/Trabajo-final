#ifndef OBJECT_POOL_H
#define OBJECT_POOL_H

#include "Recursos.h"

#include <string>
#include <list>
#include <iostream>

using namespace std;


class Object_pool : public Recursos
{
    private:

        list <Recursos*> Recurso;

        static Object_pool* instance;
        Object_pool();

    public:

        static Object_pool* getInstance();
        Recursos* getResource();
        void returnResource(Recursos* object);
};

#endif // OBJECT_POOL_H


/*#include <string>
#include <list>
#include <iostream>

using namespace std;

ObjectPool* ObjectPool::instance = 0;*/
