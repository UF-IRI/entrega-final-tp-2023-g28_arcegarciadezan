#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "includes.h"


//Parto de la suposicion de que las actividades estan dispuestas de la siguiente forma: spinning,yoga,pilates,stretching,zumba,boxeo;

enum reservar{ErrNoEncontrada=-1,ErrNoHayCupos=-2,ErrYaReservada=-3,ErrHorarioNoValido=-4,ErrActividadsuperpuesta=-5,ErrMuchasReservasActivas=-6,Reservadaconexito=1};
typedef enum reservar Eres;
enum DescartarReserva{ErrorEliminar=-1,Eliminadaconexito=1};
typedef enum DescartarReserva Edesc;
enum inicializar{ErrReservarmemoria=-1,ErrCantidadDeClientesSobrepasada=-2, inicializacionexitosa=1};
typedef enum inicializar ini;
enum Archivos{ErrAbrirArchivo=-1, ArchivoManipuladoConExito=1};
typedef enum Archivos Archi;
struct fecha{
    int dia,mes,anio;
};
typedef struct fecha Sfecha;
struct cliente{
    str Nom,Ape,mail,Telefono,NomReserva[3]={"","",""};
    Sfecha FechaNac;
    int estado,idCliente,iDClasereserv[3]={0,0,0},horariosRes[3]={0,0,0};//Clasereserv tiene 3 arrays porque partimos de la suposicion de que se pueden reservar tres clases por cliente y esta iniciada con "0";
};
typedef struct cliente Scliente;
struct musculacion{
    Scliente* cliente;//no se cuantos clientes asignare, uso memoria dinamica
    int* iDClase,*horarios,CantHorarios;
    str Nombre;

};
typedef struct musculacion Smusc;


struct actividad{
    str nombre;
    int *horarios,*cupos,*IdClase,CantHorarios;

};
typedef struct actividad Sact;
struct GIMNASIO{
    Scliente* clientes;//Hago uso de memoria dinamica porque no se cuantos clientes voy a recibir
    Sact* actividades;//se que hay 6 actividades pero usar la memoria dinamica asegura un uso mas general del codigo
    Smusc* musculacion;
    int CantClases,CantClientes,ClientesMax;
};
typedef struct GIMNASIO Sgym;

//Buscar,reservar,eliminar reserva, chequear que el cliente tenga tiempo o no superponga acts
ini inicializarVariablesFijas(Sgym* Gimnasio);//puedo llamar a esta funcion para "reiniciar el dia"
int BuscarActividadPorNombre(Sgym ActsGim,str actividadPasada);//devuelve la posicion donde lo encuentra
int BuscarActividadPorHorario(Sgym ActsGim,int horarioelegido,int posN);//recibira el dato de la otra funcion buscar y devuelve la posicion de la hora
//int BuscarCliente
//bool chequear estado-->me devuelve true o false
//Chequear datos
int ChequeoActs(Scliente misActs,Sgym ActsGim,int posN,int posH);//Retorna la misma posicion
Eres ReservarAct(Sgym* ActsGim,Scliente *misActs,int posN,int posH,int *posRepAct);//devuelve un enum que indica si se agrego correctamente,int *posRepAct,int*posRepHor son posiciones opcionales que devuelve por puntero el codigo si y solo si se superponen los horarios
Edesc CancelarReserva(Sgym* ActsGim,Scliente *misActs,int posN,int posH);//devuelve un enum que indica si se elimino.
//Sacts es puntero porque va a tener que cambiar globalmente la cantidad de cupos,mientras que cliente tendra que cambiar actividad y horario.
//ARCHIVOS
Archi LeerArchivoActividades(ifstream& Archivo,Sgym* Gimnasio);//deberia usar resize u otros metodos pero tengo una variable que inicia los valores de las actividades con un numero fijo
int ContarCantClientes(ifstream& Archivo);//cuenta las lineas del archivo y devuelve el numero total
Archi LeerArchivoClientes(ifstream& Archivo,Sgym*Gimnasio);
#endif // FUNCIONES_H
