#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>

#include <C:\Users\Gonzalo\Desktop\Facultad C++\TrabajoPractico4\Libreria\archivosg.h>

using namespace std;

#define TOPEPROM 30
#define TOPETEL 20
#define TOPRODUCTO 6

struct VentasRealizadas
{
    char Codigo_producto[TOPRODUCTO];
    char Descuento;
    int Edad;
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



void escribir(VentasRealizadas Ventas,int TopeNombre,int TopeTelefonos,char arch[]){
    ofstream archivoB;
    int largo;
    bool Invalido = false;
    largo = sizeof(VentasRealizadas);
    //app para añadir, out para escribir, binary para archivos binarios
    archivoB.open(arch,ios::app | ios::binary); 

    if(archivoB.fail()){
        cout<<"no se puede crear el archivo";
        exit(1);
    }
    fflush(stdin);
    cout<<"Pidiendo datos"<<endl;
    cout<<"indique el nombre del producto vendido: "; cin.getline(Ventas.Codigo_producto,TopeNombre,'\n');
    fflush(stdin);
    cout<<"indique si tiene descuento: "; cin>>Ventas.Descuento;
    cout<<"indique la edad del comprador: ";cin>>Ventas.Edad;

    archivoB.write((char *)&Ventas,largo);
    archivoB.close();
}

void leer(VentasRealizadas Ventas,char arch[]){
    ifstream archivoB;
    int largo;
    largo = sizeof(Ventas);
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
            cout<<"Nombre: "<<Ventas.Codigo_producto<<endl;
            cout<<"Descuento "<<Ventas.Descuento<<endl;
            cout<<"Edad: "<<Ventas.Edad<<endl;
        }
        
    }
    
    archivoB.close();
    
}

int main(int argc, char const *argv[])
{
    char Arhivo[]="Ingresoscorrectos.dat";

    VentasRealizadas Telefonos;
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