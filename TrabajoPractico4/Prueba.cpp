#include <iostream>
#include <cstdlib>
#include <string.h>
#include <iostream>

using namespace std;

#define Tope 5

struct ty_regPais{
	char	 nombrePais[30];
	float	 precio;
};

/* bool busqueda(char Dato[],ty_regPais Vec_Tel[],int topeProm){
    bool encontre = false;
    int i = 0;
    while (i<topeProm && !encontre)
    {
        if (strcmp(Vec_Tel[i].nombrePais, Dato) == 0)
        {
            encontre = true;
        }
        i++;
    }
    return encontre;
} */

int main(int argc, char const *argv[])
{
    char cad[]="Prueba";
    char Cad1[]="Otra";
    int Prueba;
    ty_regPais vecPais[5]={"Uruguay",125.70,"Bolivia", 180.30,"Chile",270,"Brasil", 350.25,"Paraguay", 147.50};

   /*  Prueba=BusquedaLibro(cad,vecPais,Tope); */
    /* cout<<Prueba; */
    bool prueba = true;
    int i = 0;
    while (prueba && i<5)
    {
        cout<<"prueba "<<i<<endl;
        i++;
        if (i>5)
        {
            prueba = false;
        }
        
    }
    
    return 0;
}
