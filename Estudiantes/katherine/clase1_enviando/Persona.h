#include <iostream>
using namespace std;

class Persona {

    private://atributos
        string Nombre, Cedula;
        int edad;
    
    public://metodos
        Persona(){
        //constructor por defecto
    }

        Persona(string Nombre , int edad){
         this -> Nombre = Nombre;//this llamando a atributo
          this -> edad = edad;
    }
        //DESTRUCTOR
        ~Persona(){

        }

    void setNombre(string _Nombre);
     void setEdad(int _edad);
     string getNombre ();
    int getEdad ();
    void pedirDatos();
    void MostrarDatos();

 
};