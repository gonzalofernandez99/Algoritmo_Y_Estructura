#include<iostream>  
#include<conio.h>
#include<math.h>
#include<cstdlib>
#include<cstdio>


using namespace std;

void IngresoNumero (int &valor){
	cout<<"Ingrese un numero: ";
	cin>>valor;
	//cout<<"Valor en el modulo contiene: "<<valor<<endl;
	//system("PAUSE");
}

void Calculo(int &sumador, int &numeros, int &iterador,float &Prom,bool &terminate){

    sumador += numeros;
    iterador++;
    Prom = sumador/iterador;

}

int main(int argc, char const *argv[])
{   
    
    int Numero,maximo,i = 0,Suma = 0;
    float promedio = 0;
    bool termino = true;
    int FinPromedio = 20;
    int MayorA = 100;
    do
    {
        if ((promedio<FinPromedio) && (i<MayorA))
        {
            IngresoNumero(Numero);
            Calculo(Suma,Numero,i,promedio,termino);
            cout<<"Iterador "<<i<<" sumador "<<Suma<<"promedio: "<< promedio<<endl;
        }else{
            termino = false;
            cout<<"Finzalizo el proceso"<<endl;
        }
        
        
    } while (termino);
    


    return 0;
}

