#include <iostream>
#include <cstdlib>
#include <string.h>
#define TOPE 10
#define PATENTE_VACIA "0"

using namespace std;


int ingresoOpcion() {
    int __opcion;

    cout << endl << "1: Ingreso de vehiculo. 2: Salida de vehiculo. 3: Listado. 4: Fin." << endl;
    cout << "Ingrese opcion: ";
    cin >> __opcion;

    return __opcion;
}

int main()
{
    int opcion;
    int cantVehiculosEstacionados;
 
    do {
        opcion = ingresoOpcion();

        switch (opcion) {
            case 1:
                //Ingreso de Vehiculo
                break;
            case 2:
                //Salida de Vehiculo
                break;
            case 3:
                //Listar Vehiculos Estacionados;
                break;
            case 4:
                cantVehiculosEstacionados = contarVehiculosEstacionados(...);
                //Si cantVehiculosEstacionados es > 0 mostrar cartel o mostrar el estacionamiento
                break;
            default:
                mostrarOpcionNoValida();
        }
    } while (opcion != 4 || cantVehiculosEstacionados != 0);

}
