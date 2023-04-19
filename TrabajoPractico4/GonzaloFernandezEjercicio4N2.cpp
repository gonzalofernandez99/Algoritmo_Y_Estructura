#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>

#include <C:\Users\Gonzalo\Desktop\Facultad C++\Parcial\Librerias\ManejoCaracteres.h>

using namespace std;
#define TOPEPROM 30
#define TOPETEL 20
#define TOPVECTORES 20

struct VentaTele
{
    char Nombre_promotor[TOPEPROM];
    char Telefono[TOPETEL];
    int Numero;
    int DiaMes;
};
struct Telefono
{
    char Des_Telefono[TOPETEL];
    float Precio;
};
struct Promotores
{
    char Promotor[TOPEPROM];
    float Comision;
};

bool busqueda(char Dato[],Promotores Vec_Prom[],int topeProm){
    bool encontre = false;
    int i = 0;
    while (i<topeProm && !encontre)
    {
        if (strcmp(Vec_Prom[i].Promotor, Dato) == 0)
        {
            encontre = true;
        }
        i++;
    }
    return encontre;
}

bool busqueda(char Dato[],Telefono Vec_Tel[],int topeProm){
    bool encontre = false;
    int i = 0;
    while (i<topeProm && !encontre)
    {
        if (strcmp(Vec_Tel[i].Des_Telefono, Dato) == 0)
        {
            encontre = true;
        }
        i++;
    }
    return encontre;
}


void leer(VentaTele Ventas,char arch[],char archB[],char archM[],Telefono Vec_Telf[],Promotores Vec_Prom[],int topeTel,int TopeProm){
    ifstream archivo;
    ofstream archivoB;
    ofstream archivoM;

    int largo;
    largo = sizeof(VentaTele);
    bool Mal = false;

    archivo.open(arch,ios::in | ios::binary);
    archivoB.open(archB,ios::out | ios::binary); 
    archivoM.open(archM,ios::out | ios::binary); 

    if(archivo.fail()||archivoB.fail()||archivoM.fail()){
        cout<<"no se puede crear el archivo";
        exit(1);
    }
    while (!archivo.eof())//recorre mientras el archivo no este vacio
    {
        archivo.read((char *)&Ventas,largo);
        if (!archivo.eof())
        { 
            /* cout<<"\n\n Mostrando los datos leidos "<<endl; */
            fflush(stdin);
            if (!busqueda(Ventas.Nombre_promotor,Vec_Prom,TopeProm))
            {
                /* cout<<"No encontro-> "<<Ventas.Nombre_promotor<<endl; */
                Mal = true;
            }
            if (!busqueda(Ventas.Telefono,Vec_Telf,topeTel))
            {
                /* cout<<"No encontro-> "<<Ventas.Telefono<<endl; */
                Mal = true;
            }
            if (Ventas.Numero<=0)
            {
                /* cout<<"Ventas.Telefono -> "<<Ventas.Numero<<endl; */
                Mal = true;
            }
            if (Ventas.DiaMes<=0 || Ventas.DiaMes>31)
            {
                /* cout<<"Ventas.DiaMes -> "<<Ventas.DiaMes<<endl; */
                Mal = true;
            }
            if (Mal)
            {
                archivoM.write((char *)&Ventas,largo);
            }else
            {
                archivoB.write((char *)&Ventas,largo);
            }
            
            Mal=false;
            
        }
        
    }
    
    archivo.close();
    archivoB.close();
    archivoM.close();
}
void CargarVector(Telefono Ventas,char arch[],Telefono Vec_Telf[],int &top){
    ifstream archivoB;
    int largo;
    largo = sizeof(Telefono);
    top = 0;
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
            Vec_Telf[top] = Ventas;
            top++;
        }
        
    }
    
    archivoB.close();
    
}

void CargarVector(Promotores Ventas,char arch[],Promotores Vec_Prom[],int &top){
    ifstream archivoB;
    int largo;
    largo = sizeof(Promotores);
    top = 0;
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
            Vec_Prom[top] = Ventas;
            top++;
        }
        
    }
    
    archivoB.close();
    
}




int main(int argc, char const *argv[])
{
    int TopeProm = 0, TopeTel = 0;

    char Arhivo[]="ingresoVentas.dat";
    char Arch_Telefono[]="telefonos.dat";
    char Arch_Promotores[]="Promotores.dat";
    char Arch_Bien[]="Ingresoscorrectos.dat";
    char Arch_Mal[]="IngresosIncorrectos.dat";

    Telefono Vec_Tel[TOPVECTORES];
    Promotores Vec_Prom[TOPVECTORES];
    VentaTele Telefonos;
    Telefono Tel;
    Promotores Prom;
    
    CargarVector(Tel,Arch_Telefono,Vec_Tel,TopeTel);
    CargarVector(Prom,Arch_Promotores,Vec_Prom,TopeProm);
    leer(Telefonos,Arhivo,Arch_Bien,Arch_Mal,Vec_Tel,Vec_Prom,TopeTel,TopeProm);
    
    return 0;
}