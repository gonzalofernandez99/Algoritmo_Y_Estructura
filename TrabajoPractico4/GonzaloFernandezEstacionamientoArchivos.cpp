#include <iostream>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <C:\Users\Gonzalo\Desktop\Facultad C++\TrabajoPractico4\Libreria\archivosg.h>
#include <fstream>

using namespace std;

#define TOPE 10
#define TOPEPATENTE 10
#define TOPEHRORA 10 

struct Estacionamiento
{
    char Patente[TOPEPATENTE];
    char Hora[TOPEHRORA];
};




string mostrarOpcionNoValida(int opciones){
    string Mostrar;
    Mostrar = "La Opcion "+to_string(opciones)+" No es valida, vuelva a intentar.";
    return Mostrar;
}

void LLenaVector(Estacionamiento VecEsta[],int Tope,char Palabras[]){
    for (int i = 0; i < Tope; i++)
    {
        strcpy(VecEsta[i].Patente,Palabras);
        strcpy(VecEsta[i].Hora,"");
    }
    
}

void EscribeArchivo(Estacionamiento Autos,char arch[],int Tope,Estacionamiento VecEsta[]){
    ofstream archivo;

    int largo;
    largo = sizeof(Autos);
    bool Mal = false;
    int Vehiculos = 0;
    archivo.open(arch,ios::out | ios::binary);

    if (archivo.fail())
    {
        cout<<"no se puede crear el archivo";
        exit(1);
    }

    for (int i = 0; i < Tope; i++)
    {
        archivo.write((char *)&VecEsta[i],largo);
    } 
    archivo.close();
}

void leerYcarga(Estacionamiento Autos,char arch[],Estacionamiento VecEsta[],int Tope,char palabras[]){

    ifstream archivo;
    int largo;
    largo = sizeof(Autos);
    bool Mal = false;
    int top = 0;
    
    archivo.open(arch,ios::in | ios::binary);

    if(archivo.fail()){
        LLenaVector(VecEsta,Tope,palabras);
    }else
    {
        while (!archivo.eof())//recorre mientras el archivo no este vacio
        {
        archivo.read((char *)&Autos,largo);
            if (!archivo.eof())
            { 
                /* cout<<VecEsta[top].Hora<<endl;
                cout<<VecEsta[top].Patente<<endl; */
                
                VecEsta[top] = Autos;
                top++;
            }

        }
        archivo.close();
    }
    
}


int BuscaPos(Estacionamiento VecEsta[],int Tope,char dato[]){
    int i = 0;
    int indice = -1;
    bool encontre = false;
    while (i<Tope&&!encontre)
    {
        if (strcmp(VecEsta[i].Patente,dato)==0)
        {
           encontre=true;
           indice = i;
        }
        i++;
    }
    return indice;
}

void IngresoVehiculo(Estacionamiento VecEsta[],int indice,int TopePatente, int TopeHora){
    fflush(stdin);
    cout<<"Bienvenido al estacionamiento ingrese su patente: "<<endl;
    cin.getline(VecEsta[indice].Patente,TopePatente);
    cout<<"Ingrese Horario de ingreso: "<<endl;
    cin.getline(VecEsta[indice].Hora,TopeHora);
}

void SalidaVehiculo(Estacionamiento VecEsta[],int Top,char palabras[],int TopePatente){
    char Patente[TopePatente];
    int Indice;
    fflush(stdin);
    cout<<"Ingrese Patente que se retira: "<<endl;
    cin.getline(Patente,TopePatente);
    Indice=BuscaPos(VecEsta,Top,Patente);
    if (Indice != (-1))
    {
        cout<<"Se retira la Patente: "<<Patente<<" su horario de ingreso fue: "<<VecEsta[Indice].Hora<<endl;
        strcpy(VecEsta[Indice].Hora,"");
        strcpy(VecEsta[Indice].Patente,palabras);
    }else
    {
        cout<<"No se encontro la patente del vehiculo. "<<endl;
    }
        
}

void ListadoDeVehiculos(Estacionamiento VecEsta[],int Top,char palabras[]){
    cout<<"Listado de vehiculos: "<<endl;
    int Vehiculos = 1;
    for (int i = 0; i < Top; i++)
    {
        if (!strcmp(VecEsta[i].Patente,palabras)==0)
        {
            cout<<Vehiculos<<". Patente: "<<VecEsta[i].Patente<<" Hora de ingreso: "<<VecEsta[i].Hora<<endl;
            Vehiculos++;
        }
        
    }
    if (Vehiculos==1)
    {
        cout<<"No hay ningun vehiculo. "<<endl;
    }
    
    
}

int CantidadVehiculos(Estacionamiento VecEsta[],int Top,char palabras[]){
    int Vehiculos = 0;
    for (int i = 0; i < Top; i++)
    {
        if (!strcmp(VecEsta[i].Patente,palabras)==0)
        {
            
            Vehiculos++;
        }
        
    }
    return Vehiculos;
}

int main()
{
    int opcion;
    int cantVehiculosEstacionados;
    string Mensaje;
    Estacionamiento VecEsta[TOPE];
    Estacionamiento Autos;
    int Indice;
    char Arhivo[]="Estacionamiento.dat";
    char Palabra[TOPEPATENTE]="Libre";

    leerYcarga(Autos,Arhivo,VecEsta,TOPE,Palabra); 

    do {
        opcion = ingresoOpcion();

        switch (opcion) {
            case 1:
                Indice=BuscaPos(VecEsta,TOPE,Palabra);
                if (Indice != (-1))
                {
                    IngresoVehiculo(VecEsta,Indice,TOPEPATENTE,TOPEHRORA);
                }else
                {
                    cout<<"El estacionamiento esta Lleno."<<endl;
                }
                
                
                break;
            case 2:
                SalidaVehiculo(VecEsta,TOPE,Palabra,TOPEPATENTE);
                break;
            case 3:
                ListadoDeVehiculos(VecEsta,TOPE,Palabra);
                break;
            case 4:
                cantVehiculosEstacionados = CantidadVehiculos(VecEsta,TOPE,Palabra);
                if (cantVehiculosEstacionados>0)
                {
                    cout<<"\nTodavia quedan autos en el estacionamiento. "<<endl;
                    ListadoDeVehiculos(VecEsta,TOPE,Palabra);
                }
                EscribeArchivo(Autos,Arhivo,TOPE,VecEsta);
                
                break;
            default:
                Mensaje = mostrarOpcionNoValida(opcion);
                cout<<Mensaje<<endl;
        }
    } while (opcion != 4);

}
