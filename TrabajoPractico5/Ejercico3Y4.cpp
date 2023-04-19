#include <iostream>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <conio.h>
#include <C:\Users\Gonzalo\Desktop\Facultad C++\Parcial\Librerias\Arreglos.h>

#define TOPER 2
#define TOPEC 3
#define TOP 4

using namespace std;

void MostrarMatriz(int Matriz[][TOPEC],int tr,int tc){
    for (int i = 0; i < tr; i++)
    {
        for (int j = 0; j < tc; j++)
        {
            cout<<Matriz[i][j];
        }
        cout<<"\n";
    }
}

void MuestraTraspuesta(int Matriz[][TOPEC],int tr,int tc){
    for (int j = 0; j < tc; j++)
    {
        for (int i = 0; i < tr; i++)
        {
            cout<<Matriz[i][j];
        }
        cout<<"\n";
    }
}

void BusquedaMatrizDato(int Matriz[][TOPEC],int tr,int tc,int &x,int &y,int dato){
    x = -1;
    y = -1;
    for (int i = 0; i < tr; i++)
    {
        for (int j = 0; j < tc; j++)
        {
            if (Matriz[i][j]==dato)
            {
                x = i;
                y = j;
            }
            
            
        }
        
    }
    
}

void BusquedaMatrizVectorial(int Matriz[][TOPEC],int tr,int tc,int Arreglo[],int Busqueda[],int Tope,int &indice){
bool encontre = false;    
    for (int b = 0; b < Tope; b++)
    {
        for (int i = 0; i < tr; i++)
        {
            for (int j = 0; j < tc; j++)
            {
                if (Matriz[i][j]==Arreglo[b])
                {
                    encontre = true;
                }
            
            }
        
        }
    if (!encontre)
    {
        Busqueda[indice]=Arreglo[b];
        indice++;
        
    }
    
    encontre = false;

    }
  
}


int main(int argc, char const *argv[])
{
    int  numeros[TOPER][TOPEC] = {{1,2,3},{4,5,6}};
    int Dato = 6;
    int x,y;
    int vector[TOP]={8,12,14,70};
    int vectorNoEncontro[TOP];
    int indice = 0;
    MostrarMatriz(numeros,TOPER,TOPEC);
    cout<<"\nNumero vectorial: "<<endl;
    MuestraTraspuesta(numeros,TOPER,TOPEC);

    BusquedaMatrizDato(numeros,TOPER,TOPEC,x,y,Dato);

    cout<<"[i] "<<x<<" [j] "<<y<<" Numero que encontro "<<numeros[x][y];

    BusquedaMatrizVectorial(numeros,TOPER,TOPEC,vector,vectorNoEncontro,TOP,indice);

    if (indice == 0)
    {
        cout<<"no encontre nada. "<<endl;
    }
    

    for (int i = 0; i < indice; i++)
    {
        cout<<"\n"<<vectorNoEncontro[i]<<endl;
    }
    




    return 0;
}
