#include "Includes.h"
#include "Funciones.h"
#include "FuncionesImp.cpp"

int main() {
    srand(time(NULL));
    //---------------------------------------------VARIABLES------------------------------------------------
    ifstream InputActividades,InputClientes,InputAsistencias;
    ofstream TextoParaUbicarArchivo,InformeGym,InformeAsis;
    int cont=0,cantasis=0;
    Sgym* Gimnasio=new Sgym;
    //--------------------------------------INICIALIZACION/APERTURA-----------------------------------------
    TextoParaUbicarArchivo.open("../Ubicacion.txt");
    TextoParaUbicarArchivo<<"Hola";
    InputActividades.open("../iriClasesGYM.csv");
    InputClientes.open("../iriClientesGYM.csv");
    InputAsistencias.open("../asistencias_1697673600000.dat",ios::binary);
    InformeGym.open("../InformeGym.txt");
    //InformeAsis.open("../asistencias_1697673600000.dat",ios::binary);

    if (!InputActividades.is_open())
        cout << "Error al abrir archivo Actividades" << endl;
    if (!InputClientes.is_open())
        cout << "Error al abrir archivo Clientes" << endl;
    if(!InputAsistencias.is_open())
        cout<<"Error al abrir archivo Asistencias"<< endl;
    //------------------------------------------INICIALIZO LAS VARIABLES----------------------------------------------------------
    inicializarVariablesFijas(Gimnasio);
    LeerArchivoActividades(InputActividades,Gimnasio);
    cont=ContarCantClientes(InputClientes);
    LeerArchivoClientes(InputClientes,Gimnasio,Gimnasio->CantClientes,cont);
    LeerAsistencias(InputAsistencias,Gimnasio->asistencias,&cantasis);

    //---------------------------------------------DATOS DE PRUEBA EXITOSOS-------------------------------------------------------
    str ActividadesCorrectas[7]={"Spinning","Stretching","Boxeo","Musculacion","Yoga","Zumba","Pilates"};
    u_int cantActs=7;
    str ActElegida;
    int posN,posH,HorarioRandom,iDrandom,posCliente,contErrores=0,posicionactividadrepetida,contReservas=0,contCancelaciones=0,valorenum;

    for(int i=0;i<20;i++){
        ActElegida=generarActAlAzar(cantActs,ActividadesCorrectas);//ActividadesValidas
        HorarioRandom= 7+rand()%(22-7);//HorariosValidos
        iDrandom=1+rand()%(251-1);//iD validos
        posN=BuscarActividadPorNombre(*Gimnasio,ActElegida);
        posH=BuscarActividadPorHorario(*Gimnasio,HorarioRandom,posN);
        posCliente=BuscarClientePorId(*Gimnasio,iDrandom);
        valorenum=ReservarAct(Gimnasio,&(Gimnasio->clientes[posCliente]),posN,posH,&posicionactividadrepetida);
        if(valorenum==Reservadaconexito)
            contReservas++;
        else
            contErrores++;
    }
    cout<<"Se resevraron: "<<contReservas<<" Actividades con exito"<<endl;
    cout<<"Hubo "<<contErrores<<" errores al reservar"<<endl;
    InformeGym<<"------------------RESERVAS------------------"<<endl;
    InformeGym<<"Se reservaron: "<<contReservas<<" actividades con exito"<<endl;
    InformeGym<<"Hubo "<<contErrores<<" al reservar"<<endl;
    contErrores=0;
    for(int i=0;i<20;i++){
        ActElegida=generarActAlAzar(cantActs,ActividadesCorrectas);//ActividadesValidas
        HorarioRandom= 7+rand()%(22-1);//HorariosValidos
        iDrandom=1+rand()%(251-1);//iD validos
        posN=BuscarActividadPorNombre(*Gimnasio,ActElegida);
        posH=BuscarActividadPorHorario(*Gimnasio,HorarioRandom,posN);
        posCliente=BuscarClientePorId(*Gimnasio,iDrandom);
        valorenum=CancelarReserva(Gimnasio,&(Gimnasio->clientes[posCliente]),posN,posH);
        if(valorenum==Canceladaconexito)
            contCancelaciones++;
        else
            contErrores++;
    }
    for(int i=0;i<20;i++){

    }
    InformeGym<<"------------------CANCELACIONES------------------"<<endl;
    InformeGym<<"Se Cancelaron: "<<contCancelaciones<<" actividades con exito"<<endl;
    InformeGym<<"Hubo "<<contErrores<<" errores al cancelar las reservas"<<endl;
    /*
//--------------------------------DATOS DE PRUEBA QUE TIENEN QUE FALLAR-------------------------------------------------------
    str ActividadesIncorrectas[7]={"Spinng","Streing","Box","Muscacion","Yoa","Zmba","Pites"};
    u_int cantActs=7;
    str ActElegida;
    int posN,posH,HorarioRandom,iDrandom,posCliente,contErrores=0,posicionactividadrepetida,contReservas=0,contCancelaciones=0,valorenum;
    for(int i=0;i<20;i++){
        ActElegida=generarActAlAzar(cantActs,ActividadesIncorrectas);//ActividadesValidas
        HorarioRandom= 1+rand()%(30-1);//HorariosNovalidos
        iDrandom=1+rand()%(500-1);//iD validos
        posN=BuscarActividadPorNombre(*Gimnasio,ActElegida);
        posH=BuscarActividadPorHorario(*Gimnasio,HorarioRandom,posN);
        posCliente=BuscarClientePorId(*Gimnasio,iDrandom);
        valorenum=ReservarAct(Gimnasio,&(Gimnasio->clientes[posCliente]),posN,posH,&posicionactividadrepetida);
        if(valorenum==Reservadaconexito)
            contReservas++;
        else
            contErrores++;
    }
    cout<<"Se resevraron: "<<contReservas<<" Actividades con exito"<<endl;
    cout<<"Hubo "<<contErrores<<" errores al reservar"<<endl;//Deberian ser todos los del for
    contErrores=0;
    for(int i=0;i<20;i++){
        ActElegida=generarActAlAzar(cantActs,ActividadesCorrectas);//ActividadesValidas
        HorarioRandom= 7+rand()%(22-1);//HorariosValidos
        iDrandom=1+rand()%(251-1);//iD validos
        posN=BuscarActividadPorNombre(*Gimnasio,ActElegida);
        posH=BuscarActividadPorHorario(*Gimnasio,HorarioRandom,posN);
        posCliente=BuscarClientePorId(*Gimnasio,iDrandom);
        valorenum=CancelarReserva(Gimnasio,&(Gimnasio->clientes[posCliente]),posN,posH);
        if(valorenum==Canceladaconexito)
            contCancelaciones++;
        else
            contErrores++;
    }
   */
    //-----------------------------------------------CERRAR ARCHIVOS--------------------------------------------------------------
    TextoParaUbicarArchivo.close();
    InputClientes.close();
    InputActividades.close();
    InputAsistencias.close();
    InformeGym.close();
    //InformeAsis.close();

    //--------------------------------------------ELIMINACION DINAMICAS----------------------------------------------------------
    for (int i = 0; i < Gimnasio->CantClases; ++i) {
        delete[] Gimnasio->actividades[i].horarios;
        delete[] Gimnasio->actividades[i].cupos;
        delete[] Gimnasio->actividades[i].IdClase;
    }
    for (int i = 0; i < cantasis; i++) {
        delete[] Gimnasio->asistencias[i].CursoYfecha;
    }
    delete[] Gimnasio->asistencias;
    delete[] Gimnasio->actividades;
    delete[] Gimnasio->musculacion->horarios;
    delete[] Gimnasio->musculacion->iDClase;
    delete Gimnasio->musculacion;
    delete[] Gimnasio->clientes;
    delete Gimnasio;
    return 0;
}
