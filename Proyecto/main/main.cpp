#include "Includes.h"
#include "Funciones.h"
#include "FuncionesImp.cpp"

int main() {
//---------------------------------------------VARIABLES------------------------------------------------
    ifstream InputActividades,InputClientes;
    ofstream TextoParaUbicarArchivo;
    int cont=0;
    Sgym* Gimnasio=new Sgym;
//--------------------------------------INICIALIZACION/APERTURA-----------------------------------------
    TextoParaUbicarArchivo.open("../Ubicacion.txt");
    TextoParaUbicarArchivo<<"Hola";
    InputActividades.open("../iriClasesGYM.csv");
    InputClientes.open("../iriClientesGYM.csv");

    if (!InputActividades.is_open())
        cout << "Error al abrir archivo" << endl;    
    if (!InputClientes.is_open())
        cout << "Error al abrir archivo" << endl;

    inicializarVariablesFijas(Gimnasio);
    LeerArchivoActividades(InputActividades,Gimnasio);
    cont=ContarCantClientes(InputClientes);
    LeerArchivoClientes(InputClientes,Gimnasio,Gimnasio->CantClientes,cont);






//-----------------------------------------------CERRAR ARCHIVOS--------------------------------------------------------------
    TextoParaUbicarArchivo.close();
    InputClientes.close();
    InputActividades.close();
//--------------------------------------------ELIMINACION DINAMICAS----------------------------------------------------------
    for (int i = 0; i < Gimnasio->CantClases; ++i) {
        delete[] Gimnasio->actividades[i].horarios;
        delete[] Gimnasio->actividades[i].cupos;
        delete[] Gimnasio->actividades[i].IdClase;
    }
    delete[] Gimnasio->actividades;
    delete[] Gimnasio->musculacion->horarios;
    delete[] Gimnasio->musculacion->iDClase;
    delete Gimnasio->musculacion;
    delete[] Gimnasio->clientes;
    delete Gimnasio;
    return 0;
}
