#include<iostream>  
#include<conio.h>
#include<math.h>
#include<cstdlib>
#include<cstdio>
/*
Ejercicio 4: Ingresar una serie de números naturales que termina con -1 e
indicar cuántas veces se interrumpe el orden ascendente y cuántos números
hay en cada grupo ordenado.
*/

using namespace std;
void IngresoNumero (int &valor){
	cout<<"Ingrese un numero: ";
	cin>>valor;
}

void CalculaInterrupcion(int &Numero, int &Interrupcion, int &cantidad,int &maximo){
if (Numero != -1)
{
  if (maximo<Numero)
{
  cantidad++;
  maximo = Numero;
}  else{
  cantidad++;
  cout<<"Hubo una cantidad de: "<<cantidad<<" valores acendentes."<<endl;
  Interrupcion++;
  maximo = Numero;
  cantidad = 0;
  }
}


}

int main(int argc, char const *argv[])
{
    //variables
    int i = 0;
    int Interrupciones=0;
    int cantidades = 0;
    int maximos,numeros;
    //variables
    
    do
    {
      IngresoNumero(numeros);
      if (i == 0)
      {
        maximos = numeros;
        i++;
      }else{
        CalculaInterrupcion(numeros,Interrupciones,cantidades,maximos);
        i++;
      }
      
    } while (numeros!=-1);
    
    if (i == 0)
    {
        cout<<"No ingreso ningun dato para comenzar el proceso."<<endl;
    }else{
        i--;
        cout<<"Se ingreso un total de: "<<i<<" datos "<<"y hubo un total de "<<Interrupciones<<" Interrupciones"<<endl;
    }
    

    return 0;
}
