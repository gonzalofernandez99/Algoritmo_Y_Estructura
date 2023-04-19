#include<iostream>  

using namespace std;

int main(int argc, char const *argv[])
{
    int Numero1,Numero2;
    cout<<"Escriba dos numeros para comparar: ";
    cin>>Numero1>>Numero2;

    if(Numero1==Numero2){
        cout<<"Ambos numero tienen el mismo valor";
    }
    else if(Numero1>Numero2){
        cout<<Numero1<<" Es Mayor a numero "<<Numero2;
    }
    else{
        cout<<Numero2<<" Es mayor a numero "<<Numero1;
    }


    return 0;
}
