#include <catch2/catch.hpp>
#include "Funciones.h"
#include "FuncionesImp.cpp"
#include "Includes.h"

TEST_CASE("CASO 1")
{
    int i;
    Sgym* Gimnasio=new Sgym;
    REQUIRE(Gimnasio!=nullptr);//me asegguro que haya hecho buen uso de la memoria dinamica o que no fallo
    Gimnasio->CantClases=2;
    Gimnasio->actividades=new Sact[Gimnasio->CantClases];
    REQUIRE(Gimnasio->actividades!=nullptr);
    //--------------------------------------SPINNING----------------------------------------
    Gimnasio->actividades[0].CantHorarios=5;
    Gimnasio->actividades[0].horarios=new int[Gimnasio->actividades[0].CantHorarios];
    Gimnasio->actividades[0].cupos=new int[Gimnasio->actividades[0].CantHorarios];
    Gimnasio->actividades[0].IdClase=new int[Gimnasio->actividades[0].CantHorarios];
    REQUIRE(Gimnasio->actividades[0].horarios!=nullptr);
    REQUIRE(Gimnasio->actividades[0].cupos!=nullptr);
    REQUIRE(Gimnasio->actividades[0].IdClase!=nullptr);

    //----------------------------------------NOMBRE----------------------------------------
    Gimnasio->actividades[0].nombre="Spinning";
    //-----------------------------------------CUPOS----------------------------------------
    for(i=0;i< Gimnasio->actividades[0].CantHorarios;i++)
        Gimnasio->actividades[0].cupos[i]=45;
    //----------------------------------------HORARIO---------------------------------------
    Gimnasio->actividades[0].horarios[0]=8;
    Gimnasio->actividades[0].horarios[1]=10;
    Gimnasio->actividades[0].horarios[2]=12;
    Gimnasio->actividades[0].horarios[3]=16;
    Gimnasio->actividades[0].horarios[4]=18;
    //------------------------------------------ID------------------------------------------
    Gimnasio->actividades[0].IdClase[0]=1;
    Gimnasio->actividades[0].IdClase[1]=2;
    Gimnasio->actividades[0].IdClase[2]=3;
    Gimnasio->actividades[0].IdClase[3]=4;
    Gimnasio->actividades[0].IdClase[4]=5;



    //-----------------------------------------BOXEO----------------------------------------
    Gimnasio->actividades[1].CantHorarios=4;
    Gimnasio->actividades[1].horarios=new int[Gimnasio->actividades[1].CantHorarios];
    Gimnasio->actividades[1].cupos=new int[Gimnasio->actividades[1].CantHorarios];
    Gimnasio->actividades[1].IdClase=new int[Gimnasio->actividades[1].CantHorarios];
    REQUIRE(Gimnasio->actividades[1].horarios!=nullptr);
    REQUIRE(Gimnasio->actividades[1].cupos!=nullptr);
    REQUIRE(Gimnasio->actividades[1].IdClase!=nullptr);
    //----------------------------------------NOMBRE----------------------------------------
    Gimnasio->actividades[1].nombre="Boxeo";
    //-----------------------------------------CUPOS----------------------------------------
    for(i=0;i< Gimnasio->actividades[1].CantHorarios;i++)
        Gimnasio->actividades[1].cupos[i]=30;
    //----------------------------------------HORARIO---------------------------------------
    Gimnasio->actividades[1].horarios[0]=8;
    Gimnasio->actividades[1].horarios[1]=17;
    Gimnasio->actividades[1].horarios[2]=18;
    Gimnasio->actividades[1].horarios[3]=19;

    //------------------------------------------ID------------------------------------------
    Gimnasio->actividades[1].IdClase[0]=30;
    Gimnasio->actividades[1].IdClase[1]=31;
    Gimnasio->actividades[1].IdClase[2]=32;
    Gimnasio->actividades[1].IdClase[3]=33;

    //--------------------------------------CLIENTES----------------------------------------
    Gimnasio->ClientesMax=300;
    Gimnasio->CantClientes=4;
    Gimnasio->clientes=new Scliente[Gimnasio->CantClientes];
    Gimnasio->clientes[0]={"Hugh","Monahan","Hugh.Monahan18@gmail.com","1 (415) 935-4832",{"Spinning","","Spinning"},{12,11,1990},0,1,{1,0,3},{8,0,12}};
    Gimnasio->clientes[1]={"Carla","Rober","Carla.Rober@gmail.com","1 (603) 037-9228",{"Boxeo","Spinning","Spinning"},{15,11,1970},4,2,{30,0,3},{8,0,12}};
    Gimnasio->clientes[2]={"Sidney","Runolfsson","Sidney.Runolfsson@hotmail.com","1 (433) 165-6466",{"Spinning","","Spinning"},{1,4,2000},3,3,{2,0,3},{10,0,12},};
    Gimnasio->clientes[3]={"Emma","O'Connell","Emma_OConnell@gmail.com","1 (493) 966-7600",{"Spinning","Spinning","Spinning"},{12,1,1995},2,4,{1,1,3},{8,8,12}};
    //-------------------------------------FUNCIONES-----------------------------------------
    SECTION("buscar"){
        int posH,posN;//posH1,posN1,posN3,posH3;
        posN=BuscarActividadPorNombre(*Gimnasio,"ASdo");
        CHECK(posN!=-1);
        //posH=BuscarActividadPorHorario(*Gimnasio,18,"Spinning");
        //CHECK(posH==0);//Falso
        //CHECK(Gimnasio->actividades[posN].horarios[posH]==Gimnasio->actividades[0].horarios[4]);
        //posN1=BuscarActividadPorNombre(*Gimnasio,"Pilates");
        //CHECK(posN!=-1);//verdadero
        //posH1=BuscarActividadPorHorario(*Gimnasio,12,"Pilates");
        //CHECK(posH1==0);//falso
        //CHECK(Gimnasio->actividades[posN1].horarios[posH1]==Gimnasio->actividades[2].horarios[3]);//verdadero
        //posN3=BuscarActividadPorNombre(*Gimnasio,"Yoga");
        //CHECK(posN3==-1);//verdadero actividad no inicializada
        posH=BuscarActividadPorHorario(*Gimnasio,19,posN);
        CHECK(posH==-4);
    }

    SECTION("RESIZE"){
        ResizeCliente(Gimnasio->clientes,Gimnasio->CantClientes,6);
        REQUIRE(Gimnasio->clientes!=nullptr);
        CHECK(Gimnasio->CantClientes==6);
    }

    SECTION("chequeoAct"){
        int pos0,posH,posN;
        posN=BuscarActividadPorNombre(*Gimnasio,"Spiing");
        posH=BuscarActividadPorHorario(*Gimnasio,8,posN);

        pos0=ChequeoActs(Gimnasio->clientes[0],*Gimnasio,posH,posN);
        CHECK(pos0==-4);//horario no valido(deberia ser verdadero)
        //pos0=ChequeoActs(Gimnasio->clientes[0],*Gimnasio,posH,posN);
        //CHECK(pos0==2);//dio falso correctamente
        //pos0=ChequeoActs(Gimnasio->clientes[2],*Gimnasio,posH,posN);
        //CHECK(pos0==1);//dio verdadero correctamente
    }

   /* SECTION("RESERVA"){
        int posN,posH,posrepeN;
        posrepeN=-2;
        posN=BuscarActividadPorNombre(*Gimnasio,"Boxeo");
        posH=BuscarActividadPorHorario(*Gimnasio,18,posN);

        ReservarAct(Gimnasio,&(Gimnasio->clientes[0]),posN,posH,&posrepeN);
        if(posrepeN!=-2)
            cout<<"Tienes "<<Gimnasio->clientes[0].NomReserva[posrepeN]<<"a esa hora"<<endl;
        CHECK(Gimnasio->actividades[1].cupos[2]==29);//esa es la actividad que quiero reservar
        CHECK(Gimnasio->clientes[0].iDClasereserv[1]!=0);
    }*/

    SECTION("CANCELAR RESERVA"){
        int posN,posH,posrepeN;
        posrepeN=-2;
        posN=BuscarActividadPorNombre(*Gimnasio,"Boxeo");
        posH=BuscarActividadPorHorario(*Gimnasio,18,posN);
         ReservarAct(Gimnasio,&(Gimnasio->clientes[0]),posN,posH,&posrepeN);
        CancelarReserva(Gimnasio,&(Gimnasio->clientes[0]),posN,posH);
         CHECK(Gimnasio->actividades[1].cupos[2]==30);
         CHECK(Gimnasio->clientes[0].iDClasereserv[1]==0);
    }

    SECTION("BUSCAR CLIENTE"){
        int pos;
        bool chequeo;
        pos=BuscarClientePorId(*Gimnasio,1);
        REQUIRE(pos==0);
        chequeo=ChequearEstado(Gimnasio->clientes[pos]);
        REQUIRE(chequeo==true);
    }

    for (int i = 0; i < Gimnasio->CantClases; ++i) {
        delete[] Gimnasio->actividades[i].horarios;
        delete[] Gimnasio->actividades[i].cupos;
        delete[] Gimnasio->actividades[i].IdClase;
    }
    delete[] Gimnasio->clientes;


   delete Gimnasio;
}
TEST_CASE("Inicializacion"){
    Sgym* Gimnasio=new Sgym;

    inicializarVariablesFijas(Gimnasio);

    CHECK(Gimnasio->actividades[3].cupos[0]==40);


    for (int i = 0; i < Gimnasio->CantClases; ++i) {
        delete[] Gimnasio->actividades[i].horarios;
        delete[] Gimnasio->actividades[i].cupos;
        delete[] Gimnasio->actividades[i].IdClase;
    }
    delete[] Gimnasio->actividades;
    delete[] Gimnasio->musculacion->horarios;
    delete[] Gimnasio->musculacion->iDClase;
    delete Gimnasio->musculacion;

    delete Gimnasio;

}
TEST_CASE("ArchivoActividades"){
    Sgym* Gimnasio=new Sgym;
    inicializarVariablesFijas(Gimnasio);
    ifstream InputActividades;
    InputActividades.open("../iriClasesGYM.csv");

    SECTION("LeerArchivos"){
    LeerArchivoActividades(InputActividades,Gimnasio);
    REQUIRE(Gimnasio!=nullptr);
    CHECK(Gimnasio->actividades[4].horarios[3]==16);
    }



    InputActividades.close();
    for (int i = 0; i < Gimnasio->CantClases; ++i) {
        delete[] Gimnasio->actividades[i].horarios;
        delete[] Gimnasio->actividades[i].cupos;
        delete[] Gimnasio->actividades[i].IdClase;
    }
    delete[] Gimnasio->actividades;
    delete[] Gimnasio->musculacion->horarios;
    delete[] Gimnasio->musculacion->iDClase;
    delete Gimnasio->musculacion;

    delete Gimnasio;

}
TEST_CASE("ArchivoClientes"){
    ifstream InputClientes;
    InputClientes.open("../iriClientesGYM.csv");
    Sgym* Gimnasio=new Sgym;



    /*
    SECTION("CONTARCLIENTES"){
        int cont;
        cont=ContarCantClientes(InputClientes);
        REQUIRE(cont!=-1);
    }
*/
    SECTION("LEERCLIENTES"){
        /*int cont;
        cont=ContarCantClientes(InputClientes);
        REQUIRE(cont==250);*/
        LeerArchivoClientes(InputClientes,Gimnasio,Gimnasio->CantClientes,3);
        REQUIRE(Gimnasio->clientes[2].Ape.compare("Lanaro"));

        delete[] Gimnasio->clientes;
    }

    InputClientes.close();
    delete Gimnasio;
}
