#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip> 
using namespace std;

struct ty_regPais{
	char	 nombrePais[30];
	float	 precio;
};

void VerExtremos(int &desde, int &hasta, int ext){
	desde+=ext;
	hasta=hasta-ext;
	ext=4;
}



int main(){

	int num1, num2=8, extremos=1;
	char nomArch[]="libros.dat";
	char nomArch1[]="libross.dat";
	ty_regPais vecPais[5]={"Uruguay",125.70,"Bolivia", 180.30,"Chile",270,"Brasil", 350.25,"Paraguay", 147.50};
	cout<<strcmp(nomArch,nomArch1);


	/* cout<<"El numero num1 contiene: "<<num1<<endl;
	IngresoNumero(num1);
	cout<<"El numero ingresado es: "<<num1<<endl; */
	
	/*IngresoNumero(num2);
	comentario

	VerExtremos(num1,num2,extremos);
	cout<<"Desde: "<<num1<<endl;
	cout<<"Hasta: "<<num2<<endl;
	cout<<"Extremos?: "<<extremos<<endl;
	*/
	
}


