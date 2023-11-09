#include "Includes.h"
#include "Funciones.h"

int main() {
    ifstream InputActividades,InputClientes;
    ofstream TextoParaUbicarArchivo;
    TextoParaUbicarArchivo.open("../Ubicacion.txt");
    TextoParaUbicarArchivo<<"Hola";
    InputActividades.open("../iriClasesGYM.csv");
    InputClientes.open("../iriClientesGYM.csv");
    if (!InputActividades.is_open()) {
        cout << "Error al abrir archivo" << endl;

    }
    if (!InputClientes.is_open()) {
        cout << "Error al abrir archivo" << endl;

    }




    TextoParaUbicarArchivo.close();
    InputClientes.close();
    InputActividades.close();
    return 0;
}
