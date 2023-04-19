#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<conio.h>
#include<string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    
    int numeros[] = {80,2,3,1,5};
    int i,pos,aux;

    for(i=0;i<5;i++){
        pos = i;
        aux = numeros[i];
        while ((pos>0)&&(numeros[pos-1]>aux))
        {
           numeros[pos] = numeros[pos-1];
           pos--; 
        }
        numeros[pos] = aux;
    }

cout<<"Orden acendente: ";
for (i = 0; i < 5; i++)
{
    cout<<numeros[i]<<" ";
}
cout<<"\nOrden desendente: ";

for (i = 4; i >=0 ; i--)
{
    cout<<numeros[i]<<" ";
}


    return 0;
}
