#include <iostream>
#include "Persona.h"
using namespace std;

int main(int argc,char ** argv){

    //Objeto estatico
    Persona p1 ("Katherin" , 19);
    cout<<"el nombe es "<<p1.getNombre()<<endl;
    cout<<"la edad es "<<p1.getEdad()<<endl;
    

    //objeto dinamico
    Persona *p2 = new Persona();
        p2->setNombre("jhon");
        
        p2->setEdad(29);

        cout<<"el nombe es "<<p2-> getNombre()<<endl;
    cout<<"la edad es "<<p2->getEdad()<<endl;
    Persona p3 [4];//creación de un arreglo estatico (crea 4 espacios a persona)

    Persona *p4 = new Persona[4];//CREACIÓN DE ARREGLO DINAMICO
        cout<<"\t::PEDIR DATOS:: "<<endl;
        for(int i=0;i<4; i++){
            (p4+i)->pedirDatos();
            cout<<endl;

        }
        cout<<"\t::MOSTRAR DATOS:: "<<endl;
        for(int i=0;i<4; i++){
            (p4+i)->MostrarDatos();
            cout<<endl;

            

        }

        delete p4;//liberando memoria








    return 0;

}