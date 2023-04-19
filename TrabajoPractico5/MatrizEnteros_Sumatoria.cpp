/*ESTE EJEMPLO REALIZA:
1- LA SUMA DE LOS ELEMENTOS DE UNA MATRIZ DE ENTEROS,DE topeFila CANTIDAD DE FILAS 
Y topeColumna CANTIDAD DE COLUMNAS.
2- LA SUMA DE LOS ELEMENTOS DE UNA FILA ESPECÍFICA */

#include <iostream>
#include <iomanip> 
/*La biblioteca iomanip: io-> entrada/salida y manip-> manipulación; permite
la maniputación del formato de las entradas cin y salidas cout. 
En este caso, en la función "void MostrarMatriz(int matriz[topeFila][topeColumna])" 
se invoca a setw(n) para darle a la matriz un formato en cuadricula, con el objetivo
que uds. puedan visualizar con claridad las filas y las columnas (independientemente 
de la longitud de los enteros ingresados). A futuro no es necesario que muestren
los datos de una matriz de este modo; generalmente se muestra un dato a 
continuación del anterior. 
El uso de setw(n) se explica más adelante como comentario*/

//Podia definirse un sólo tope asoacido a 3.
#define topeFila 3
#define topeColumna 3
using namespace std;
void IngresarMatriz(int matriz[topeFila][topeColumna]);
void InicializarMatriz(int matriz[topeFila][topeColumna]);
void MostrarMatriz(int matriz[topeFila][topeColumna]);
int SumarElementosMatriz(int matriz[topeFila][topeColumna]);
int SumarFilaMatriz(int matriz[topeFila][topeColumna],int fila);
int IngresarFilaValida();

int main()
{
int A[topeFila][topeColumna];
int numeroFila;
InicializarMatriz(A);
//MostrarMatriz(A);
cout<<"Ingresar matriz A de "<<topeFila<<"X"<<topeColumna<<endl;
IngresarMatriz(A);
cout<<"Matriz A ingresada"<<endl;
MostrarMatriz(A);
cout<<"Sumatoria de todos los elementos de A"<<endl;
cout<<"La suma total es: "<<SumarElementosMatriz(A)<<endl;
cout<<"Sumatoria de una fila en particular de A"<<endl;
numeroFila=IngresarFilaValida();
cout<< "La suma de la fila "<<numeroFila<<" es: "<<SumarFilaMatriz(A,numeroFila);
return 0;
}

void InicializarMatriz(int matriz[topeFila][topeColumna])
{
	for(int i=0;i<topeFila;i++)
	{
		for (int j=0;j<topeColumna;j++)
		{
			matriz[i][j]=0; 
		}
	}
}

void IngresarMatriz(int matriz[topeFila][topeColumna])
{
	for(int i=0;i<topeFila;i++)
	{
		for (int j=0;j<topeColumna;j++)
		{
			cout<<"Elemento "<<i<<" "<<j<<": "<<endl;
			cin>>matriz[i][j]; 
		}
		cout<<endl;
	}
}

void MostrarMatriz(int matriz[topeFila][topeColumna])
{
	for(int i=0;i<topeFila;i++)
	{
		for (int j=0;j<3;j++)
		{
			cout<<setw(10)<<matriz[i][j];
			/*La función setw(10) setea el ancho de una salida a 10 caracteres (con
			alineación derecha). De este modo, al mostrar cada elemento de la matriz,
			se define su ancho como 10 y todas las columnas quedan alineadas. Como
			les dije en un comentario anterior, no es necesario que lo planteen así
			pero al empezar con matrices les "ayuda" a entender su estructura*/
		}
		cout<<endl;
	}
}

int SumarElementosMatriz(int matriz[topeFila][topeColumna])
{
	int suma=0;
	for(int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			suma=suma+matriz[i][j];
		}
	}
	return suma;
}

int IngresarFilaValida()
{
	int fila;
	do
	{
	cout << "Ingresar una fila (entre 0 y "<< topeFila-1 <<"):";
	cin >> fila;
	}while(fila<0||fila>=topeFila);
	return fila;	
}

int SumarFilaMatriz(int matriz[topeFila][topeColumna],int fila)
{
	int suma=0;
	for(int j=0;j<3;j++)
		suma=suma+matriz[fila][j];
	return suma;
}


