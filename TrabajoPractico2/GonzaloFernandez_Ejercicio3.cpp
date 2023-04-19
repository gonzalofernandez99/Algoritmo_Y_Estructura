#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

#define TOPECAD 100

/*
ACLARACI�N IMPORTANTE: ojo que este es solo un ejemplo, en un caso real tanto la cadena como el caracter a contar 
deber�an ser ingresados por teclado, nosotros no lo hacemos as� para no extender el video.
*/

//Dada una cadena y un caracter, decir cuantas veces aparece dicho caracter en la cadena.

int contarCaracter(char miCadena[], int tope, char letra){
	int i=0;
	int q=0;
	
	while(i<tope&&miCadena[i]!='\0'){
		if(miCadena[i]==letra){
			q++;
		}
		i++;
	}
    /*
	tope=strlen(miCadena);
	cout<<tope<<endl;
	for(i=0;i<tope;i++){
		if(miCadena[i]==letra){
			q++;
		}		
	}
	*/
	return q;
    
}

int main(){

	char cad[TOPECAD]="Esto es una cadena de caracteres!a"; //cadena de HASTA 99 elementos, OJO: SOLO 99 ELEMENTOS!!!
	
	char c = 'a'; //esto es UN caracter
	
	int resu=101;

	//resu=contarCaracter(cad,TOPECAD,c);
	
	//c='c';

	cout<<contarCaracter(cad,TOPECAD,'c')+contarCaracter(cad,TOPECAD,c);
	

}
