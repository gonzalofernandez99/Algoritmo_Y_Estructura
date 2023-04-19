#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<conio.h>
#include<string.h>
#include <stdio.h>
#include<C:\Users\Gonzalo\Desktop\Facultad C++\Parcial\Librerias\ManejoCaracteres.h>
//uso libreria,adjunto en el compilado. nombre: ManejoCaracteres.h

using namespace std;

#define TOPE 3
#define TOPECURSOS 1000
#define TOPMENOR 18
#define TOPMAYOR 50
struct AverSiEstudiamos
{
    int Legajo;
    char CodigoCruso;
    int edad;
}Cursos[TOPECURSOS];


void CargaFiestas(int &N_cursos,int top,char LetrasCursos[],int MenorEdad,int MayorEdad){
    int i = 0;
    bool encontre;
    cout<<"Indique Legajo: "<<endl;
    cin>>Cursos[i].Legajo;
    while (Cursos[i].Legajo!=(-1))
    {
        if (i!=0)
        {
            cout<<"Indique Legajo: "<<endl;
            cin>>Cursos[i].Legajo;
        }
        if (Cursos[i].Legajo != (-1))
        {
            fflush(stdin);
            cout<<"Indique codigo de Curso: "<<endl;
            cin>>Cursos[i].CodigoCruso;
            encontre=BusquedaSecuencial(LetrasCursos,top,Cursos[i].CodigoCruso);
            while (!encontre)
            {
                cout<<"Vuelva a indicar el curso. "<<endl;
                cin>>Cursos[i].CodigoCruso;
                encontre=BusquedaSecuencial(LetrasCursos,top,Cursos[i].CodigoCruso);
            }
                cout<<"indique la Edad: "<<endl;
                cin>>Cursos[i].edad;
                encontre=MayorOigual(Cursos[i].edad,MenorEdad,MayorEdad);
                while (!encontre)
                {
                    cout<<"Vuelva a indicar la edad. "<<endl;
                    cin>>Cursos[i].edad;
                    encontre=MayorOigual(Cursos[i].edad,MenorEdad,MayorEdad);
                }
                
                i++;
        }
        
    }
    N_cursos = i;

}

void mostrarDatos(int N_cursos1){
    cout<<"Mayores de 40. "<<endl;
    for (int i = 0; i < N_cursos1; i++)
    {
    
        if (Cursos[i].edad>40)
        {
            cout<<" Legajo: ";
            cout<<Cursos[i].Legajo<<endl;
            cout<<" Codigo: ";
            cout<<Cursos[i].CodigoCruso<<endl;
            cout<<" Edad: ";
            cout<<Cursos[i].edad<<endl;
        }
        
        
    }
    
}

void Calculos(int NumeroCursos,int Cantidad[],float &promedio,int &Mayor){
    int SumEdades = 0;
    for (int i = 0; i < NumeroCursos; i++)
    {
        if (Cursos[i].CodigoCruso=='C')
        {
            Cantidad[0]++;
        }
        if (Cursos[i].CodigoCruso=='O'){
            Cantidad[1]++;
            SumEdades +=Cursos[i].edad;
        }
        if (Cursos[i].CodigoCruso=='E')
        {
            Cantidad[2]++;
            if (Cursos[i].edad>Cursos[Mayor].edad)
            {
                Mayor = i;
            }
            
        }
        
    }

    promedio = SumEdades/Cantidad[1];
}

void mostrarUno(int Pos){
    cout<<"Incripto de mayor edad Estadiscticas: "<<endl;
    cout<<"Legajo: "<<Cursos[Pos].Legajo<<endl;
    cout<<"Codigo curso: "<<Cursos[Pos].CodigoCruso<<endl;
    cout<<"Edad: "<<Cursos[Pos].edad<<endl;
}




int main(int argc, char const *argv[])
{
    int N_curs = 0;
    char LetrasCurso[TOPE] = {'C','O','E'};
    int Cant_cursos[] = {0,0,0};
    int MayorEstadista = 0;
    float promedio = 0;
    CargaFiestas(N_curs,TOPE,LetrasCurso,TOPMENOR,TOPMAYOR);
    cout<<"muestro i: "<<N_curs;
    mostrarDatos(N_curs);
    Calculos(N_curs,Cant_cursos,promedio,MayorEstadista);
    mostrarUno(MayorEstadista);
    cout<<"El promedio de edad en Ofimatica es de: "<<promedio<<endl;
    cout<<"la cantidad de incriptos por cada curso son: "<<endl;
    cout<<"para Cirugia: "<<Cant_cursos[0]<<endl;
    cout<<"para Ofimatica: "<<Cant_cursos[1]<<endl;
    cout<<"para Estadistica: "<<Cant_cursos[2]<<endl;
    return 0;
}
