#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<conio.h>
#include<string.h>

using namespace std;

using namespace std;

bool BusquedaSecuencial(int Arreglo[],int tope,int dato){
	bool encontre = false;
	int i = 0;
	while (i<tope)
	{
		if (Arreglo[i]==dato)
		{
			encontre=true;
		}
		i++;
	}
	return encontre;
}

void BusquedaVectores(int Arreglo[],int Busqueda[],int tope,int tope1){
	int i = 0,j = 0;
	bool encontre = false;
	while (i<tope)
	{
		while (j<tope1&&Busqueda[j])
		{
			if (Arreglo[i]==Busqueda[j])
			{
				encontre = true;
			}
			j++;
		}
		i++;
		j=0;
	}
	
}

float PromedioArreglo(int Arreglo[],int Top){
    float sumador = 0;
    int i = 0;
    for (i = 0; i < Top; i++)
    {
        sumador += Arreglo[i];
    }
    sumador = sumador/i;
    return sumador;
}

int ArregloMaximo(int Arreglo[],int Top){
    int i = 0;
    int max = Arreglo[i];
    for (i = 0; i < Top; i++)
    {
        if (Arreglo[i]>max)
        {
            max = Arreglo[i];
        }
        
    }
    
    return max;
}

void ArregloMaximo(int Arreglo[],int Top,int Pos[]){
    // Pos 0 = devuelve posicion mayor.
    //Pos 1 = devuelve posicion menor.
    int i = 0;
    int max = Arreglo[i];
    int min = Arreglo[i];
    for (i = 0; i < Top; i++)
    {
        if (Arreglo[i]>max)
        {
            max = Arreglo[i];
            Pos[0] = i;
        }
        if (Arreglo[i]<min)
        {
            min = Arreglo[i];
            Pos[1] = i;
        }
        
    }
    
}

void ArregloMaximo(int Arreglo[],int Top,int max){
    //devuelve la posicion del maximo valor del vector.
    
    int i = 0;
    cout<<"El valor maximo del vector es: "<<max<<endl;
    cout<<"Y se encuentra en la posicines: "<<endl;
    for (i = 0; i < Top; i++)
    {
        if (Arreglo[i]==max)
        {
            cout<<"posicion: "<<i<<endl;
        }
      
    }
}

void ArregloMerge(int ArregloX[],int ArregloY [],int ArregloMerge [],int Topes[]){
    bool encontre;
    int i = 0;
    int j = 0;
    for (int x = 0; x < Topes[0]; x++)
    {
        encontre = BusquedaSecuencial(ArregloMerge,j,ArregloX[x]);
        if (!encontre)
        {
            ArregloMerge [i] = ArregloX[x];
            i++;
            j++;
        }
        
    }
    for (int y = 0; y < Topes[1]; y++)
    {
        encontre = BusquedaSecuencial(ArregloMerge,j,ArregloY[y]);
        if (!encontre)
        {
            ArregloMerge [i] = ArregloY[y];
            i++;
            j++;
        }
        
    }
    Topes[2]=j;
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
