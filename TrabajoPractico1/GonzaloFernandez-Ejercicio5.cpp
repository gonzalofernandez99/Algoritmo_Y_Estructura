#include<iostream>  
#include<conio.h>
#include<math.h>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include <iomanip>

/*
Ejercicio 5: Ingresar N juegos de N1 valores enteros cada uno, donde N se
informa al comienzo y N1 al cargar cada juego. Emitir el número del juego con
promedio más alto y la suma total de todos los juegos.
*/

using namespace std;
void IngresoNumero (int &valor){
	cout<<"Ingrese un numero: ";
	cin>>valor;
}

void CalculoJuegos(int &sumaTotal, float &promedioMax,int &Nmayor){
    //variables
    int Cantidad,valoresCartas = 20,dato,iterador=1;
    float promedio;
    //variables

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
    promedio = sumaTotal/(float)Cantidad;
    cout<<fixed<<setprecision(2)<<"El promedio: "<<promedio<<endl;
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
    //variables
    float MaxPromedios = 0;
    int numero,total,NumeroMayor,Sumado = 0;
    //variables

    cout<<"Ingre la cantidad de N de juegos, no se permiten nuemeros negativos ni nulos."<<endl;
    
    IngresoNumero(numero);
    
    if (numero>0)
    {
        for (int i = 0; i < numero; i++)
        {
            CalculoJuegos(total,MaxPromedios,NumeroMayor);
            Sumado +=total;
        }
    cout<<fixed<<setprecision(2)<<"El promedio mas alto fue: "<<MaxPromedios<<" del juego numero "<<NumeroMayor<<" suma total de todos los juegos = "<<Sumado<<endl;   
    }else{
        cout<<"Ingreso un valor invalido."<<endl;
    }

    
    
    return 0;
}
