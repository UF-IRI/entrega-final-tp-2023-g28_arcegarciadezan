#include "Funciones.h"
/*ini inicializarVariablesFijas(Sgym* Gimnasio){
    //esta funcion inicializa los datos que son fijos en mis variables, como los cupos y los id reservas(van a estar inicializados en 0)
    int i;
    Gimnasio->CantClases=6;//la cantidad de clases es fijo
    Gimnasio->actividades=new Sact[Gimnasio->CantClases];
    if(Gimnasio->actividades==nullptr)
        return ErrReservarmemoria;

    //--------SPINNING--------
    Gimnasio->actividades[0].CantHorarios=5;
    Gimnasio->actividades[0].cupos=new int[Gimnasio->actividades[0].CantHorarios];
    if(Gimnasio->actividades[0].cupos==nullptr)
        return ErrReservarmemoria;
    for(i=0;i<Gimnasio->actividades[0].CantHorarios;i++)
    {
    Gimnasio->actividades[0].cupos[i]=45;//todas las actividades de spinning tienen 45 cupos cada una
    }
    //-------YOGA-------
    Gimnasio->actividades[1].CantHorarios=6;
    Gimnasio->actividades[1].cupos=new int[Gimnasio->actividades[1].CantHorarios];
    if(Gimnasio->actividades[1].cupos==nullptr)
        return ErrReservarmemoria;
    for(i=0;i<Gimnasio->actividades[1].CantHorarios;i++)
    {
    Gimnasio->actividades[1].cupos[i]=25;
    }
    //-------PILATES-------
    Gimnasio->actividades[2].CantHorarios=6;
    Gimnasio->actividades[2].cupos=new int[Gimnasio->actividades[2].CantHorarios];
    if(Gimnasio->actividades[2].cupos==nullptr)
        return ErrReservarmemoria;
    for(i=0;i<Gimnasio->actividades[2].CantHorarios;i++)
    {
    Gimnasio->actividades[2].cupos[i]=15;
    }
    //---------STRETCHING----------
    Gimnasio->actividades[3].CantHorarios=6;
    Gimnasio->actividades[3].cupos=new int[Gimnasio->actividades[3].CantHorarios];
    if(Gimnasio->actividades[3].cupos==nullptr)
        return ErrReservarmemoria;
    for(i=0;i<Gimnasio->actividades[3].CantHorarios;i++)
    {
    Gimnasio->actividades[3].cupos[i]=40;
    }
    //-------ZUMBA---------
    Gimnasio->actividades[4].CantHorarios=6;
    Gimnasio->actividades[4].cupos=new int[Gimnasio->actividades[4].CantHorarios];
    if(Gimnasio->actividades[4].cupos==nullptr)
        return ErrReservarmemoria;
    for(i=0;i<Gimnasio->actividades[4].CantHorarios;i++)
    {
    Gimnasio->actividades[4].cupos[i]=50;
    }
    //------BOXEO-------
    Gimnasio->actividades[5].CantHorarios=4;
    Gimnasio->actividades[5].cupos=new int[Gimnasio->actividades[5].CantHorarios];
    if(Gimnasio->actividades[5].cupos==nullptr)
        return ErrReservarmemoria;
    for(i=0;i<Gimnasio->actividades[5].CantHorarios;i++)
    {
    Gimnasio->actividades[5].cupos[i]=30;
    }
    return inicializacionexitosa;
    //libero memoria en el main, porque si borro la memoria dinamica aca no estaria inicializando nada
}*/
int BuscarActividadPorNombre(Sgym ActsGim,str actividadPasada){
    int i=0,posact=0;

    while(ActsGim.actividades[i].nombre.compare(actividadPasada)!=0){
        if(posact==5)//si lo encuentra en la ultima posicion no seria necesario que entre al while
            return -1;//Actividad no encontrada
        posact++;
        i++;
    }
    return posact;
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
    if(pos0==-1)
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
