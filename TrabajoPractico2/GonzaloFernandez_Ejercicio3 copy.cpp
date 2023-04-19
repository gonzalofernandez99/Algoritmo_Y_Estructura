#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<conio.h>
#include<string.h>

using namespace std;


#define TOPE 41

    struct Caracter
    {
        char caracteres[TOPE];
    }car[100];



/*int busquedaBinaria (char a[],char dato,int inferior,int superior) {
    int mitad;
    int q=0;
    if(inferior > superior) { // No encontrado
        return -1;
    }
    else{
        mitad = ( inferior + superior ) / 2 ;
        if (dato == a[mitad] ) { // Caso base
            return mitad;
        }
        else if(dato>a [mitad]) {
            return busquedaBinaria(a,dato,mitad+1,superior);
        }
        else
        {
            return busquedaBinaria(a,dato,inferior,mitad-1);
        }

    }


}*/

int main(int argc, char const *argv[])
{
    
    int n_car = 4;

    cout<<"digite la cantidad de caracteres: "<<endl;

    for(int i=0;i<n_car;i++){
        cout<<"digite su caracter Numero "<<i+1<<": ";
        cin.getline(car[i].caracteres,TOPE,'\n');
    }



    return 0;
}
