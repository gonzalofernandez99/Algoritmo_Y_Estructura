#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<conio.h>
#include<string.h>
//#include<C:\Users\Gonzalo\Desktop\Facultad C++\Parcial\Librerias\Arreglos.h>

using namespace std;

#define TOPE1 6
#define TOPE 4

void intercambio ( int & x , int & y ) {
    int aux ;
    aux = x ;
    x = y ;
    y = aux;
}

void ordenacionShell ( int a[],int n) {
    int salto,i,j,k;
    salto = n / 2 ;
    while ( salto > 0 ) {
        for ( i = salto ; i < n ; i ++ ) {
            j = i - salto ;
            while (j >= 0) {
                k = j + salto;
                if ( a[j] <=a[k] ){ 
                    j =-1;
                }
                else{ 
                    intercambio (a[j],a[k]);
                    j -= salto;
                }
            } 
        }
        salto = salto / 2 ;
    }
}


bool DatoIgual(int x, int y){
    bool Igual = false;
    if (x == y)
    {
        Igual = true;
    }
    
    return Igual;
}

bool IgualMayorMenor(int x,int y){
    bool Mayor;
    if (x>y)
    {
        Mayor = true;
    }else
    {
        Mayor = false;
    }
    
    
    return Mayor;

}

void ArregloMergeOrdenado(int ArregloX[],int ArregloY [],int ArregloMerge [],int Topes[]){
int x =0;
int y = 0;
int i = 0;
bool Encontro;
bool Mayor;
while (x<Topes[0]&&y<Topes[1])
{
    
    
    Mayor = IgualMayorMenor(ArregloX[x],ArregloY[y]);
  
 
    while (Mayor&&y<Topes[1]&&ArregloY[y]!='\0')
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

    while (!Mayor&&x<Topes[0]&&ArregloX[x]!='\0')
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
    int Arreglo1[TOPE1] = {4,4,4,11,50,150};
    int Arreglo[TOPE] = {2,1,4,50};
    int SumaArreglos[SUMATOP];
    int Topes[] = {TOPE1,TOPE,SUMATOP};
    ordenacionShell(Arreglo1,TOPE1);
    ordenacionShell(Arreglo,TOPE);
    ArregloMergeOrdenado(Arreglo1,Arreglo,SumaArreglos,Topes);
    while (i<Topes[2]&&SumaArreglos[i]!='\0')
    {
        cout<<SumaArreglos[i]<<endl;
        i++;
    }
    
    return 0;

}
