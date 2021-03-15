// Declaracion clase

//1. Nombre de la clase .h archivo de cabecera

#include<iostream>

using namespace std;


class Persona{
	//Atributos
	private:
		string nombre;
		int edad;
		string cedula;
		
	//Metodos
	public:
		//Constructor es aque que tiene el mismo nombre de la clase y nos va permitir inicializar atributo de la clase
		Persona(){
			
		}
		Persona(string nombre, int edad){//string _nombre, int _edad
			this->nombre = nombre;//this hace referecia a su atributo
			this->edad = edad;
		}
		Persona(string cedula){//sobre carga metodos, dos metodos que son iguales pero se diferencIA QUE son diferentes argunmentos
			this->cedula = cedula;
		}
		
		~Persona(){//Destructor
			//cuando crea sobjetos necesitas liberar esa memoria
		}
		
		void setNombre(string _nombre);//Establecer un valor a num1
		void setEdad(int _edad);
		void setCedula(string _cedula);
		string getNombre();
		int getEdad();
		string getCedula();
		
		
		void pedirDatos();
		void mostrarDatos();
		
	
};


