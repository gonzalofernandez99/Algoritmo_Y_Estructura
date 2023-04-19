#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<conio.h>
#include<string.h>

using namespace std;

#define TOPE 5

struct tyAlumno
{
    string tyAlumno;
    int tyedad;
};

void verMaxMin(tyAlumno S_alum[],int tope,int MinMax[]){
    int i = 0;
    //MinMax[1] = Maximo --- MinMax[0] = Minimo
    for (i; i < tope; i++)
    {
        if (S_alum[i].tyedad<S_alum[MinMax[0]].tyedad)
        {
            MinMax[0] = i;
        }
        if (S_alum[i].tyedad>S_alum[MinMax[1]].tyedad)
        {
            MinMax[1] = i;
        }
           
    }

}

void MostrarResultado(tyAlumno S_alu[],int MiMax[]){
    //MiMax[1] = Maximo --- MiMax[0] = Minimo
    cout<<S_alu[MiMax[0]].tyAlumno<<" Tiene "<<S_alu[MiMax[0]].tyedad<<" y es el/la menor."<<endl;
    cout<<S_alu[MiMax[1]].tyAlumno<<" Tiene "<<S_alu[MiMax[1]].tyedad<<" y es el/la mayor."<<endl;
}

int main(int argc, char const *argv[])
{
    //MaximoMinimo[1] = Maximo --- MaximoMinimo[0] = Minimo
    int MaximoMinimo[] = {0,0};
    tyAlumno VectAlumno[] = {"Pedro",28,"Juan",23,"Maria",50,"Marcos",21,"ceci",2};   

    verMaxMin(VectAlumno, TOPE,MaximoMinimo);
    MostrarResultado(VectAlumno,MaximoMinimo);
    return 0;
}


