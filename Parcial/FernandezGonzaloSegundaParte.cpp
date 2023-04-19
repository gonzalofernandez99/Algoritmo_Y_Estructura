#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<conio.h>
#include<string.h>
#include<C:\Users\Gonzalo\Desktop\Facultad C++\Parcial\Librerias\ManejoCaracteres.h>
//uso libreria,adjunto en el compilado. nombre: ManejoCaracteres.h

using namespace std;

#define TOPE 20
#define TOPE2 5


int main(int argc, char const *argv[])
{
	char a[TOPE];
	bool encontro = false;
	bool encontroNoconsecutivo = false;
	bool encontre = false;
	int ContadorVect[TOPE2] = {0,0,0,0,0};
	char vocales[TOPE2] = {'a','e','i','o','u'};
	CargaCaracter(a,TOPE);
	
	/* encontro=CaracterConsecutivo(a,TOPE,'a','b');
	if (encontro)
	{
		cout<<"encontro consecutivo"<<endl;
	}else
	{
		cout<<"no encontro nada consecutivo"<<endl;
	}
	
	encontroNoconsecutivo=CaracterNoConsecutivo(a,TOPE,'a','b');

	if (encontroNoconsecutivo)
	{
		cout<<"encontro no consecutivo"<<endl;
	}else
	{
		cout<<"no encontro nada no consecutivo"<<endl;
	}
	encontre=BusquedaSecuencial(a,TOPE,'z');
	if (encontre)
	{
		cout<<"encontre";
	}else
	{
		cout<<"no encontre.";
	} */
	
	BusquedaVectores(a,vocales,ContadorVect,TOPE,TOPE2);
	
	for (int i = 0; i < TOPE2; i++)
	{
		cout<<"letra "<<vocales[i]<<" cantidad q aparece: "<<ContadorVect[i]<<endl;
	}
	
	//cout<<"Muestra char: "<<a;
	return 0;
}


//Encontrar caracter y encontrar caracter simultanio