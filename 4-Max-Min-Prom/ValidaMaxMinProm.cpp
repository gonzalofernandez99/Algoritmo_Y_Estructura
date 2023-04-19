#include<iostream>  
#include<conio.h>
#include<math.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int i;
    float Numero,Max,Min,Promedio,Sumador = 0;
    i=1;

    cout<<"Recuerda que al digitar el valor de -1 el Programa se detendra y calculara el resultado."<<endl;
    cout<<"Por favor digite el primer numero: ";
    cin>>Numero;
    Max = Numero;
    Min = Numero;


    while(Numero!=-1){
        i++;
        Sumador += Numero;

        if (Numero>Max)
        {
            Max = Numero;
        }
        if (Numero<Min)
        {
            Min = Numero;
        }
            cout<<"Digite otro numero: "<<endl;
            cin>>Numero;

    }
    if (i==1)
    {
       cout<<endl<<"No ingreso ningun valor Valido, Saludos!";
    }
    else{
        Promedio = Sumador/i;
        cout.precision(3);
        cout<<"El numero maximo es: "<<Max<<endl<<"El numero minimo es: "<<Min<<endl<<"Se ingreso un total de: "<<i<<" Numeros"<<endl<<"La suma de todos fue de: "<<Sumador<<endl<<"Y el promedio fue de: "<<Promedio<<endl;
    }
    
    return 0;
}
