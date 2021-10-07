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
        string nombre;
    public:
        persona(int,string);
        ~persona();
        void set_edad(int);
        int get_edad();
        void set_nombre(string);
        string get_nombre();
};

persona::persona(int ed,string nom)
{
    this->edad=ed;
    this->nombre=nom;
}
persona::~persona()
{
}
void persona::set_edad(int ed)
{
    this->edad=ed;
}
int persona::get_edad()
{
    return this->edad;
}
void persona::set_nombre(string nom)
{
    this->nombre=nom;
}
string persona::get_nombre()
{
    return this->nombre;
}

class contratado;

class empleado : public persona
{
    private:
        int salarioemp;
    public:
        empleado(int,string,int);
        void setsalario(int);
        int getsalario();
        friend void comparar(empleado *,contratado *);
};
empleado::empleado(int e,string nom,int sal):persona(e,nom)
{
    this->salarioemp=sal;
}
void empleado::setsalario(int s)
{
    this->salarioemp=s;
}
int empleado::getsalario()
{
    return this->salarioemp;
}
class contratado : public persona
{
    private:
        int salariocont;
    public:
        contratado(int,string,int);
        void setsalario(int);
        int getsalario();
        friend void comparar(empleado *,contratado *);
};
contratado::contratado(int e,string nom,int sal):persona(e,nom)
{
    this->salariocont=sal;
}
void contratado::setsalario(int s)
{
    this->salariocont=s;
}
int contratado::getsalario()
{
    return this->salariocont;
}
void comparar(empleado *a,contratado *b)
{
    if(a->salarioemp > b->salariocont)
        cout<<"el empleado cobra mas"<<endl;
    else
        cout<<"el contratado cobra mas"<<endl;
}
int main()
{
    int x,y;
    cout<<"ingrese salario de empleado: "<<endl;
    cin>>x;
    empleado *a=new empleado(20,"luciano",x);
    cout<<"ingrese salario de contratado: "<<endl;
    cin>>y;
    contratado *b=new contratado(30,"matias",y);
    comparar(a,b);
    system("PAUSE");
    return 0;
}
