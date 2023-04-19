#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>

#include <C:\Users\Gonzalo\Desktop\Facultad C++\TrabajoPractico4\Libreria\archivosg.h>

using namespace std;

#define TOPEPROM 30

struct Promotores
{
    char Promotor[TOPEPROM];
    float Comision;
};

int ingresoOpcion() {
    int __opcion;
    fflush(stdin);
    cout << endl << "1: Ingreso de Promotor. 2: Listado. 3: Fin." << endl;
    cout << "Ingrese opcion: ";
    cin >> __opcion;
    return __opcion;
}

string mostrarOpcionNoValida(int opciones){
    string Mostrar;
    Mostrar = "La Opcion "+to_string(opciones)+" No es valida, vuelva a intentar.";
    return Mostrar;
}

void escribir(Promotores Prom,int TopeTelefonos,char arch[]){
    ofstream archivoB;
    int largo;
    largo = sizeof(Promotores);

    archivoB.open(arch,ios::app | ios::binary);

    if(archivoB.fail()){
        cout<<"no se puede crear el archivo";
        exit(1);
    }
    fflush(stdin);
    cout<<"Indica el nombre del Promotor: "; cin.getline(Prom.Promotor,TopeTelefonos,'\n');
    fflush(stdin);
    cout<<"indique la comision: ";cin>>Prom.Comision;
    archivoB.write((char *)&Prom,largo);
    archivoB.close();
}

void leer(Promotores Prom,char arch[]){
    ifstream archivoB;
    int largo;
    largo = sizeof(Promotores);
    //in para leer los archivos
    archivoB.open(arch,ios::in | ios::binary);
     if(archivoB.fail()){
        cout<<"no se puede crear el archivo";
        exit(1);
    }
    while (!archivoB.eof())//recorre mientras el archivo no este vacio
    {
        archivoB.read((char *)&Prom,largo);
        if (!archivoB.eof())
        { 
            cout<<"\n\n Mostrando los datos leidos "<<endl;
            fflush(stdin);
            cout<<"Nombre Promotor : "<<Prom.Promotor<<endl;
            cout<<"Comision Promotor : "<<Prom.Comision<<endl;
        }
        
    }
    
    archivoB.close();
    
}

int main(int argc, char const *argv[])
{
    char Arhivo[]="Promotores.dat";
    bool Fin = false;
    Promotores Promotor;
    int opcion;
    string mensaje;
   
    do {
        opcion = ingresoOpcion();

        switch (opcion) {
            case 1:
                escribir(Promotor,TOPEPROM,Arhivo);
                break;
            case 2:
                leer(Promotor,Arhivo);
                break;
            case 3:
                cout<<"Fin."<<endl;
                break;
            default:
                mensaje = mostrarOpcionNoValida(opcion);
                cout<<mensaje<<endl;
        }
    } while (opcion != 3);

        

    return 0;
}