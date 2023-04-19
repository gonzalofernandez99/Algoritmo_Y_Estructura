#include<iostream>  

using namespace std;

int main(int argc, char const *argv[])
{
    int Numero1,Numero2,Numero3;
    cout<<"Escriba Tres numeros para comparar: ";
    cin>>Numero1>>Numero2>>Numero3;


    
    if ((Numero1>=Numero2)&&(Numero1>=Numero3))
    {
        if (Numero2>=Numero3){
            cout<<"\nOrdenados de mayor a menor: N1 - "<<Numero1<<" N2 - "<<Numero2<<" N3 - "<<Numero3;
        }   
        else{
            cout<<"\nOrdenados de mayor a menor: N1 - "<<Numero1<<" N3 - "<<Numero3<<" N2 - "<<Numero2;
        }
    }
    else if ((Numero2>=Numero1)&&(Numero2>=Numero3))
    {
        if (Numero1>=Numero3){
            cout<<"\nOrdenados de mayor a menor: N2 - "<<Numero2<<" N1 - "<<Numero1<<" N3 - "<<Numero3;
        }   
        else{
            cout<<"\nOrdenados de mayor a menor: N2 - "<<Numero2<<" N3 - "<<Numero3<<" N1 - "<<Numero1;
        }
    }
    else if ((Numero3>=Numero1)&&(Numero3>=Numero2)){
        if (Numero1>=Numero2){
            cout<<"\nOrdenados de mayor a menor: N3 - "<<Numero3<<" N1 - "<<Numero1<<" N2 - "<<Numero2;
        }   
        else{
            cout<<"\nOrdenados de mayor a menor: N3 - "<<Numero3<<" N2 - "<<Numero2<<" N1 - "<<Numero1;
        }
    }
    else
    {
        cout<<"\nTodos los numeros son iguales"<<endl;
    }
    


    return 0;
}