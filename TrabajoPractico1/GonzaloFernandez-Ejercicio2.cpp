#include<iostream>  
#include<conio.h>
#include<math.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int i = 0,Mayor,MenoresTotal = 0,LaboralTotal = 0,Numero;

    cout<<"Por favor indique la edad del usuario: "<<endl;
    cin>>Numero;

        while (Numero<(-1)){
            cout<<"Por favor indique una edad validad o precione -1 para finalizar. "<<endl;
            cin>>Numero;
        }
            


    while (Numero!=-1){
        i++;   
        if (Numero>Mayor)
        {
            Mayor = Numero;
        }
        if (Numero<=17)
        {
            MenoresTotal++;
        }else if (Numero<=65)
        {
            LaboralTotal++;
        }else{
            cout<<"Se jubilo o esta por jubilarse ya que tiene "<<Numero<<" años de edad"<<endl;
        }

            cout<<"Por favor indique otra edad: "<<endl;
            cin>>Numero;
             while (Numero<(-1)){
                cout<<"Por favor indique una edad validad o precione -1 para finalizar. "<<endl;
                cin>>Numero;
            }
    }
    
    if (i==0)
    {
        cout<<"No ingreso ningun valor valido para comenzar el proceso."<<endl;
    }else{
        cout<<"Se ingreso una cantidad de "<<i<<" Edades"<<endl<<"El mayor es: "<<Mayor<<endl<<"La cantidad de menores de edad son: "<<MenoresTotal<<endl<<"La cantidad de personas que estan en edad laboral activa son: "<<LaboralTotal<<endl;
    }
    
    

    return 0;
}
