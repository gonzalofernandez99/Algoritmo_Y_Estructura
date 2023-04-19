#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<conio.h>
#include<string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int numero[]={2,5,4,3,1};
    int i,j,aux;

    for(i=0;i<5;i++){
        for(int p=0;p<5;p++){
                cout<<numero[p]<<"  ";
            }
            for(j=0;j<5;j++){
                if(numero[j]>numero[j+1]){
                aux = numero[j];
                numero[j] = numero[j+1];
                numero[j+1]=aux;
            }
        }
    }


    cout<<"\norden asecendente: ";
    for(i=0;i<5;i++){
        cout<<numero[i]<<"  ";
    }


    return 0;
}
