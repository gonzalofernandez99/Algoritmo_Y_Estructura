#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip> 

using namespace std;

#define TOPETIPOPUB 4
#define TOPEPAIS 5
#define TOPELIBROS 9
#define TOPENOMBRES 25

struct ty_regLibro{
	char	 nombreLibro[TOPENOMBRES];
	int		 tipoPub;
	int		 stock;
};
struct ty_regPais{
	string	 nombrePais;
	float	 precio;
};


struct typedido{
	char	 nombreLibro[TOPENOMBRES];
	int		 pais;
};

struct ty_Matriz_Libreria
{
	float Recaudacion;
	int Cantidad;
};


void CargarVectorLibro(ty_regLibro Libros,char arch[],ty_regLibro Vec_Libros[],int &top,int TopeRegistros){
    ifstream archivoB;
    int largo;
    largo = sizeof(Libros);
    top = 0;
    archivoB.open(arch,ios::in | ios::binary);

     if(archivoB.fail()){
        cout<<"no se puede crear el archivo";
        exit(1);
    }

    while ((!archivoB.eof()) && top<TopeRegistros)//recorre mientras el archivo no este vacio
    {
        archivoB.read((char *)&Libros,largo);
        if (!archivoB.eof())
        { 
            Vec_Libros[top] = Libros;
            top++;
        }
        
    }
    
    archivoB.close();
    
}

void InicializarMatriz(ty_Matriz_Libreria matriz[TOPETIPOPUB][TOPEPAIS])
{
	for(int i=0;i<TOPETIPOPUB;i++)
	{
		for (int j=0;j<TOPEPAIS;j++)
		{
			matriz[i][j].Cantidad=0; 
			matriz[i][j].Recaudacion=0;
		}
	}
}

int BusquedaLibro(ty_regLibro Vec_Libros[],int Tope,char Libro[]){
    int Aux = -1;
	int i = 0;
	bool Noencontre = true;
	while (Noencontre && i<Tope)
	{
		if (strcmp(Vec_Libros[i].nombreLibro,Libro) ==0)
		{
			Aux = i;
			Noencontre = false;
		}else
		{
			i++;
		}
		
	}
	
    return Aux;
}

void IngresoDatos(typedido &Pedido,ty_regLibro Vec_Libros[],int TopeNombres,int TopeLibros,int &IndiceLibro){
	fflush(stdin);
	cout<<"Para finalizar ingrese * "<<endl;
	cout<<"indique nombre de libro "<<endl;
	cin.getline(Pedido.nombreLibro,TopeNombres,'\n');
	
	if (Pedido.nombreLibro[0] != '*')
	{
		IndiceLibro = BusquedaLibro(Vec_Libros,TopeLibros,Pedido.nombreLibro);
		while (IndiceLibro == -1)
	{
		fflush(stdin);
		cout<<"indique nuevamente un valor valido"<<endl;
		cin.getline(Pedido.nombreLibro,TopeNombres,'\n');

		if (Pedido.nombreLibro[0] == '*')
		{
			IndiceLibro = 0;
		}else
		{
			IndiceLibro = BusquedaLibro(Vec_Libros,TopeLibros,Pedido.nombreLibro);
		}
	}
	}

	if (Pedido.nombreLibro[0] != '*')
	{
		cout<<"indique Pais Comprador"<<endl;
		cin>>Pedido.pais;
		while (Pedido.pais <1 || Pedido.pais > 5)
		{
			fflush(stdin);
			cout<<"indique Nuevamente pais Comprador"<<endl;
			cin>>Pedido.pais;
		}
		
	}
	
}

bool VerificaSiHaystok(ty_regLibro Vec_Libros[],int IndiceLibro){
	bool Stock;
	if (Vec_Libros[IndiceLibro].stock==0)
	{
		Stock = false;
	}else
	{
		Stock = true;
	}
	
	return Stock;
}

void DescuentoStock(ty_regLibro Vec_Libros[],int IndiceLibro){
	Vec_Libros[IndiceLibro].stock--;
}

void CalculaIndices(typedido regPedido,int IndicePais,ty_regLibro  vecLibros[],int &ITipo,int &Ipais){
	Ipais = regPedido.pais-1;
	ITipo = vecLibros[IndicePais].tipoPub;
}

void CargaEnMatriz(ty_Matriz_Libreria matriz[TOPETIPOPUB][TOPEPAIS],int Pais,int IndiceLibro,float GastosEnvio){
	matriz[IndiceLibro][Pais].Cantidad++;
	matriz[IndiceLibro][Pais].Recaudacion += GastosEnvio;
}

void MuestraSinStock(char Libro[]){
	cout<<"No Hay stock para el libro: "<<Libro<<endl;
}

void PorPaisRecaudacionTipo(ty_Matriz_Libreria matriz[TOPETIPOPUB][TOPEPAIS],ty_regPais vecPais[]){
	for (int IPais = 0; IPais < TOPEPAIS; IPais++)
	{
		for (int ITipo = 0; ITipo  < TOPETIPOPUB; ITipo ++)
		{
			cout<<vecPais[IPais].nombrePais<<" Tipo de publicacion "<<ITipo<<" Recaudo: "<<matriz[ITipo][IPais].Recaudacion<<endl;
		}
		
	}
	
}

void PorTipoMinimoEnvios(ty_Matriz_Libreria matriz[TOPETIPOPUB][TOPEPAIS],ty_regPais vecPais[]){
	int aux;
	int min;
	for (int ITipo = 0; ITipo < TOPETIPOPUB; ITipo++)
	{
		for (int IPais = 0; IPais < TOPEPAIS; IPais++)
		{
			if (IPais == 0)
			{
				min = matriz[ITipo][IPais].Cantidad;
				aux = IPais;
			}
			
			if (matriz[ITipo][IPais].Cantidad != 0)
			{
				if (min != 0)
				{
					if (matriz[ITipo][IPais].Cantidad<min)
					{
						min = matriz[ITipo][IPais].Cantidad;
						aux = IPais;
					}
				}else
				{
					min = matriz[ITipo][IPais].Cantidad;
					aux = IPais;
				}
			
			}
			
				
		}
			
		if (min == 0)
		{
			cout<<" \nTipo de publicacion "<<ITipo<<" No tuvo Ventas en ningun pais "<<endl;
		}else
		{
			cout<<"\nTipo de publicacion "<<ITipo<<" Pais con menor ventas "<<vecPais[aux].nombrePais<<" Con "<<min<<" Ventas."<<endl;
		}
		
		
	}
		
}

void PublicacionSinStock(ty_regLibro Vec_Libros[],int TopeLibros){
	bool Stock;
	int i = 0;
	while (i <TopeLibros)
	{
		if (Vec_Libros[i].stock==0)
		{
			cout<<"\nNo hay stock para el libro: "<<Vec_Libros[i].nombreLibro<<endl;
		}
		i++;
	}
	
}

int main(){
	typedido regPedido;
	ty_regLibro Libros;
    ty_regLibro  vecLibros[TOPELIBROS];
    ty_regPais vecPais[TOPEPAIS]={"Uruguay",125.70,"Bolivia", 180.30,"Chile",270,"Brasil", 350.25,"Paraguay", 147.50};
	ty_Matriz_Libreria MatrizLibreria[TOPETIPOPUB][TOPEPAIS];

	char nomArch[]="libros.dat";
	bool BStock;
	int CantLibros;
	int IndiceLibro;
	int IndicePais;
	int IndiceTipo;
	CargarVectorLibro(Libros,nomArch,vecLibros,CantLibros,TOPELIBROS);

	/* for (int i = 0; i < CantLibros; i++)
	{
		cout<<"Nombre libro - > "<<vecLibros[i].nombreLibro<<endl;
		cout<<" Tipo stock "<<vecLibros[i].stock<<endl;
		cout<<" tipo libro "<<vecLibros[i].tipoPub<<endl;
	} */
	
	InicializarMatriz(MatrizLibreria);

	IngresoDatos(regPedido,vecLibros,TOPENOMBRES,TOPELIBROS,IndiceLibro);

	while (regPedido.nombreLibro[0] != '*')
	{
		BStock=VerificaSiHaystok(vecLibros,IndiceLibro);

		if (BStock)
		{
			DescuentoStock(vecLibros,IndiceLibro);
			CalculaIndices(regPedido,IndiceLibro,vecLibros,IndiceTipo,IndicePais);
			CargaEnMatriz(MatrizLibreria,IndicePais,IndiceTipo,vecPais[IndicePais].precio);
		}else
		{
			MuestraSinStock(regPedido.nombreLibro);
		}
		
		IngresoDatos(regPedido,vecLibros,TOPENOMBRES,TOPELIBROS,IndiceLibro);
	}
	
	PorPaisRecaudacionTipo(MatrizLibreria,vecPais);
	PorTipoMinimoEnvios(MatrizLibreria,vecPais);
	PublicacionSinStock(vecLibros,CantLibros); 
 
	
	
}
