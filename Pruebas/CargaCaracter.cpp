#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<conio.h>
#include<string.h>

using namespace std;

#define TOPE 10

void CargaCaracter(char Cadena[],int Top){
    int i = 0;
    cout<<"Ingrese nuevo contenido en CADENACHAR: ";
	cin.getline(Cadena, Top);

/*  for (i; i < 10; i++)
   {
    cout<<Cadena[i]<<" .";
   }
   i=0;
   while (Cadena[i]!='\0')
   {
    cout<<Cadena[i]<<" .";
    i++;
   } */
   
}

int contarCaracter(char miCadena[], int tope, char letra){
	int i=0;
	int q=0;
	
	while(i<tope&&miCadena[i]!='\0'){
		if(miCadena[i]==letra){
			q++;
		}
		i++;
	}
/* 	tope=strlen(miCadena);
	cout<<tope<<endl;
	for(i=0;i<tope;i++){
		if(miCadena[i]==letra){
			q++;
		}		
	}
	 */
	return q;
}



int main(int argc, char const *argv[])
{
    char Palabra[TOPE];

    CargaCaracter(Palabra, TOPE);
    cout<<"palabra: "<<Palabra;
    return 0;
}
