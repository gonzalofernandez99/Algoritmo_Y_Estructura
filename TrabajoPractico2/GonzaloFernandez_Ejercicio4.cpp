#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include<string.h>

using namespace std;


#define topChar 200

void IngresoParrafo(char cadch[],int topCarac,int &CantCarct){
	CantCarct = 0;
	cout<<"Ingrese un parrafo que no supere los 200 caracteres: "<<endl;
    gets(cadch);
	CantCarct = strlen(cadch);

	while (CantCarct>topCarac || CantCarct == 0)
	{
		if (CantCarct == 0)
		{
			cout<<"No ingreso ningun caracteres, vuelva a intentarlo: "<<endl;
			gets(cadch);
			CantCarct = strlen(cadch);
			cout<<CantCarct<<endl;
		}else{
			cout<<"Ingreso mas de 200 caracteres, vuelva intentarlo: "<<endl;
			gets(cadch);
			CantCarct = strlen(cadch);
			cout<<CantCarct<<endl;
			}
		
		
	}
	
	system("PAUSE");
}

void busquedaSecuencial(int Cant, char Palabras[],int &n_Palabras){
	int i = 0;
	int DobleSpace = 1;
	n_Palabras = 0;
	int n_Letras = 0;
	while (i<Cant)
	{
		// cout<<Palabras[i]<<endl; //Sacar comentario si se quiere ver letra por letra como se cargaron las palabras
		if (Palabras[i] == ',' || Palabras[i] == ':' ||Palabras[i] == '.' ||Palabras[i] == ';' ||Palabras[i] == '?' ||Palabras[i] == '!' ||Palabras[i] == '#')
		{
			i++;

		}else if (Palabras[i] == ' ')
		{
			if (DobleSpace == 1)
			{
				i++;
				n_Palabras++;
				cout<<"En la palabra: "<<n_Palabras<<" Hubo "<<n_Letras<<" letras "<<endl;
				n_Letras = 0;
			}
			
			

		}else{
			DobleSpace = 1;
			n_Letras ++;
			i++;
		}
		
	}
	n_Palabras++;
	cout<<"En la palabra: "<<n_Palabras<<" Hubo "<<n_Letras<<" letras "<<endl;


	
}


int main(int argc, char const *argv[])
{
	char parrafo[topChar];
	int CantCar = 0;
	int n_palabras = 0;
	IngresoParrafo(parrafo,topChar,CantCar);
	busquedaSecuencial(CantCar,parrafo,n_palabras);
	cout<<"En total hubo: "<<n_palabras<<" Palabras."<<endl;
    return 0;
}
