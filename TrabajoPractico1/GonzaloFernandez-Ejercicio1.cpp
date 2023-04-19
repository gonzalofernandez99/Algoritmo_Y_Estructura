#include<iostream>  
#include<conio.h>
#include<math.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int Numero;
    int Multiplicacion;
    int i;
    do{

        cout<<"Ingrese un numero: "<<endl;cin>>Numero;

    }while((Numero<1)||(Numero>10));

    for (i = 1; Multiplicacion < 100; i++)
    {
        Multiplicacion = i*Numero;
        cout<<Numero<<" * "<<i<<" = "<<Multiplicacion<<endl;
    }
    
    for (i = i -1; Multiplicacion > 0; i--)
    {
        Multiplicacion = i*Numero;
        cout<<Numero<<" * "<<i<<" = "<<Multiplicacion<<endl;
    }
    
    return 0;
}
