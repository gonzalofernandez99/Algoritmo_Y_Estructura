#include<iostream>  
#include<conio.h>
#include<math.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int Numero1,Numero2;
    int N1,N2;

    cout<<"Por favor ingrese el primer numero para comenzar la serie."<<endl;
    cin>>Numero1;
    cout<<"Por favor ingrese el segundo numero para la serie."<<endl;
    cin>>Numero2;

    N1 = Numero1;
    N2 = Numero2;
    if (Numero1 == Numero2)
    {
        cout<<"La serie de los dos numeros ingresados es siemplemente el mismo valor: "<<Numero1<<endl;
    }
    //validacion para que no falle cuando el primer numero es mas grande que el segundo.
    if (Numero1>Numero2)
    {
        N2 = Numero1;
        N1 = Numero2;
    }
    

    if (Numero1 != Numero2)
    {    
        cout<<"Comienza serie: ";
    
        for (int i = N1 - 1; i < N2; i++)
        {
            //se le agrega esta validacion para sacar el " - " del ultimo numero sino quedaria 1 - 2 - 3 - y con la validacion queda 1 - 2 - 3. 
            if (N1<N2){
                cout<<N1<<" - ";
                N1++;
            }else{
                cout<<N1;
                N1++;
            }
            

        }
        
        
    }
    
    
    return 0;
}
