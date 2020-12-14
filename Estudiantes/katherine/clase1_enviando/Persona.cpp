#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"

void Persona::setNombre(string _Nombre){//metodo pertenecea la clase persona

    Nombre = _Nombre;
}
void Persona:: setEdad(int _edad){
    edad = _edad;
}
 string Persona::getNombre (){
     
    return Nombre;
 }
 int Persona ::getEdad (){

     return edad;
 }
 void Persona:: pedirDatos(){
     fflush(stdin);//si se salta ponerlo(vaciar buffer)
     cout<<"ingrese el nombre ";
     getline(cin,Nombre);//--------------------------------------------------Cambio 1
     fflush(stdin);//si se salta ponerlo(vaciar buffer)
     cout<<"ingrese la edad ";
     fflush(stdin);//si se salta ponerlo(vaciar buffer)
          cin>>edad;
    
     cout<<"ingrese la cedula ";
     fflush(stdin);//si se salta ponerlo(vaciar buffer)
     getline(cin,Cedula);
 }
    void Persona::MostrarDatos(){
        cout<<"Nombre: "<<Nombre<<endl;
        cout<<"Edad: "<<edad<<endl;
        cout<<"Cedula: "<<Cedula<<endl;



    }


