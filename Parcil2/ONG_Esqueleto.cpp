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
#define TOPENOMBRE 30
#define TOPEONG 25
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

string mostrarOpcionNoValida(int opciones){
    string Mostrar;
    Mostrar = "La Opcion "+to_string(opciones)+" No es valida, vuelva a intentar.";
    return Mostrar;
}

void CargarVectorTipo(tyProyectos Proyecto,char arch[],tyProyectos Vec_Proyecto[],int &top){
    ifstream archivoB;
    int largo;
    largo = sizeof(Proyecto);
    top = 0;
    archivoB.open(arch,ios::in | ios::binary);

     if(archivoB.fail()){
        cout<<"no se puede crear el archivo";
        exit(1);
    }

    while (!archivoB.eof())//recorre mientras el archivo no este vacio
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


void IngresoDatos(tyInforme Informe,tySector Sector[],int topeSector,tyManaCola Matriz[TOPEROW][TOPECOLUM],float porcentaje,tyProyectos proyecto[]){
	bool bool_Sector;
	bool bool_Proyecto = false;
	bool bool_importe = false;
	int Indice;
	float PorcentajeEmpresa;
	fflush(stdin);
do
{
	cout<<"Indique sector al que aporta: "<<endl;
	cin>>Informe.Sector;
	bool_Sector = BusquedaSecuencial(Sector,topeSector,Informe.Sector,Indice);
	cout<<bool_Sector;
} while (!bool_Sector);

do
{
	cout<<"indique proyecto que desea apoyar: "<<endl;
	cin>>Informe.Proyecto;
	if ((Informe.Proyecto>=1)&&(Informe.Proyecto<=9))
	{
		bool_Proyecto = true;
	}
	
} while (!bool_Proyecto);

do
{
	cout<<"indique importe mayor a 0: "<<endl;
	cin>>Informe.Importe;
	if (Informe.Importe>0)
	{
		bool_importe = true;
	}
} while (!bool_importe);


	//calculo porcentaje
	int numero = Informe.Proyecto;
	int i = proyecto[numero].Tipo;
	PorcentajeEmpresa = ((porcentaje*Informe.Importe)/(float)100);
	cout<<"La empresa va a tener que aportar: "<<PorcentajeEmpresa<<endl;
	Matriz[i][Indice].importe=+Informe.Importe;
	Matriz[i][Indice].porcentaje=+PorcentajeEmpresa;

}

int ingresoOpcion(){
	int opcion;
	fflush(stdin);
	cout<<"indique la opcion"<<endl;
	cin>>opcion;
	return opcion;
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

void MostrarMatriz(tyManaCola matriz[TOPEROW][TOPECOLUM],tySector Sector[])
{
	int TotalporSector; 
	/* int aux=0; */
	for(int i=0;i<TOPEROW;i++)
	{
		/* TotalporSector = 0; */
		for (int j=0;j<TOPECOLUM;j++)
		{
			cout<<"Tipo de producto "<<i + 1<<" Sector "<<Sector[j].nombreSector<<" aporto: "<<matriz[i][j].importe<<" la empresa tiene que aportar: "<<matriz[i][j].porcentaje;
			/* TotalporSector +=matriz[i][j].importe; */
			/* aux = j; */
		}
		/* cout<<"\n"<<"Recaudacion total en el sector "<<Sector[aux].nombreSector<<" TOTAL: "<<TotalporSector;
		cout<<endl; */
	}
}
void minimoAportadoPorsecotr(tyManaCola matriz[TOPEROW][TOPECOLUM],tySector Sector[]){
	float min = -1;
	string aux;
	for(int i=0;i<TOPECOLUM;i++)
	{
		for (int j=0;j<TOPEROW;j++)
		{
			if (matriz[i][j].importe<min)
			{
				min = matriz[i][j].importe;
				aux = Sector[j].nombreSector;
			}
			
		}
		if (min != 0)
		{
			cout<<"Sector "<<aux<<"minimo aporte "<<min<<endl;
		}else
		{
			cout<<"no tuvo aportes "<<endl;
		}
		
		
		
	}
}
void MostrarDatos(tyManaCola matriz[TOPEROW][TOPECOLUM]){
	
	
}

int main(int argc, char const *argv[])
{
	tyProyectos Vec_Proyecto[TOPEPROYECTOS];
	tySector vecSectores[TOPESECTORES]= {"Contaduria", 14, "Deposito", 9, "Ventas", 11, "Administracion", 12, 
											"Despacho", 7, "Sistemas", 10, "Atencion al Cliente", 12, "Compras", 6 };
	tyProyectos Proyecto;
	tyInforme Informe;
	//Contadores
	int CantProyectos;
	int opcion;
	int IndiceSector;
	char ArchivoProyecto[]="proyectos.dat";
	//matriz
	tyManaCola Matriz[TOPEROW][TOPECOLUM];
	//CargoVector
	bool prueba;
	CargarVectorTipo(Proyecto,ArchivoProyecto,Vec_Proyecto,CantProyectos);
	InicializarMatriz(Matriz);
	
	do
	{
		opcion = ingresoOpcion();

		switch (opcion)
		{
		case 1:
			 IngresoDatos(Informe,vecSectores,TOPESECTORES,Matriz,TOPEPORCENTAJE,Vec_Proyecto);
			 
			break;
		case 2:
			MostrarMatriz(Matriz,vecSectores);
			minimoAportadoPorsecotr(Matriz,vecSectores);
			break;
		
		default:
			break;
		}
	} while (opcion != 4);
	

//Me falto corregir la parte del manejo para salir del programa 
//me falto el ultimo punto lo podria hacer con un vector
    
	return 0;
}




