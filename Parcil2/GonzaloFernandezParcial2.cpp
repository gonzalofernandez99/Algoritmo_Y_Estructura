#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iomanip> 

using namespace std;
#define TOPEPORCENTAJE 15
#define TOPESECTORES 8
#define TOPEPROYECTOS 9
//TopeChars
#define TOPENOMBRE 31
#define TOPEONG 26
//matriz
#define TOPEROW 4
#define TOPECOLUM 8

struct tyProyectos
{
	char Nombre[TOPENOMBRE];
	int Tipo;
	char Ong[TOPEONG];
};

struct tySector{
	string nombreSector;
	int cantidadEmp;
};

struct tyInforme
{
	string Sector;
	int Proyecto;
	float Importe;
};

struct tyManaCola{
	float porcentaje;
	float importe;
};


void CargarVectorTipo(tyProyectos Proyecto,char arch[],tyProyectos Vec_Proyecto[],int &top,int TopeRegistros){
    ifstream archivoB;
    int largo;
    largo = sizeof(Proyecto);
    top = 0;
    archivoB.open(arch,ios::in | ios::binary);

     if(archivoB.fail()){
        cout<<"no se puede crear el archivo";
        exit(1);
    }

    while ((!archivoB.eof()) && top<TopeRegistros)//recorre mientras el archivo no este vacio
    {
        archivoB.read((char *)&Proyecto,largo);
        if (!archivoB.eof())
        { 
            Vec_Proyecto[top] = Proyecto;
            top++;
        }
        
    }
    
    archivoB.close();
    
}

bool BusquedaSecuencial(tySector Arreglo[],int tope,string dato,int &i){
	bool encontre = false;
	i = 0;
	while (i<tope && !encontre)
	{
		if (Arreglo[i].nombreSector==dato)
		{
			encontre=true;
		}else{
			i++;
		}
		
	}
	return encontre;
}

void ingreso(tyInforme &Informe){
    fflush(stdin);
    cout<<"Indicar F si quiere finalizar el programa"<<endl;
    cout<<"Indique sector al que aporta: "<<endl;
	cin>>Informe.Sector;
    if (Informe.Sector != "F")
    {
        cout<<"indique proyecto que desea apoyar: "<<endl;
	    cin>>Informe.Proyecto;
        cout<<"indique importe mayor a 0: "<<endl;
	    cin>>Informe.Importe;
    }
    
    

}

bool Valida(tyInforme Informe,tySector Sector[],int topeSector,int &Indice){
    bool Correcto = true;

    if (!((Informe.Proyecto>=1)&&(Informe.Proyecto<=9)))
	{
		Correcto = false;
        cout<<"Dato mal ingresado: "<<Informe.Proyecto<<endl;
	}
    if (!(BusquedaSecuencial(Sector,topeSector,Informe.Sector,Indice)))
    {
        Correcto = false;
        cout<<"Dato mal ingresado: "<<Informe.Sector<<endl;
    }
    if (Informe.Importe<=0)
    {
        Correcto = false;
        cout<<"Dato mal ingresado: importe -> "<<Informe.Importe<<endl;
    }
    
    return Correcto;
}

float PorcentajeAportaEmpresa(float importe,float porcentaje,float &Total){
    float PorcentajeEmpresa;
    PorcentajeEmpresa = ((porcentaje*importe)/(float)100);
    cout<<"\nLa empresa debe aportar: "<<PorcentajeEmpresa<<endl;
    Total = PorcentajeEmpresa + importe;
    cout<<"Total "<<Total<<endl;
    return PorcentajeEmpresa;
}

void CargaMatriz(float Total,tyManaCola Matriz[TOPEROW][TOPECOLUM],float porcentaje,int Indice_Fila,int Indice_Columna){
    Matriz[Indice_Fila][Indice_Columna].importe += Total;
    Matriz[Indice_Fila][Indice_Columna].porcentaje += porcentaje;
}


void InicializarMatriz(tyManaCola matriz[TOPEROW][TOPECOLUM])
{
	for(int i=0;i<TOPEROW;i++)
	{
		for (int j=0;j<TOPECOLUM;j++)
		{
			matriz[i][j].importe=0; 
			matriz[i][j].porcentaje=0;
		}
	}
}

void PorTipoProyecto(tyManaCola matriz[TOPEROW][TOPECOLUM],tySector Sector[])
{
    int indice = 0;
	for(int i=0;i<TOPECOLUM;i++)
	{
		for (int j=0;j<TOPEROW;j++)
		{
			cout<<"Tipo de proyecto: "<<j<<" Sector: "<<Sector[indice].nombreSector<<" aporto: "<<matriz[j][i].importe<<" la empresa tiene que aportar: "<<matriz[j][i].porcentaje<<endl;
			
		}
        indice++;
	}
}


void minimoAportadoPorsecotr(tyManaCola matriz[TOPEROW][TOPECOLUM],tySector Sector[]){
	float min = 0;
    int int_aux;
	string aux;

	for(int i=0;i<TOPECOLUM;i++)
	{
        min = 0;
		for (int j=0;j<TOPEROW;j++)
		{
            aux = Sector[i].nombreSector;
            if (matriz[j][i].importe != 0)
            {
                if (min != 0)
                {
                    if (matriz[j][i].importe<min)
                    {
                        min = matriz[j][i].importe;
                        int_aux = j;
                    }
                 
                }else
                {
                    min = matriz[j][i].importe;
                    int_aux = j;
                }
            
            
		    }
        }
		if (min != 0)
		{
			cout<<"\nTipo de proyecto: "<<int_aux<<" Sector "<<aux<<" minimo aporte "<<min<<endl;
		}else
		{
			cout<<aux<<" no tuvo aportes "<<endl;
		}
		
	    
    }
}

void MuestraImportePorProyecto(int Importes[],tyProyectos Vec_Proyecto[],int tope){
    for (int i = 0; i < tope; i++)
    {
        cout<<"\n"<<Vec_Proyecto[i].Nombre<<" La empresa aporta "<<Importes[i]<<endl;
    }
    
}

int main(int argc, char const *argv[])
{
	tyProyectos Vec_Proyecto[TOPEPROYECTOS];
	tySector vecSectores[TOPESECTORES]= {"Contaduria", 14, "Deposito", 9, "Ventas", 11, "Administracion", 12, 
											"Despacho", 7, "Sistemas", 10, "Atencion al Cliente", 12, "Compras", 6 };
	tyProyectos Proyecto;
	tyInforme Informe;
    int Vec_ImporteProyecto[TOPEPROYECTOS] ={0,0,0,0,0,0,0,0,0};
	//Contadores
	int CantProyectos;
	int Indice;
    float Total;
    float Porcentaje;
	char ArchivoProyecto[]="proyectos.dat";
	//matriz
	tyManaCola Matriz[TOPEROW][TOPECOLUM];
	//CargoVector
	bool Validado;

	CargarVectorTipo(Proyecto,ArchivoProyecto,Vec_Proyecto,CantProyectos,TOPEPROYECTOS);
	InicializarMatriz(Matriz);

    ingreso(Informe);

    while (Informe.Sector != "F")
    {
        Validado=Valida(Informe,vecSectores,TOPESECTORES,Indice);

        if (Validado)
        {
        
            Porcentaje=PorcentajeAportaEmpresa(Informe.Importe,TOPEPORCENTAJE,Total);
            CargaMatriz(Total,Matriz,Porcentaje,Vec_Proyecto[Informe.Proyecto-1].Tipo,Indice);
            Vec_ImporteProyecto[Informe.Proyecto-1] += Porcentaje;

        }else{
            cout<<"Los datos no fueron validados correctamente "<<endl;
        }

        ingreso(Informe);
    }
    
    PorTipoProyecto(Matriz,vecSectores);
    minimoAportadoPorsecotr(Matriz,vecSectores);
	MuestraImportePorProyecto(Vec_ImporteProyecto,Vec_Proyecto,CantProyectos);
    
	
	return 0;
}
