#include<iostream>  
#include<conio.h>
#include<math.h>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include <iomanip>

using namespace std;

void CalculoHidrografico (int &iterador,float &sumador, float &Promedio){
    //variables
    int nolluvia = 0,n,contador = 1;
    float Porcentaje = 0;
    Promedio = 0,sumador = 0;
    //variables
    cout<<"\nSemana: "<<iterador<<endl;
    while (contador<=7)
    {
        cout<<"Dia "<<contador<<": indique cantidad de milimetros de agua que cayo: "<<endl;
        cin>>n;
        if (n == 0)
        {
            nolluvia++;
            contador++;
        }else{
            sumador += n;
            contador++;
        }
    }
    
    if (nolluvia != 0)
    {
        Porcentaje = (nolluvia/(float)7) * 100;
    }
        cout<<fixed<<setprecision(2)<<"\nPorcentaje dias que no llovio: "<<Porcentaje<<endl;
    if (sumador != 0)
    {
        Promedio = sumador/7;
    }
    
    cout<<fixed<<setprecision(2)<<"promedio de llubia: "<<Promedio<<endl;


}
   
    
int main(int argc, char const *argv[])
{
    //variables
    int cantidadSemanas = 4;
    float suma,prom,PromMax = 0;
    int SumadorTotal = 0;
    //variables
    for (int i = 1; i <= cantidadSemanas; i++)
    {
        CalculoHidrografico (i,suma,prom);
        SumadorTotal +=suma;
        if (PromMax<prom)
        {
            PromMax = prom;
        }
        
    }
    

    cout<<"\nLa cantidad de lluvia caida en las ultimas 4 semanas fue de: "<<SumadorTotal<<" mm"<<endl;
    cout<<fixed<<setprecision(2)<<"El promedio maximo de lluvia fue de "<<PromMax<<"%";

    return 0;
}
