#include<iostream>  
#include<conio.h>
#include<math.h>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include <iomanip>
#include<cstring>

using namespace std;

#define TOPE 20

void ContarChar(char Palabra[],int &Qchar){
	Qchar=0;
	bool Biterador = true;
    while (Biterador)
    {
        if (Palabra[Qchar] == '\0')
        {
            Biterador = false;
        }else{
            Qchar ++;
        }
        
        
    }
    
	cout<<"La palabra tiene: "<<Qchar<<" Caracteres"<<endl;
}

int main(int argc, char const *argv[])
{
    char Cad[TOPE]= "Probando un poco";
    int CantidadCaracteres = 0;

    ContarChar(Cad,CantidadCaracteres);
    cout<<strlen(Cad)<<endl;

    return 0;
}
