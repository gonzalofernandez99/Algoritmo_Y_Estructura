#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<conio.h>
#include<string.h>
#include<C:\Users\Gonzalo\Desktop\Facultad C++\Parcial\Librerias\Arreglos.h>

using namespace std;

#define TOPE 20
#define TOP 2

int main(int argc, char const *argv[])
{
    float Promedio = 0;
    int maximo = 0;
    int arreglos[TOPE] = {1,2,20,4,5,20,7,8,9,10,20,12,13,14,20,16,17,18,19,20};
    int Pos[TOP] = {0,0};
    Promedio = PromedioArreglo(arreglos,TOPE);
    cout<<"El promedio es: "<<Promedio<<endl;
    maximo = ArregloMaximo(arreglos,TOPE);
    cout<<"El maximo es: "<<maximo<<endl;
    ArregloMaximo(arreglos,TOPE,Pos);
    cout<<"Maximo es la posicion: "<<Pos[0];
    cout<<"Minimo es la posicion: "<<Pos[1]<<endl;
    ArregloMaximo(arreglos,TOPE,maximo);

    return 0;
}

