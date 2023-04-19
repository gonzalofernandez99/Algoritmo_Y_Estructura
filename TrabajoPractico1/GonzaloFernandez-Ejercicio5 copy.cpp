#include<iostream>  
#include<conio.h>
#include<math.h>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include <iomanip>

using namespace std;
void IngresoNumero (int &valor){
	cout<<"Ingrese un numero: ";
	cin>>valor;
}

void CalculoJuegos(int &Cantidad,int &sumaTotal,float &promedio, float &promedioMax,int &Nmayor, int &valoresCartas,int dato,int &iterador){
    
    
    cout<<"Indique la cantidad de numeros del juego: "<<endl;
    cin>>Cantidad;
    cout<<" Cantidad es: "<<Cantidad<<endl;
    cout<<"Las cartas que te tocaron fueron: "<<endl;
    sumaTotal = 0;

    srand(time(0)); //cambiar el algoritmo de alatoriedad

    for (int i = 1; i <=Cantidad; i++)
    {
        dato = 1+(rand()%valoresCartas);
        cout<<i<<"° Carta: "<<dato<<endl;
        sumaTotal +=dato;
    }
    promedio = sumaTotal/Cantidad;
    cout<<"El promedio: "<<promedio<<endl;
    if (promedioMax<promedio)
    {
        Nmayor = iterador;
        promedioMax = promedio;
        iterador++;
    }else{
        iterador++;
    }
    
    cout<<"Suma total: "<<sumaTotal<<endl;
}

int main(int argc, char const *argv[])
{
    float Promedios,MaxPromedios = 0;
    int numero,cantidades,Cartas = 20,total,NumeroMayor,ValoresCartas,datos,iteradores = 1,Sumado = 0;

    cout<<"Ingre la cantidad de N de juegos, no se permiten nuemeros negativos ni nulos."<<endl;
    
    IngresoNumero(numero);
    
    if (numero>0)
    {
        for (int i = 0; i < numero; i++)
        {
            CalculoJuegos(cantidades,total,Promedios,MaxPromedios,NumeroMayor,Cartas,datos,iteradores);
            Sumado +=total;
        }
        
    }else{
        cout<<"Ingreso un valor invalido."<<endl;
    }

    cout<<"El promedio mas alto fue: "<<MaxPromedios<<" del juego numero "<<NumeroMayor<<" suma total de todos los juegos= "<<Sumado<<endl;
    
    return 0;
}
