#include<iostream>  
#include<conio.h>
#include<math.h>
#include<cstdlib>
#include<cstdio>


using namespace std;
void IngresoNumero (float &valor1,float &valor2,char &Operadores){
	cout<<"Ingrese el operador";
    cin>>Operadores;
    cout<<"Ingrese el primer valor";
	cin>>valor1;
    cout<<"Ingrese el segundo valor";
	cin>>valor2;
}
void IngresoNumero (float &V1,float &V2,char &OP,float &res,int &val){
    switch (OP)
    {
    case '+':
        res = V1 + V2;
        val = 1;
        break;
    case '-':
        res = V1 - V2;
        val = 1;
    break;
    case '*':
        res = V1 * V2;
        val = 1;
    break;
    case '/':
        res = V1 / V2;
        val = 1;
        break;
    
    default:
        val = 0;
        break;
    }

}


int main(int argc, char const *argv[])
{
    char operador;
    float resultado,x,y;
    int valido = 1;
    do
    {
        IngresoNumero(x,y,operador);
        IngresoNumero(x,y,operador,resultado,valido);
        if (valido)
        {
            cout<<"el resultado de la operacion es: "<<resultado<<endl;
        }else{
            cout<<"no ingreso un operador valido, vuelva a intentarlo o precione f para finalizar"<<endl;
        }
        

    } while (operador != 'f');
    
    cout<<"Finalizo el proseso."<<endl;

    return 0;
}
