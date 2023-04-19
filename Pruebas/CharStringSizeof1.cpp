#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

#define TOPE 21
int main(){
	char cadenachar[TOPE]="Hola Mundo";
	
	string cadenastring="Bienvenidos a AyED";
	
	cout<< "CADENACHAR: "<<sizeof(cadenachar)<<endl;
	
	cout<< "CADENASTRING: "<<sizeof(cadenastring)<<endl;
	
	cout<<"Cuantos caracteres tiene CADENACHAR? "<<strlen (cadenachar)<<endl;
	
	cout<<"y cuantos caracteres tiene CADENASTRING? "<<cadenastring.size()<<endl;
	
	system("PAUSE");

	// la instrucción sizeof() nos dice el tamaño de la variable
	// strlen se usa para saber cuantos caracteres tiene efectivamente una cadena
	// de tipo char y para una cadena de tipo string esa información se obtiene
	// con el nombre de la cadena seguida por ".size()"
	
	
	cout<<"Ingrese nuevo contenido en CADENACHAR: ";
	cin.getline(cadenachar, TOPE);
	system("PAUSE");
	cout<<endl<<"El nuevo contenido de CADENACHAR es: "<<cadenachar<<endl;
	cout<<"Cuantos caracteres tiene ahora CADENACHAR? "<<strlen (cadenachar)<<endl<<endl;
	system("PAUSE");
	
	cout<<"Ahora vamos a ingresar en CADENASTRING: ";
	getline(cin,cadenastring);
	system("PAUSE");
	cout<<endl<<"El nuevo contenido de CADENASTRING es: "<<cadenastring<<endl;
	cout<<"Cuantos caracteres tiene ahora CADENASTRING? "<<cadenastring.size()<<endl;
	system("PAUSE");
	
	
	
	
	
}

