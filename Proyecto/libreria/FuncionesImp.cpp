#include "Funciones.h"
ini inicializarVariablesFijas(Sgym* Gimnasio){
    //esta funcion inicializa los datos que son fijos en mis variables, como los cupos y los id reservas(van a estar inicializados en 0)
    int i;
    Gimnasio->CantClases=6;//la cantidad de clases es fijo
    Gimnasio->actividades=new Sact[Gimnasio->CantClases];
    if(Gimnasio->actividades==nullptr)
        return ErrReservarmemoria;

    //--------SPINNING--------
    Gimnasio->actividades[0].CantHorarios=5;
    Gimnasio->actividades[0].nombre="Spinning";
    Gimnasio->actividades[0].cupos=new int[Gimnasio->actividades[0].CantHorarios];
    Gimnasio->actividades[0].IdClase=new int[Gimnasio->actividades[0].CantHorarios];
    Gimnasio->actividades[0].horarios=new int[Gimnasio->actividades[0].CantHorarios];
    if(Gimnasio->actividades[0].cupos==nullptr)
        return ErrReservarmemoria;
    else if(Gimnasio->actividades[0].IdClase==nullptr)
        return ErrReservarmemoria;
    else if(Gimnasio->actividades[0].horarios==nullptr)
        return ErrReservarmemoria;
    for(i=0;i<Gimnasio->actividades[0].CantHorarios;i++)
    {
        Gimnasio->actividades[0].cupos[i]=45;//todas las actividades de spinning tienen 45 cupos cada una
    }
    //-------YOGA-------
    Gimnasio->actividades[1].CantHorarios=6;
    Gimnasio->actividades[1].nombre="Yoga";
    Gimnasio->actividades[1].cupos=new int[Gimnasio->actividades[1].CantHorarios];
    Gimnasio->actividades[1].IdClase=new int[Gimnasio->actividades[1].CantHorarios];
    Gimnasio->actividades[1].horarios=new int[Gimnasio->actividades[1].CantHorarios];
    if(Gimnasio->actividades[1].cupos==nullptr)
        return ErrReservarmemoria;
    else if(Gimnasio->actividades[1].IdClase==nullptr)
        return ErrReservarmemoria;
    else if(Gimnasio->actividades[1].horarios==nullptr)
        return ErrReservarmemoria;
    for(i=0;i<Gimnasio->actividades[1].CantHorarios;i++)
    {
        Gimnasio->actividades[1].cupos[i]=25;
    }
    //-------PILATES-------
    Gimnasio->actividades[2].CantHorarios=6;
    Gimnasio->actividades[2].nombre="Pilates";
    Gimnasio->actividades[2].cupos=new int[Gimnasio->actividades[2].CantHorarios];
    Gimnasio->actividades[2].IdClase=new int[Gimnasio->actividades[2].CantHorarios];
    Gimnasio->actividades[2].horarios=new int[Gimnasio->actividades[2].CantHorarios];
    if(Gimnasio->actividades[2].cupos==nullptr)
        return ErrReservarmemoria;
    else if(Gimnasio->actividades[2].IdClase==nullptr)
        return ErrReservarmemoria;
    else if(Gimnasio->actividades[2].horarios==nullptr)
        return ErrReservarmemoria;
    for(i=0;i<Gimnasio->actividades[2].CantHorarios;i++)
    {
        Gimnasio->actividades[2].cupos[i]=15;
    }
    //---------STRETCHING----------
    Gimnasio->actividades[3].CantHorarios=6;
    Gimnasio->actividades[3].nombre="Stretching";
    Gimnasio->actividades[3].cupos=new int[Gimnasio->actividades[3].CantHorarios];
    Gimnasio->actividades[3].IdClase=new int[Gimnasio->actividades[3].CantHorarios];
    Gimnasio->actividades[3].horarios=new int[Gimnasio->actividades[3].CantHorarios];
    if(Gimnasio->actividades[3].cupos==nullptr)
        return ErrReservarmemoria;
    else if(Gimnasio->actividades[3].IdClase==nullptr)
        return ErrReservarmemoria;
    else if(Gimnasio->actividades[3].horarios==nullptr)
        return ErrReservarmemoria;
    for(i=0;i<Gimnasio->actividades[3].CantHorarios;i++)
    {
        Gimnasio->actividades[3].cupos[i]=40;
    }
    //-------ZUMBA---------
    Gimnasio->actividades[4].CantHorarios=6;
    Gimnasio->actividades[4].nombre="Zumba";
    Gimnasio->actividades[4].cupos=new int[Gimnasio->actividades[4].CantHorarios];
    Gimnasio->actividades[4].IdClase=new int[Gimnasio->actividades[4].CantHorarios];
    Gimnasio->actividades[4].horarios=new int[Gimnasio->actividades[4].CantHorarios];
    if(Gimnasio->actividades[4].cupos==nullptr)
        return ErrReservarmemoria;
    else if(Gimnasio->actividades[4].IdClase==nullptr)
        return ErrReservarmemoria;
    else if(Gimnasio->actividades[4].horarios==nullptr)
        return ErrReservarmemoria;
    for(i=0;i<Gimnasio->actividades[4].CantHorarios;i++)
    {
        Gimnasio->actividades[4].cupos[i]=50;
    }
    //------BOXEO-------
    Gimnasio->actividades[5].CantHorarios=4;
    Gimnasio->actividades[5].nombre="Boxeo";
    Gimnasio->actividades[5].cupos=new int[Gimnasio->actividades[5].CantHorarios];
    Gimnasio->actividades[5].IdClase=new int[Gimnasio->actividades[5].CantHorarios];
    Gimnasio->actividades[5].horarios=new int[Gimnasio->actividades[5].CantHorarios];
    if(Gimnasio->actividades[5].cupos==nullptr)
        return ErrReservarmemoria;
    else if(Gimnasio->actividades[5].IdClase==nullptr)
        return ErrReservarmemoria;
    else if(Gimnasio->actividades[5].horarios==nullptr)
        return ErrReservarmemoria;
    for(i=0;i<Gimnasio->actividades[5].CantHorarios;i++)
    {
        Gimnasio->actividades[5].cupos[i]=30;
    }
    //------MUSCULACION------
    Gimnasio->musculacion=new musculacion;
    Gimnasio->musculacion->CantHorarios=27;
    Gimnasio->musculacion->Nombre="Musculacion";
    Gimnasio->musculacion->horarios=new int[Gimnasio->musculacion->CantHorarios];
    Gimnasio->musculacion->iDClase=new int[Gimnasio->musculacion->CantHorarios];
    if(Gimnasio->musculacion->horarios==nullptr)
        return ErrReservarmemoria;
    else if(Gimnasio->musculacion->iDClase==nullptr)
        return ErrReservarmemoria;


    return inicializacionexitosa;
    //libero memoria en el main, porque si borro la memoria dinamica aca no estaria inicializando nada
}
int BuscarActividadPorNombre(Sgym ActsGim,str actividadPasada){
    int i;
    for(i=0;i<ActsGim.CantClases;i++)
    {
        if (ActsGim.actividades[i].nombre.compare(actividadPasada) == 0) {
            // La actividad se encontró en la posición i
            return i;
        }
    }
    return -1;//si sale de la funcion quiere decir que no la encontro
}
int BuscarActividadPorHorario(Sgym ActsGim,int horarioelegido,int posN){
    int i;

    if(posN==-1)
        return -1;

    i=0;
    while(ActsGim.actividades[posN].horarios[i]!=horarioelegido){

        if((ActsGim.actividades[posN].nombre.compare("Spinning"))==0&&i>5)//Caso spinning
            return -4;//Horario no valido
        else if((ActsGim.actividades[posN].nombre.compare("Boxeo"))==0&&i>4)//Caso boxeo
            return -4;
        else if(i>6)//Otras actividades
            return -4;
        i++;
    }
    return i;
}
int BuscarClientePorId(Sgym Gimnasio,int idPasado){
    int pos=0;
    for(int i=0;i<Gimnasio.CantClientes;i++){
        if(Gimnasio.clientes[i].idCliente==idPasado)
            pos=i;
    }
    if(pos==Gimnasio.CantClientes)
        return -1;
    else return pos;
}
bool ChequearEstado(Scliente Cliente){
    if(Cliente.estado>=0)//mayor igual a 0 tienen la cuota al dia
        return true;
    else return false;
}
int ChequeoActs(Scliente misActs,Sgym ActsGim,int posN,int posH){
    int i,cont=0,pos0=-2;//pos0 recibe un valor que no puede tomar como para poder determinar si tengo espacio o no
    if(posN==-1||posH==-1)
        return -1;//actividad no encontrada
    else if(posH==-4)
        return -4;//horario invalido

    for(i=0;i<3;i++)
    {
        if(ActsGim.actividades[posN].IdClase[posH]==misActs.iDClasereserv[i])
            cont++;

        if(misActs.iDClasereserv[i]==0)
            pos0=i;//guardo la posicion del array vacio
    }

    if(cont!=0)
        return -3;//actividad repetida
    else if(pos0==-2)
        return -6;//no tengo espacio

    return pos0;//posicion vacia de mi id;
}
Eres ReservarAct(Sgym* ActsGim,Scliente *misActs,int posN,int posH,int *posRepAct){
    int pos0,contrepe=0;
    *posRepAct=-2;//este parametro es devuelto por puntero si y solo si encuentro actividades superpuestas, para informar que clase especifica se superpone con la actividad a reservar

    pos0=ChequeoActs(*misActs,*ActsGim,posN,posH);
    if(ChequearEstado(*misActs)==false)
        return ErrFaltadePago;
    else if(pos0==-1)
        return ErrNoEncontrada;
    else if(pos0==-3)
        return ErrYaReservada;
    else if(pos0==-4)
        return ErrHorarioNoValido;
    else if(pos0==-6)
        return ErrMuchasReservasActivas;
    else if(ActsGim->actividades[posN].cupos[posH]==0)
        return ErrNoHayCupos;

    for(int i=0;i<3;i++)
    {
        if(ActsGim->actividades[posN].horarios[posH]==misActs->horariosRes[i]){
            contrepe++;
            *posRepAct=i;
        }

    }
    //agarrar los id de la clase dentro de la structura del cliente y comparar esos horarios con el de la nueva actividad
    if(contrepe!=0)
        return ErrActividadsuperpuesta;

    misActs->iDClasereserv[pos0]=ActsGim->actividades[posN].IdClase[posH];//guardo el id de la clase;
    misActs->horariosRes[pos0]=ActsGim->actividades[posN].horarios[posH];//guardo el horario hayado
    misActs->NomReserva[pos0]=ActsGim->actividades[posN].nombre;

    ActsGim->actividades[posN].cupos[posH]=ActsGim->actividades[posN].cupos[posH]-1;

    return Reservadaconexito;
}
Edesc CancelarReserva(Sgym* ActsGim,Scliente *misActs,int posN,int posH){
    int i=0;
    while(i<3&&misActs->iDClasereserv[i]!=ActsGim->actividades[posN].IdClase[posH]){
        i++;
    }
    if(i==3)
        return ErrNoReservada;//No encontro el id de la clase en las clases reservadas
    else
    {
        //Se restablecen los valores
        misActs->iDClasereserv[i]=0;
        misActs->NomReserva[i]="";
        misActs->horariosRes[i]=0;
        //Se aumenta un cupo
        ActsGim->actividades[posN].cupos[posH]++;
    }
    return Canceladaconexito;
}
ini ResizeCliente(Scliente*& Clientes,int &tam,int ntam){
    if(Clientes==nullptr&&ntam>0){
        Scliente*Aux=new Scliente[ntam];
        delete Clientes;
        Clientes=Aux;
        tam=ntam;
        return inicializacionexitosa;
    }
    if(tam>=0&&ntam>0){
        Scliente*Aux=new Scliente[ntam];
        u_int longitud=(tam<ntam)?tam:ntam;
        for(u_int i=0;i<longitud;i++)
            Aux[i]=Clientes[i];
        (tam>1)? delete[] Clientes:delete Clientes;
        Clientes=Aux;
        tam=ntam;
        return inicializacionexitosa;
    }else if(ntam>0){
        Clientes=new Scliente[ntam];
        tam=ntam;
        return inicializacionexitosa;
    }else ErrReservarmemoria;

}
//buscar cliente
//Chequear datos
//Chequear estado
//-------------------------------------------ARCHIVOS-------------------------------------------
Archi LeerArchivoActividades(ifstream& Archivo,Sgym* Gimnasio){
    if (!Archivo.is_open())
        return ErrAbrirArchivo;

    Archivo.clear();//reestablezco el flujo correcto del archivo
    Archivo.seekg(0,ios::beg);//envio el puntero que recorre el archivo al inicio
//---------------------VARIABLES NECESARIAS PARA EL ARCHIVO-------------------------
    str header,line;//manejo de archivos
    char delimiter= ',';//Es un csv entonces por cada coma debe contar un elemento

    getline(Archivo,header);//separo el encabezado
//---------------------AUXILIARES----------------------
    str NomAct,horarios,id;//despues debo castearlos
    int i,j,k,l,m,n,o,horariosI;
    i=j=k=l=m=n=o=0;

    while(Archivo.good()&&!Archivo.eof()){
        getline(Archivo,line);
        istringstream iss(line);//permite leer los "campos de la linea"
        getline(iss,id,delimiter);//de donde leo, a donde leo, hasta donde leo
        getline(iss,NomAct,delimiter);
        getline(iss,horarios,delimiter);
        horariosI=stoi(horarios);
        if(horariosI>=8&&horariosI<=19){
            if(NomAct.compare("Spinning")==0){
                Gimnasio->actividades[0].horarios[i]=stoi(horarios);
                Gimnasio->actividades[0].IdClase[i]=stoi(id);
                i++;
            }
            else if(NomAct.compare("Yoga")==0){
            Gimnasio->actividades[1].horarios[j]=stoi(horarios);
            Gimnasio->actividades[1].IdClase[j]=stoi(id);
            j++;
            }
            else if(NomAct.compare("Pilates")==0){
                Gimnasio->actividades[2].horarios[k]=stoi(horarios);
                Gimnasio->actividades[2].IdClase[k]=stoi(id);
                k++;
            }
            else if(NomAct.compare("Stretching")==0){
            Gimnasio->actividades[3].horarios[l]=stoi(horarios);
            Gimnasio->actividades[3].IdClase[l]=stoi(id);
            l++;
            }
            else if(NomAct.compare("Zumba")==0){
                Gimnasio->actividades[4].horarios[m]=stoi(horarios);
                Gimnasio->actividades[4].IdClase[m]=stoi(id);
                m++;
            }
            else if(NomAct.compare("Boxeo")==0){
                Gimnasio->actividades[5].horarios[n]=stoi(horarios);
                Gimnasio->actividades[5].IdClase[n]=stoi(id);
                n++;
            }
            else if(NomAct.compare("Musculacion")==0){
                Gimnasio->musculacion->horarios[o]=stoi(horarios);
                Gimnasio->musculacion->iDClase[o]=stoi(id);
                o++;
            }
        }else if(horariosI>=7&&horariosI<8||horariosI>=19&&horariosI<=21){
            if(NomAct.compare("Musculacion")==0){
            Gimnasio->musculacion->horarios[o]=stoi(horarios);
            Gimnasio->musculacion->iDClase[o]=stoi(id);
            o++;
            }
        }
    }

    return ArchivoManipuladoConExito;
}
int ContarCantClientes(ifstream& Archivo){
    if(!Archivo.is_open())
        return -1;

    Archivo.clear();
    Archivo.seekg(0,ios::beg);//envio el puntero que recorre el archivo al inicio

    int cont=0;
    str encabezado,linea;
    getline(Archivo,encabezado);//quito el encabezado

    while(Archivo.good()&&!Archivo.eof()&&getline(Archivo,linea))
        cont++;
    return cont;
}
Archi LeerArchivoClientes(ifstream& Archivo,Sgym*Gimnasio,int &cantclientes,int cantclientesT){
    if(!Archivo.is_open())
        return ErrAbrirArchivo;

    Archivo.clear();
    Archivo.seekg(0,ios::beg);//envio el puntero que recorre el archivo al inicio

    str encabezado,linea;
    char delimitador=',';
    getline(Archivo,encabezado);//quito el encabezado

    //---------AUXILIARES------
    str idCliente,Nombre,Apellido,Mail,Telefono,FechaNac,Estado;
    int dia,mes,anio,i;
    i=0;
    //---------RESIZE----------
    if(cantclientes<cantclientesT)
        ResizeCliente(Gimnasio->clientes,cantclientes,cantclientesT);//si no tengo espacio hago un resize

    while(Archivo.good()&&!Archivo.eof()&&i<Gimnasio->CantClientes){
        getline(Archivo,linea);
        stringstream s(linea);
        getline(s,idCliente,delimitador);
        getline(s,Nombre,delimitador);
        getline(s,Apellido,delimitador);
        getline(s,Mail,delimitador);
        getline(s,Telefono,delimitador);
        getline(s,FechaNac,delimitador);
        getline(s,Estado,delimitador);
        //---------------GUARDADO--------------------------
        Gimnasio->clientes[i].idCliente=stoi(idCliente);
        Gimnasio->clientes[i].Nom=Nombre;
        Gimnasio->clientes[i].Ape=Apellido;
        Gimnasio->clientes[i].mail=Mail;
        Gimnasio->clientes[i].Telefono=Telefono;
        SepararFecha(FechaNac,dia,mes,anio);//separo la fecha en dia mes y año para guardarla en mi struct
        Gimnasio->clientes[i].FechaNac.dia=dia;
        Gimnasio->clientes[i].FechaNac.mes=mes;
        Gimnasio->clientes[i].FechaNac.anio=anio;
        Gimnasio->clientes[i].estado=stoi(Estado);
        i++;
    }
    return ArchivoManipuladoConExito;
}
void SepararFecha(string fecha, int& dia, int& mes, int& anio) {
    istringstream ss(fecha);
    char delimitador = '-';
    string campo;

    getline(ss, campo, delimitador);
    dia = stoi(campo);

    getline(ss, campo, delimitador);
    mes = stoi(campo);

    getline(ss, campo, delimitador);
    anio = stoi(campo);
}
