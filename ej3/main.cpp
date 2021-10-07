#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
using namespace std;

class objeto
{
    private:
        int dato;
        objeto *siguiente;
    public:
        objeto(int);
        int obtener();
        friend class lista;
};

objeto::objeto(int valor)
{
    this->dato=valor;
    this->siguiente=NULL;
}
int objeto::obtener()
{
    return this->dato;
}

class lista
{
    private:
        objeto *primero;
    public:
        lista();
        ~lista();
        void nuevo(int);
        objeto *obtenerprimero();
        objeto *obtenersiguiente(objeto *);
        void recorrer();
};
lista::lista()
{
    this->primero=NULL;
}
lista::~lista()
{
    objeto *aux;
    while(primero!=NULL)
    {
        aux=primero;
        primero=primero->siguiente;
        delete aux;
    }
    primero=NULL;
}
void lista::nuevo(int d)
{
    objeto *nuevo=new objeto(d);

    if(primero==NULL)
    {
        primero=nuevo;
    }
    else
    {
        objeto *aux=primero;
        while(aux->siguiente!=NULL)
        {
            aux=aux->siguiente;
        }
        aux->siguiente=nuevo;
    }
}
objeto *lista::obtenerprimero()
{
    return this->primero;
}
objeto *lista::obtenersiguiente(objeto *d)
{
    return d->siguiente;
}
void lista::recorrer()
{

}

int main()
{
    lista *l=new lista();
    l->nuevo(5);
    l->nuevo(8);
    l->nuevo(11);
    l->nuevo(20);
    l->recorrer();
    system("PAUSE");
    return 0;
}
