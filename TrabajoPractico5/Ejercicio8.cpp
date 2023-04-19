#include <iostream>
#include <cstdlib>
#include <string.h>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip> 
#include <C:\Users\Gonzalo\Desktop\Facultad C++\Parcial\Librerias\Arreglos.h>
#include <C:\Users\Gonzalo\Desktop\Facultad C++\Parcial\Librerias\ManejoCaracteres.h> //recordar cuando cambio de pc cambiar ruta

//TopeVectores
#define TOPTIPOS 12
#define TOPPRODUCTOS 50
#define TOPEDAD 10
//Matriz
#define TOPEC 10
#define TOPF 12
//struct ventas
#define TOPECODIGOCHAR 6
#define TOPEDESCRIPCIONCHAR 31


using namespace std;

struct Ventas
{
    char CodigoProducto[TOPECODIGOCHAR];
    char Descuento;
    int edad;
};

struct Productos 
{
    char CodigoProducto[TOPECODIGOCHAR];
    char DescripcionProducto[TOPEDESCRIPCIONCHAR];
    float Precio;
    int Tipo;
};

struct TipoProducto
{
    char Tipo[TOPEDESCRIPCIONCHAR];
    float Descuento;
    
};

struct GrupoEdad
{
    int desde;
    int hasta;
};

struct Recaudacion
{
    float recaudacion;
    int cantidad;
};



void CargarVectorProducto(Productos productos,char arch[],Productos Vec_Produ[],int &top){
    ifstream archivoB;
    int largo;
    largo = sizeof(productos);
    top = 0;
    archivoB.open(arch,ios::in | ios::binary);

     if(archivoB.fail()){
        cout<<"no se puede crear el archivo";
        exit(1);
    }

    while (!archivoB.eof())//recorre mientras el archivo no este vacio
    {
        archivoB.read((char *)&productos,largo);
        if (!archivoB.eof())
        { 
            Vec_Produ[top] = productos;
            top++;
        }
        
    }
    
    archivoB.close();
    
}

void CargarVectorTipo(TipoProducto Tipo,char arch[],TipoProducto Vec_Tipo[],int &top){
    ifstream archivoB;
    int largo;
    largo = sizeof(Tipo);
    top = 0;
    archivoB.open(arch,ios::in | ios::binary);

     if(archivoB.fail()){
        cout<<"no se puede crear el archivo";
        exit(1);
    }

    while (!archivoB.eof())//recorre mientras el archivo no este vacio
    {
        archivoB.read((char *)&Tipo,largo);
        if (!archivoB.eof())
        { 
            Vec_Tipo[top] = Tipo;
            top++;
        }
        
    }
    
    archivoB.close();
    
}

void CargarVectorGrupoEdad(GrupoEdad Edad,char arch[],GrupoEdad Vec_Edad[],int &top){
    ifstream archivoB;
    int largo;
    largo = sizeof(Edad);
    top = 0;
    archivoB.open(arch,ios::in | ios::binary);

     if(archivoB.fail()){
        cout<<"no se puede crear el archivo";
        exit(1);
    }

    while (!archivoB.eof())//recorre mientras el archivo no este vacio
    {
        archivoB.read((char *)&Edad,largo);
        if (!archivoB.eof())
        { 
            Vec_Edad[top] = Edad;
            top++;
        }
        
    }
    
    archivoB.close();
    
}

bool busqueda(char Dato[],Productos Vec_Produ[],int topeProm,int &i){
    bool encontre = false;
    i = 0;
    while (i<topeProm && !encontre)
    {
        if (strcmp(Vec_Produ[i].CodigoProducto, Dato) == 0)
        {
            encontre = true;
        }else
        {
            i++;
        }
        
        
    }
    return encontre;
}

int BusquedaEdad(GrupoEdad Vec_Edad[],int TopeEdades,int edad){
    int i = 0;
    bool encontro =false;
    while (i<TopeEdades && !encontro)
    {
        //cout<<"edades "<<Vec_Edad[i].desde<<endl;
        if ((Vec_Edad[i].desde<=edad)&&(edad<=Vec_Edad[i].hasta))
        {
            encontro = true;
        }else{
            i++;
        }
        
    }
    return i;
}


void LeeMovimientos(Ventas Venta,char arch[],char archM[],int topeCodigo,Productos Vec_Produ[],Recaudacion matriz[TOPF][TOPEC],GrupoEdad Vec_Edad[],int TopeEdad,int Vec_descuento[]){
    ifstream archivo;
    ofstream archivoM;

    int iEdad;
    int iProducto;
    int largo;
    largo = sizeof(Venta);
    bool Mal = false;

    archivo.open(arch,ios::in | ios::binary);
    archivoM.open(archM,ios::out | ios::binary); 

    if(archivo.fail()||archivoM.fail()){
        cout<<"no se puede crear el archivo";
        exit(1);
    }
    while (!archivo.eof())
    {
        archivo.read((char *)&Venta,largo);
        if (!archivo.eof())
        {
            fflush(stdin);
            //cout<<Venta.CodigoProducto<<" "<<Venta.Descuento<<" "<<Venta.edad<<endl;
            if (!busqueda(Venta.CodigoProducto,Vec_Produ,topeCodigo,iProducto))
            {
                Mal = true;
            }
            if (Venta.Descuento != 'S' && Venta.Descuento != 'N')
            {
                Mal = true;
            }
            if (6>Venta.edad || 100<Venta.edad)
            {
                Mal = true;
            }
            if (Vec_Produ[iProducto].Tipo>=12)
            {
                Mal = true;
            }
            
            if (Mal)
            {
                archivoM.write((char *)&Venta,largo);
            }else
            {
               iEdad = BusquedaEdad(Vec_Edad,TopeEdad,Venta.edad);
               matriz[Vec_Produ[iProducto].Tipo][iEdad].cantidad++;
               matriz[Vec_Produ[iProducto].Tipo][iEdad].recaudacion += Vec_Produ[iProducto].Precio;
               if (Venta.Descuento == 'S')
               {
                    Vec_descuento[iEdad]++;
               }
               
            }
            
            Mal=false;
            
            
        }
        
    }
    
    archivo.close();
    archivoM.close();
}

void InicializarMatriz(Recaudacion matriz[TOPF][TOPEC])
{
	for(int i=0;i<TOPF;i++)
	{
		for (int j=0;j<TOPEC;j++)
		{
			matriz[i][j].cantidad=0;
            matriz[i][j].recaudacion=0;
		}
	}
}

void InicializarVector(int vector[], int tope){
    for (int i = 0; i < tope; i++)
    {
        vector[i] = 0;
    }
    
}

void MostrarMatriz(Recaudacion matriz[TOPF][TOPEC])
{
	for(int i=0;i<TOPF;i++)
	{
		for (int j=0;j<TOPEC;j++)
		{
			cout<<setw(12)<<matriz[i][j].cantidad<<" "<<matriz[i][j].recaudacion;
		}
		cout<<endl;
	}
}

void Muestra(Recaudacion matriz[TOPF][TOPEC],TipoProducto Tipo[],GrupoEdad Vec_Edad[]){
    for(int i=0;i<TOPF;i++){
        for (int j=0;j<TOPEC;j++)
        {
            cout<<Tipo[i].Tipo<<" : "<<Vec_Edad[i].desde<<" Hasta "<<Vec_Edad[i].hasta<<endl;
            cout<<" Recaudacion: "<<matriz[i][j].recaudacion;
        }
        
    }
}

int main(int argc, char const *argv[])
{
    //TY
    Productos Prod;
    TipoProducto Tipo;
    GrupoEdad Edad;
    Ventas Venta;
    //Vectores
    Productos Vec_Prod[TOPPRODUCTOS];
    TipoProducto Vec_Tipo[TOPTIPOS];
    GrupoEdad Vec_Edad[TOPEDAD];
    int Vec_descuentos[TOPEDAD];
    //Nombre Arhivos
    char ArchivoProductos[]="productos.dat";
    char ArchivoTipo[]="tipos.dat";
    char ArchivoEdad[]="grupos.dat";
    char ArchivoMovimiento[]="movimientosEJ8.dat";
    char ArchivoErrores[]="Errores.dat";
    //Contadores
    int ContEdad;
    int ContTipo;
    int ContProd;
    int ContVenta;
    //matriz
    Recaudacion matriz [TOPF][TOPEC];

    //carga en vectores
    CargarVectorGrupoEdad(Edad,ArchivoEdad,Vec_Edad,ContEdad);
    CargarVectorTipo(Tipo,ArchivoTipo,Vec_Tipo,ContTipo);
    CargarVectorProducto(Prod,ArchivoProductos,Vec_Prod,ContProd);
    //inicializa
    InicializarMatriz(matriz);
    InicializarVector(Vec_descuentos,ContEdad);
    //leeMovimientos
    LeeMovimientos(Venta,ArchivoMovimiento,ArchivoErrores,ContProd,Vec_Prod,matriz,Vec_Edad,ContEdad,Vec_descuentos);

    MostrarMatriz(matriz);

    /* for (int i = 0; i < ContProd; i++)
    {
        cout<<"\n"<<Vec_Prod[i].CodigoProducto<<" "<<Vec_Prod[i].DescripcionProducto<<" "<<Vec_Prod[i].Precio<<" "<<Vec_Prod[i].Tipo<<endl;
    } */
    
    /* for (int i = 0; i < ContTipo; i++)
    {
        cout<<Vec_Tipo[i].Descuento<<"   "<<Vec_Tipo[i].Tipo<<endl;
    } 
     */

    return 0;
}
