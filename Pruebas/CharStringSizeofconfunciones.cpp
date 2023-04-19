#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
#define TOPECHAR 21

void VerLargo(char cadch[], int tope1, string cads){
	cout<< "CADENACHAR: "<<sizeof(cadch)<<endl;
	
	cout<< "CADENASTRING: "<<sizeof(cads)<<endl;
	
	system("PAUSE");
	
	cout<<"Cuantos caracteres tiene CADENACHAR? "<<strlen (cadch)<<endl;
	
	cout<<"y cuantos caracteres tiene CADENASTRING? "<<cads.size()<<endl;
	
	// la instrucci�n sizeof() nos dice el tama�o de la variable
	// strlen se usa para saber cuantos caracteres tiene efectivamente una cadena
	// de tipo char y para una cadena de tipo string esa informaci�n se obtiene
	// con el nombre de la cadena seguida por ".size()"
	

}
void IngresarCadenaChar(char cadch[], int tope1){
	cout<<"Ingrese nuevo contenido en CADENACHAR: ";
	cin.getline(cadch, tope1);
	system("PAUSE");
}

void MostrarCadenaChar(char cadch[]){
	cout<<endl<<"La cadena de char ingresada es: "<<cadch<<endl;
	cout<<"Cuantos caracteres tiene ahora CADENACHAR? "<<strlen (cadch)<<endl<<endl;
	system("PAUSE");
	}		
	
void ContarChar(char cadch[], int topech, int &qchar){
	qchar=0;
	//qchar<topech && 
	while (cadch[qchar]!='\0'){
		cout<<"cadch[qchar]: "<<cadch[qchar+1]<<endl;
		qchar++;
	}
	
}







int main(){
	char cadenachar[TOPECHAR]="Hola Mundo";
	string cadenastring="Bienvenidos a AyED";
	int qchar;

	VerLargo(cadenachar, TOPECHAR, cadenastring);
	system("PAUSE");

	MostrarCadenaChar (cadenachar);

	IngresarCadenaChar(cadenachar, TOPECHAR);
	MostrarCadenaChar (cadenachar);
	ContarChar(cadenachar, TOPECHAR, qchar);
	cout<<"La cantidad de caracteres de cadenachar es: "<<qchar;

}

