#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<conio.h>
#include<string.h>
#include<C:\Users\Gonzalo\Desktop\Facultad C++\Parcial\Librerias\Arreglos.h>

using namespace std;

#define TOPE1 6
#define TOPE 4

void ArregloMergeOrdenado(int ArregloX[],int ArregloY [],int ArregloMerge [],int Topes[]){
int x =0;
int y = 0;
int i = 0;
bool Encontro;
bool Mayor;
while (x<Topes[0]||y<Topes[1])
{
    
    Mayor = IgualMayorMenor(ArregloX[x],ArregloY[y]);
    if (y>=Topes[1])
    {
        Mayor =false;
    }
    if (x>=Topes[0])
    {
        Mayor =true;
    }
    
 
    while (Mayor&&y<Topes[1])
    {
        Encontro = DatoIgual(ArregloY[y],ArregloMerge[i-1]);
        if (!Encontro)
        {
            ArregloMerge[i] = ArregloY[y];
            i++;
            y++;
        }else
        {
            y++;
        }
        Mayor = IgualMayorMenor(ArregloX[x],ArregloY[y]);
    }

    while (!Mayor&&x<Topes[0])
    {
        Encontro = DatoIgual(ArregloX[x],ArregloMerge[i-1]);
        if (!Encontro)
        {
            ArregloMerge[i] = ArregloX[x];
            i++;
            x++;
        }else
        {
            x++;
        }
        
       Mayor = IgualMayorMenor(ArregloX[x],ArregloY[y]);
    }
}

Topes[2] = i;
}

int main(int argc, char const *argv[])
{
    int SUMATOP = TOPE1+TOPE;
    int i = 0,cant = 0;
    int Arreglo1[TOPE1] = {0,4,0,1,4,251};
    int Arreglo[TOPE] = {1,250,250,250};
    int SumaArreglos[SUMATOP];
    int Topes[] = {TOPE1,TOPE,SUMATOP};
    ArregloMerge(Arreglo1,Arreglo,SumaArreglos,Topes);
    cout<<"\nArreglo no ordenado: "<<endl;

    while (i<Topes[2])
    {
        cout<<SumaArreglos[i]<<endl;
        i++;
    }
    
    i = 0;
    system("PAUSE");
    ordenacionShell(Arreglo,TOPE);
    ordenacionShell(Arreglo1,TOPE1);
    ArregloMergeOrdenado(Arreglo1,Arreglo,SumaArreglos,Topes);
    cout<<"\nArreglo ordenado: "<<endl;
    while (i<Topes[2])
    {
        cout<<SumaArreglos[i]<<endl;
        i++;
    }
    
    return 0;

}
