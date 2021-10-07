#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
using namespace std;

class importado;
class nacional;

class productos
{
    private:
            string marca;
            string nombre;
            int codigo;
            int cantidad;
    public:
            productos(string,string,int,int);
            void setmarca(string);
            string getmarca();
            void setnombre(string);
            string getnombre();
            void setcodigo(int);
            int getcodigo();
            void setcantidad(int);
            int getcantidad();
            friend void comparar(importado *,nacional *);
};
productos::productos(string mar,string nom,int cod,int cant)
{
    this->marca=mar;
    this->nombre=nom;
    this->codigo=cod;
    this->cantidad=cant;
}
void productos::setmarca(string mar)
{
    this->marca=mar;
}
string productos::getmarca()
{
    return this->marca;
}
void productos::setnombre(string nom)
{
    this->nombre=nom;
}
string productos::getnombre()
{
    return this->nombre;
}
void productos::setcodigo(int cod)
{
    this->codigo=cod;
}
int productos::getcodigo()
{
    return this->codigo;
}
void productos::setcantidad(int cant)
{
    this->cantidad=cant;
}
int productos::getcantidad()
{
    return this->cantidad;
}
class nacional : public productos
{
    private:
    		string fabricante;
    		string proveedor;
    public:
            nacional(string,string,int,int,string,string);
            void setfabricante(string);
            string getfabricante();
            void setproveedor(string);
            string getproveedor();
            friend void comparar(importado *,nacional *);
};
nacional::nacional(string mar,string nom,int cod,int cant,string fab,string prove):productos(mar,nom,cod,cant)
{
    this->fabricante=fab;
    this->proveedor=prove;
}
void nacional::setfabricante(string fab)
{
    this->fabricante=fab;
}
string nacional::getfabricante()
{
    return this->fabricante;
}
void nacional::setproveedor(string prove)
{
    this->proveedor=prove;
}
string nacional::getproveedor()
{
    return this->proveedor;
}

class importado : public productos
{
    private:
            string importador;
            string paisorigen;
    public:
            importado(string,string,int,int,string,string);
            void setimportador(string);
            string getimportador();
            void setpaisorigen(string);
            string getpaisorigen();
            friend void comparar(importado *,nacional *);
};
importado::importado(string mar,string nom,int cod,int cant,string import,string pais):productos(mar,nom,cod,cant)
{
    this->importador=import;
    this->paisorigen=pais;
}
void importado::setimportador(string impor)
{
    this->importador=impor;
}
string importado::getimportador()
{
    return this->importador;
}
void importado::setpaisorigen(string pais)
{
    this->paisorigen=pais;
}
string importado::getpaisorigen()
{
    return this->paisorigen;
}

void comparar(importado *a,nacional *b)
{
    if(a->cantidad > b->cantidad)
    {
        cout<<"marca: "<<a->marca<<"\nnombre: "<<a->nombre<<"\ncodigo: "<<a->codigo<<"\ncantidad: "<<a->cantidad<<"\nimportador: "<<a->importador<<"\npais de origen: "<<a->paisorigen<<endl;
    }
    else
    {
        cout<<"marca: "<<b->marca<<"\nnombre: "<<b->nombre<<"\ncodigo: "<<b->codigo<<"\ncantidad: "<<b->cantidad<<"\nfabricante: "<<b->fabricante<<"\nproveedor: "<<b->proveedor<<endl;
    }
}

int main()
{
    importado *a=new importado("jvc","tv 32",335,1000,"argentina","china");
    nacional *b=new nacional("fiat","auto 5 puertas",105,500,"fiat argentina","giama");
    comparar(a,b);
    return 0;
}
