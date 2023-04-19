#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<conio.h>
#include<string.h>
#include<C:\Users\Gonzalo\Desktop\Facultad C++\Parcial\Librerias\ManejoCaracteres.h>
//uso libreria,adjunto en el compilado. nombre: ManejoCaracteres.h

using namespace std;

#define TOPE 40

int BusquedaEntrePosiciones(char Cadena[],int top,char Letra,int x,int y){
    int cantdidadCaracter = 0;
    int resultado = 0;
    if (x>y)
    {
        y = x;
    }
    
    
    if (top>=y)
    {
        for (int i = x; i < y && Cadena[i]!='\0'; i++)
        {
            if (Cadena[i]==Letra)
            {
                cantdidadCaracter++;
            }
            
        }
        cout<<"La cantidad de veces que aparece el caracter buscado "<<cantdidadCaracter<<"-N"<<endl;
    }else{
        cout<<"Parametros fuera de rango. "<<endl;
        resultado = (-1);
    }

    return resultado;
    
}

//Dejo el main por si les hace mas facil para probarlo.


/* int main(int argc, char const *argv[])
{
    char cadena [] = {"Holaesto es una prueba"};
    int resultado = 0;
    resultado = BusquedaEntrePosiciones(cadena,TOPE,'a',0,50);
    cout<<"Resultado: "<<resultado;


    return 0;
} */
