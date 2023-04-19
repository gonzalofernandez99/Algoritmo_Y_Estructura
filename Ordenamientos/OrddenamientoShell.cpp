
#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<conio.h>
#include<string.h>

using namespace std;



void intercambio ( float & x , float & y ) {
    float aux ;
    aux = x ;
    x = y ;
    y = aux;
}

void ordenacionShell ( float a[],int n) {
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
     

int main(int argc, char const *argv[])
{
    float arreglo[] = {4,5,2,4,5,6,88,24,24,4};

    ordenacionShell(arreglo,10);

    cout<<"arreglo ordenado: "<<endl;

    for (int i = 0; i < 10; i++)
    {
        cout<<arreglo[i]<<"|";
    }
    

    return 0;
}
