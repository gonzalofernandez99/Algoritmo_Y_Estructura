#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>

#include <C:\Users\Gonzalo\Desktop\Facultad C++\TrabajoPractico4\Libreria\archivosg.h>

using namespace std;
#define TOPEPROM 30
#define TOPETEL 20

struct VentaTele
{
    char Nombre_promotor[TOPEPROM];
    char Telefono[TOPETEL];
    int Numero;
    int DiaMes;
};

void escribir(VentaTele Ventas,int TopeNombre,int TopeTelefonos,char arch[]){
    ofstream archivoB;
    int largo;
    bool Invalido = false;
    largo = sizeof(VentaTele);

    archivoB.open(arch,ios::app | ios::binary);

    if(archivoB.fail()){
        cout<<"no se puede crear el archivo";
        exit(1);
    }

    cout<<"Pidiendo datos"<<endl;
    cout<<"indique el nombre del promotor: "; cin.getline(Ventas.Nombre_promotor,TopeNombre,'\n');
    fflush(stdin);
    cout<<"indique el telefono: "; cin.getline(Ventas.Telefono,TopeNombre,'\n');
    cout<<"indique el numero de ventas: ";cin>>Ventas.Numero;
    if (Ventas.Numero<=0)
    {
        cout<<"Numero es menor o igual a 0 ERROR."<<endl;
    }

    cout<<"indique el numero del mes: ";cin>>Ventas.DiaMes;

    if (Ventas.DiaMes<1 || Ventas.DiaMes>31)
    {
        cout<<"Dia del mes no valido."<<endl;
    }
    

    archivoB.write((char *)&Ventas,largo);
    archivoB.close();
}

void leer(VentaTele Ventas,char arch[]){
    ifstream archivoB;
    int largo;
    largo = sizeof(VentaTele);

    archivoB.open(arch,ios::in | ios::binary);
     if(archivoB.fail()){
        cout<<"no se puede crear el archivo";
        exit(1);
    }
    while (!archivoB.eof())
    {
        archivoB.read((char *)&Ventas,largo);
        if (!archivoB.eof())
        { 
            cout<<"\n\n Mostrando los datos leidos "<<endl;
            fflush(stdin);
            cout<<"Nombre: "<<Ventas.Nombre_promotor<<endl;
            cout<<"Telefono: "<<Ventas.Telefono<<endl;
            cout<<"Numero ventas: "<<Ventas.Numero<<endl;
            cout<<"Numero del mes: "<<Ventas.DiaMes<<endl;
        }
        
    }
    
    archivoB.close();
    
}

int main(int argc, char const *argv[])
{
    char Arhivo[]="Pruebaaa.dat";

    VentaTele Ventas;
    escribir(Ventas,TOPEPROM,TOPETEL,Arhivo);
    leer(Ventas,Arhivo);
    return 0;
}