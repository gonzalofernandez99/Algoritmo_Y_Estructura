#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;
#define TOPE 10
#define Palabra "LIBRE"
struct Estacionamiento
{
    string Patente;
    string Hora;
};


int ingresoOpcion() {
    int __opcion;

    cout << endl << "1: Ingreso de vehiculo. 2: Salida de vehiculo. 3: Listado. 4: Fin." << endl;
    cout << "Ingrese opcion: ";
    cin >> __opcion;
    return __opcion;
}

string mostrarOpcionNoValida(int opciones){
    string Mostrar;
    Mostrar = "La Opcion "+to_string(opciones)+" No es valida, vuelva a intentar.";
    return Mostrar;
}

void LLenaVector(Estacionamiento VecEsta[],int Tope,string Palabras){
    for (int i = 0; i < Tope; i++)
    {
        VecEsta[i].Patente = Palabras;
        VecEsta[i].Hora= " ";
    }
    
}

int BuscaPos(Estacionamiento VecEsta[],int Tope,string dato){
    int i = 0;
    int indice = -1;
    bool encontre = false;
    while (i<Tope&&!encontre)
    {
        if ( VecEsta[i].Patente == dato)
        {
           encontre=true;
           indice = i;
        }
        i++;
    }
    return indice;
}

void IngresoVehiculo(Estacionamiento VecEsta[],int indice){
    fflush(stdin);
    cout<<"Bienvenido al estacionamiento ingrese su patente: "<<endl;
    getline(cin,VecEsta[indice].Patente);
    cout<<"Ingrese Horario de ingreso: "<<endl;
    getline(cin,VecEsta[indice].Hora);
}

void SalidaVehiculo(Estacionamiento VecEsta[],int Top,string palabras){
    string Patente;
    int Indice;
    fflush(stdin);
    cout<<"Ingrese Patente que se retira: "<<endl;
    getline(cin,Patente);
    Indice=BuscaPos(VecEsta,Top,Patente);
    if (Indice != (-1))
    {
        cout<<"Se retira la Patente: "<<Patente<<" su horario de ingreso fue: "<<VecEsta[Indice].Hora<<endl;
        VecEsta[Indice].Hora = " ";
        VecEsta[Indice].Patente = palabras;
    }else
    {
        cout<<"No se encontro la patente del vehiculo. "<<endl;
    }
        
}

void ListadoDeVehiculos(Estacionamiento VecEsta[],int Top,string palabras){
    cout<<"Listado de vehiculos: "<<endl;
    int Vehiculos = 1;
     for (int i = 0; i < Top; i++)
    {
        if (VecEsta[i].Patente != palabras)
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

int CantidadVehiculos(Estacionamiento VecEsta[],int Top,string palabras){
    int Vehiculos = 0;
    for (int i = 0; i < Top; i++)
    {
        if (VecEsta[i].Patente != palabras)
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
    int Indice;
    LLenaVector(VecEsta,TOPE,Palabra);
    do {
        opcion = ingresoOpcion();

        switch (opcion) {
            case 1:
                Indice=BuscaPos(VecEsta,TOPE,Palabra);
                if (Indice != (-1))
                {
                    IngresoVehiculo(VecEsta,Indice);
                }else
                {
                    cout<<"El estacionamiento esta Lleno."<<endl;
                }
                
                
                break;
            case 2:
                SalidaVehiculo(VecEsta,TOPE,Palabra);
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
                }else
                {
                    cout<<"No quedo ningun auto en el estacionamiento, saludos !"<<endl;
                }
                
                
                break;
            default:
                Mensaje = mostrarOpcionNoValida(opcion);
                cout<<Mensaje<<endl;
        }
    } while (opcion != 4 || cantVehiculosEstacionados != 0);

}
