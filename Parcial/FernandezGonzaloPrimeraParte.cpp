#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<conio.h>
#include<string.h>

using namespace std;

#define TOPE 10
#define TOPE2 20
#define TOPE3 30


struct Dos
{
    //struct Uno pruebas;
    char Nombre[20];
    string Fecha;
    int numeroParticipantes;
}Fiesta[100]; //cantidad de fiestas que pueden haber


void CargaFiestas(int top, int &N_fist){
    cout<<"numero de fiestas: "<<endl;
    cin>>N_fist;

    for (int i = 0; i < N_fist; i++)
    {
        fflush(stdin);
        cout<<"indique Nombre: "<<endl;
        cin.getline(Fiesta[i].Nombre,top,'\n');
        cout<<"indique Fecha: "<<endl;
        getline(cin,Fiesta[i].Fecha);
        //cin.getline(Fiesta[i].Fecha,top,'\n');
        cout<<"Numero participantes: "<<endl;
        cin>>Fiesta[i].numeroParticipantes;
    }
}

void mostrarDatos(int Fiestas){
    for (int i = 0; i < Fiestas; i++)
    {
        cout<<". "<<i+1<<endl;
        cout<<Fiesta[i].Nombre<<endl;
        cout<<". "<<i+1<<endl;
        cout<<Fiesta[i].Fecha<<endl;
        cout<<". "<<i+1<<endl;
        cout<<Fiesta[i].numeroParticipantes<<endl;
    }
    
}

int FechaConMas(int Fies){
    int j = 0; 
    for (int i = 0; i < Fies; i++)
    {
        if (Fiesta[i].numeroParticipantes>Fiesta[j].numeroParticipantes)
        {
            j = i;
        }
        
    }
    return j;
}

void mostrarUno(int Pos){
    cout<<"Nombre: "<<Fiesta[Pos].Nombre;
    cout<<"Fecha: "<<Fiesta[Pos].Fecha;
    cout<<"NumeroParticipantes: "<<Fiesta[Pos].numeroParticipantes<<endl;
}

void MostrarSegunFecha(int n_fiestas,int Indice){
    for (int i = 0; i < n_fiestas; i++)
    {
        if (Fiesta[Indice].Fecha==Fiesta[i].Fecha)
        {
            cout<<"Nombre: "<<Fiesta[i].Nombre;
            cout<<"Fecha: "<<Fiesta[i].Fecha;
            cout<<"NumeroParticipantes: "<<Fiesta[i].numeroParticipantes<<endl;
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    int fies = 0;
    int mayor = 0;
    CargaFiestas(TOPE2,fies);
    //mostrarDatos(fies);
    mayor = FechaConMas(fies);
    //mostrarUno(mayor);
    MostrarSegunFecha(fies,mayor);
    return 0;
}



