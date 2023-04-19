#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	
	int edad;
	int edad2=54;

	char sexo;
	char * puntsexo=NULL;
	int *  puntedad=NULL;
	cout<<"Ingrese edad: ";
	cin>>edad;
	cout<<endl<<"Ingrese sexo: ";
	cin>>sexo;
//	puntedad=NULL;
	puntedad=&edad;
	puntsexo=&sexo;
	cout<<"Edad: "<< edad<<" - puntero a edad: "<<puntedad<<endl;
	system ("PAUSE");	
	cout<<"Ingrese Otra edad: ";
	cin>>edad;
	
	cout<<endl<<"Edad: "<<edad<<" - puntero a edad: "<<puntedad<<endl;
	cout<<"Y esto que mostrara?: "<<*puntedad<<endl;

	system ("PAUSE");	
	
//	*puntedad=*puntedad+1;
	(*puntedad)++;
	cout<<endl<<"*puntedad: "<<*puntedad;
	cout<<endl<<"edad: "<<edad;
	cout<<endl<<"Largo de la variable edad: "<<sizeof(edad)<<endl;
	puntedad++;
	cout<<"Valor de puntedad modificado en 1: "<<puntedad<<endl;
	cout<<endl<<"*puntedad: "<<*puntedad<<endl;
	
	cout<<"-------------------------- Recorrido del vector con puntero --------------------------"<<endl;
	int vec[]={11,25,43,88,51};
	int *pvec=vec;
	cout<<*pvec<<endl;
	system("pause");
	pvec++;
	cout<<*pvec<<endl;
	system("pause");
	pvec++;
	cout<<*pvec<<endl;
	system("pause");
	pvec++;
	cout<<*pvec<<endl;
	system("pause");
	pvec++;
	cout<<*pvec<<endl;
	system("pause");
	
}


