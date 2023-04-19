#include <iostream>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <conio.h>
#define TOPER 3
#define TOPEC 3

using namespace std;


int SumaDigonlaPrincipalMatriz(int Matriz[][TOPEC],int tr,int tc){
    int Suma = 0;
    for (int i = 0; i < tr; i++)
    {
        for (int j = 0; j < tc; j++)
        {
            if (i==j)
            {
                cout<<Matriz[i][j]<<endl;
                Suma += Matriz[i][j];
            }
            
        }
        
    }
    
    return Suma;
}

void MostrarMatriz(int Matriz[][TOPEC],int tr,int tc){
    for (int i = 0; i < tr; i++)
    {
        for (int j = 0; j < tc; j++)
        {
            cout<<Matriz[i][j];
        }
        cout<<"\n";
    }
}

void CargaMatriz(int Matriz[][TOPEC],int tr,int tc){
    for (int i = 0; i < tr; i++)
    {
        for (int j = 0; j < tc; j++)
        {
            cout<<"Digite un numero["<<i<<"]["<<j<<"]: ";
            cin>>Matriz[i][j];
        }
        cout<<"\n";
    }
}

void MuestraTraspuesta(int Matriz[][TOPEC],int tr,int tc){
    for (int i = 0; i < tr; i++)
    {
        for (int j = 0; j < tc; j++)
        {
            cout<<Matriz[j][i];
        }
        cout<<"\n";
    }
}

int SumaDigonlaInversaMatriz(int Matriz[][TOPEC],int tr,int tc){
    int Suma = 0;
    int aux = tc - 1;
    for (int i = 0; i < tr; i++)
    {
        for (int j = 0; j < tc; j++)
        {
            if (j==aux)
            {
                cout<<Matriz[i][j]<<endl;
                Suma += Matriz[i][j];
                aux = aux -1;
            }
            
        }
        
    }
    
    return Suma;
}


int main(int argc, char const *argv[])
{
    int  numeros[TOPER][TOPEC] = {{1,2,3},{4,5,6},{7,8,9}};
    int Suma = 0;
    int sumaInversa= 0;
    //Suma = SumaDigonlaPrincipalMatriz(numeros,TOPER,TOPEC);
    MostrarMatriz(numeros,TOPER,TOPEC);
    //cout<<endl<<Suma<<endl;
    sumaInversa = SumaDigonlaInversaMatriz(numeros,TOPER,TOPEC);
    cout<<endl<<sumaInversa;
    //MuestraTraspuesta(numeros,TOPER,TOPEC);
    
    return 0;
}
