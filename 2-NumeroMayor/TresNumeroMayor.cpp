#include<iostream>  

using namespace std;

int main(int argc, char const *argv[])
{
    int Numero1,Numero2,Numero3;
    cout<<"Escriba Tres numeros para comparar: ";
    cin>>Numero1>>Numero2>>Numero3;

    if ((Numero1>Numero2)&&(Numero1>Numero3))
    {
        cout<<"\nEl numero mayor es: "<<Numero1<<endl;
    }
    else if ((Numero2>Numero1)&&(Numero2>Numero3))
    {
        cout<<"\nEl numero mayor es: "<<Numero2<<endl;
    }
    else if ((Numero3>Numero1)&&(Numero3>Numero2)){
        cout<<"\nEl numero mayor es: "<<Numero3<<endl;
    }
    else
    {
        cout<<"\nTodos los numeros son iguales"<<endl;
    }
    


    return 0;
}