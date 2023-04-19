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

int ingresoOpcion() {
    int __opcion;
    fflush(stdin);
    cout << endl << "1: Ingreso de Venta. 2: Listado. 3: Fin." << endl;
    cout << "Ingrese opcion: ";
    cin >> __opcion;
    return __opcion;
}

string mostrarOpcionNoValida(int opciones){
    string Mostrar;
    Mostrar = "La Opcion "+to_string(opciones)+" No es valida, vuelva a intentar.";
    return Mostrar;
}



void escribir(VentaTele Ventas,int TopeNombre,int TopeTelefonos,char arch[]){
    ofstream archivoB;
    int largo;
    bool Invalido = false;
    largo = sizeof(VentaTele);
    //app para añadir, out para escribir, binary para archivos binarios
    archivoB.open(arch,ios::app | ios::binary); 

    if(archivoB.fail()){
        cout<<"no se puede crear el archivo";
        exit(1);
    }
    fflush(stdin);
    cout<<"Pidiendo datos"<<endl;
    cout<<"indique el nombre del promotor: "; cin.getline(Ventas.Nombre_promotor,TopeNombre,'\n');
    fflush(stdin);
    cout<<"indique el telefono: "; cin.getline(Ventas.Telefono,TopeNombre,'\n');
    cout<<"indique el numero de ventas: ";cin>>Ventas.Numero;
    cout<<"indique el numero del mes: ";cin>>Ventas.DiaMes;

    archivoB.write((char *)&Ventas,largo);
    archivoB.close();
}

void leer(VentaTele Ventas,char arch[]){
    ifstream archivoB;
    int largo;
    largo = sizeof(VentaTele);
    //in para leer los archivos
    archivoB.open(arch,ios::in | ios::binary);
     if(archivoB.fail()){
        cout<<"no se puede crear el archivo";
        exit(1);
    }
    while (!archivoB.eof())//recorre mientras el archivo no este vacio
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
    char Arhivo[]="Ingresoscorrectos.dat";

    VentaTele Telefonos;
    int opcion;
    string mensaje;
   
    do {
        opcion = ingresoOpcion();

        switch (opcion) {
            case 1:
                escribir(Telefonos,TOPEPROM,TOPETEL,Arhivo);
                break;
            case 2:
                leer(Telefonos,Arhivo);
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