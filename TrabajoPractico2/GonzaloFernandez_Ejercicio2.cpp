#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<conio.h>
#include<string.h>

using namespace std;


#define TOPE 41

void IntercambioChar(char Palabra1[],char Palabra2[],int &Qchar){
    Qchar=0;
    strcpy(Palabra1,Palabra2);
    Qchar = strlen(Palabra1);
}

void IngresarCadenaChar(char cadch[], int tope1){
	cout<<"Ingrese nuevo contenido en CADENACHAR: ";
	cin.getline(cadch, tope1);
	system("PAUSE");
}

int main(int argc, char const *argv[])
{
    
    char cad1[TOPE];
    char cad2[TOPE] = "universidad nacional de avellaneda";
    int Leng = 0;

    cout<<"Muestro cadena1.."<<cad1<<endl;

    IntercambioChar(cad1,cad2,Leng);
    

    cout<<"Muestro cadena1: "<<cad1<<" Numero de caracteres: "<<Leng<<endl;

    IngresarCadenaChar(cad2,TOPE);  

    IntercambioChar(cad1,cad2,Leng);

    cout<<"Muestro cadena1: "<<cad1<<" Numero de caracteres: "<<Leng<<endl;

    return 0;
}
