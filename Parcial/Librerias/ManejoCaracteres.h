#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<conio.h>
#include<string.h>

using namespace std;

void CargaCaracter(char Cadena[],int Top){
    int i = 0;
    cout<<"Ingrese nuevo contenido en CADENACHAR: ";
	cin.getline(Cadena, Top); 
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
	return q;
}

bool CaracterConsecutivo(char CadConse[],int tope,char letra1,char letra2){
	int i=0;
	bool Encontre = false;
	while (i<tope&&CadConse[i]!='\0'&&!Encontre)
	{
		if (CadConse[i]==letra1)
		{
			if (CadConse[i+1]==letra2)
			{
				Encontre = true;
				//break;
			}
			
		}
		i++;
	}

	return Encontre;
	
}

bool CaracterNoConsecutivo(char CadNconsec[],int tope,char letra1,char letra2){
	int i=0;
	bool Encontre = false;
	bool encontrePrimero = false;
	while (i<tope&&CadNconsec[i]!='\0'&&!Encontre)
	{
		if (CadNconsec[i]==letra1)
		{
			encontrePrimero = true;
		}
		if (encontrePrimero)
			{
				Encontre = true;
				//break;
			}
		i++;
	}

	return Encontre;
	
}

bool BusquedaSecuencial(char cadena[],int tope,char dato){
	bool encontre = false;
	int i = 0;
	while (i<tope&&cadena[i]!='\0'&&!encontre)
	{
		if (cadena[i]==dato)
		{
			encontre=true;
		}
		i++;
	}
	return encontre;
}

//buscarVocales

void BusquedaVectores(char Cadena[],char Busqueda[],int contador[],int tope,int tope1){
	int i = 0,j = 0;
	bool encontre = false;
	while (i<tope&&Cadena[i]!='\0')
	{
		while (j<tope1&&Busqueda[j]!='\0'&&!encontre)
		{
			if (Cadena[i]==Busqueda[j])
			{
				encontre = true;
				contador[j]++;
			}
			j++;
		}
		i++;
		j=0;
		encontre = false;
		
	}
	
}

bool MayorOigual(int x,int y, int z){
	bool encontre = false;
	if (x>=y && x<=z)
	{
		encontre = true;
	}
	return encontre;

}

