#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
using namespace std;

class persona
{
    private:
        int edad;
        double altura;
        char *nombre;
    public:
        persona(int,double,char *);
        ~persona();
        void set_edad(int);
        int get_edad();
        void set_altura(double);
        double get_altura();
        void set_nombre(char *);
        char * get_nombre();
        friend void comparar(persona *,persona *);
};

persona::persona(int ed,double alt,char* nom)
{
    this->edad=ed;
    this->altura=alt;
    this->nombre=new char(sizeof(nom));
    strcpy(this->nombre,nom);
}
persona::~persona()
{
    delete[]this->nombre;
}
void persona::set_edad(int ed)
{
    this->edad=ed;
}
int persona::get_edad()
{
    return this->edad;
}
void persona::set_altura(double alt)
{
    this->altura=alt;
}
double persona::get_altura()
{
    return this->altura;
}
void persona::set_nombre(char *nom)
{
    strcpy(this->nombre,nom);
}
char* persona::get_nombre()
{
    return this->nombre;
}
void comparar(persona *a,persona *b)
{
    if(a->edad > b->edad)
        cout<<"el primero es mayor"<<endl;
    else
        cout<<"el segundo es mayor"<<endl;
}
int main()
{
    int x,y;
    cout<<"ingrese su edad: "<<endl;
    cin>>x;
    persona *a=new persona(x,0,(char*)"");
    cout<<"ingrese su edad: "<<endl;
    cin>>y;
    persona *b=new persona(y,0,(char*)"");
    comparar(a,b);
    system("PAUSE");
    return 0;
}
