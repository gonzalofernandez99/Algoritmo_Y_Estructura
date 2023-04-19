#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include<conio.h>
#include<string.h>
#include<C:\Users\Gonzalo\Desktop\Facultad C++\TrabajoPractico4\Libreria\archivosg.h>

using namespace std;
#define TOPEPROM 30
#define TOPETEL 20
#define TOPVECTORES 20

struct ty_reg
{
    char Nombre_promotor[TOPEPROM];
    char Telefono[TOPETEL];
    int Numero;
    int DiaMes;
};


void mostrarArch (char arch[]) {
	ty_reg reg;
	bool pude=false, finArch=false;
	FILE *fichero=NULL;
	int largo = sizeof(reg);
	abrirArch(arch,"rb",fichero,pude);
	//cout<<"El registro pesa: "<<sizeof(reg)<<" bytes"<<endl;
	if (pude){
		leerArch(fichero, &reg,largo,finArch,pude);
		while(pude&&!finArch) {
			cout << "\nNombre: "<<reg.Nombre_promotor<< endl;
			cout << "Tel - > "<<reg.Telefono<<endl;
            cout << "Numero - > "<<reg.Numero<<endl;
            cout << "Dia mes "<<reg.DiaMes<<endl;
			leerArch(fichero, &reg,sizeof(reg),finArch,pude);
		}
		cerrarArch(fichero);
	}else{
		cout<<"Archivo no encontrado...";
	}
}


int main(int argc, char const *argv[])
{
    char Archivo[]="ingresoVentas.dat";
    char Arch_Bien[]="Ingresoscorrectos.dat";
    char Arch_Mal[]="IngresosIncorrectos.dat";

    mostrarArch(Archivo);
    cout<<endl<<"archivoscorrectos<<"<<endl;
    mostrarArch(Arch_Bien);
    cout<<endl<<"archivosIncorrectos<<"<<endl;
    mostrarArch(Arch_Mal);

    return 0;
}
