#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;


void abrirArch(char arch[],char op[], FILE *&fichero, bool &pude){
	fichero=NULL;
	//abre el fichero en el modo indicado
	/*
		wb = write binary 	(escribir = destruir lo que existe y empezar de 0)
		rb = read binary	(leer)
		ab = append binary	(agregar al final)
	*/
	if ((op[0]=='w' || op[0]=='r' || op[0]=='a') && op[1]=='b'){
		fichero = fopen (arch, op);
	}else{
		cout<<"No se reconoce el modo de acceso solicitado."<<endl;
	}
	pude = (fichero != NULL);
}


bool escribirArch(void *reg, int size, FILE *fichero){
	bool pude=false;
	if(fichero!=NULL){
		if (fwrite(reg,size,1,fichero)==1){
			pude=true;
		}
	}
	return pude;
}

bool cerrarArch(FILE *fichero){
	bool pude=false;
	//primero verifico que el fichero no sea NULL
	if (fichero != NULL ){
		pude= (fclose(fichero)==0);	
	}
	return pude;
}

void leerArch(FILE * fichero, void *reg, int size, bool &fin, bool &pude){
	fin=true; //Fuerzo la condici�n de fin a verdadero por si el fichero vino en null
	if ( fichero != NULL ) {
		if (fread(reg,size,1,fichero)==0){
			pude=false;
		}else{
			pude=true;
			fin = feof(fichero);
		}
	}	
}
/* 
Para implementaci�n local en el cpp

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
			cout << "Nombre: "<<reg.nombre << endl;
			cout << "------------------";
			leerArch(fichero, &reg,sizeof(reg),finArch,pude);
		}
		cerrarArch(fichero);
	}else{
		cout<<"Archivo no encontrado...";
	}
}
 */




