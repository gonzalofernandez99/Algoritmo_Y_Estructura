#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>

#include <C:\Users\Gonzalo\Desktop\Facultad C++\TrabajoPractico4\Libreria\archivosg.h>

using namespace std;

#define TOPETEL 20

struct Telefono
{
    char Des_Telefono[TOPETEL];
    float Precio;
};

int ingresoOpcion() {
    int __opcion;
    fflush(stdin);
    cout << endl << "1: Ingreso de Telefono. 2: Listado. 3: Fin." << endl;
    cout << "Ingrese opcion: ";
    cin >> __opcion;
    return __opcion;
}

string mostrarOpcionNoValida(int opciones){
    string Mostrar;
    Mostrar = "La Opcion "+to_string(opciones)+" No es valida, vuelva a intentar.";
    return Mostrar;
}

void escribir(Telefono Tel,int TopeTelefonos,char arch[]){
    ofstream archivoB;
    int largo;
    largo = sizeof(Telefono);

    archivoB.open(arch,ios::app | ios::binary);

    if(archivoB.fail()){
        cout<<"no se puede crear el archivo";
        exit(1);
    }
    fflush(stdin);
    cout<<"Indica el nombre del Telefono"; cin.getline(Tel.Des_Telefono,TopeTelefonos,'\n');
    fflush(stdin);
    cout<<"indique el precio del telefono: ";cin>>Tel.Precio;
    archivoB.write((char *)&Tel,largo);
    archivoB.close();
}

void leer(Telefono Tel,char arch[]){
    ifstream archivoB;
    int largo;
    largo = sizeof(Telefono);
    //in para leer los archivos
    archivoB.open(arch,ios::in | ios::binary);
     if(archivoB.fail()){
        cout<<"no se puede crear el archivo";
        exit(1);
    }
    while (!archivoB.eof())//recorre mientras el archivo no este vacio
    {
        archivoB.read((char *)&Tel,largo);
        if (!archivoB.eof())
        { 
            cout<<"\n\n Mostrando los datos leidos "<<endl;
            fflush(stdin);
            cout<<"Nombre Telefono : "<<Tel.Des_Telefono<<endl;
            cout<<"Precio Telefono : "<<Tel.Precio<<endl;
        }
        
    }
    
    archivoB.close();
    
}

int main(int argc, char const *argv[])
{
    char Arhivo[]="telefonos.dat";
    bool Fin = false;
    Telefono Telefono;
    int opcion;
    string mensaje;
   
    do {
        opcion = ingresoOpcion();

        switch (opcion) {
            case 1:
                escribir(Telefono,TOPETEL,Arhivo);
                break;
            case 2:
                leer(Telefono,Arhivo);
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