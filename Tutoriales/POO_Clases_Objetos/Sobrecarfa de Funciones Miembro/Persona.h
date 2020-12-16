//Implementación Persona
/*Cuando se puede inicializar el objeto de diferentes formas es decir:
Como se muestran los ejemplos de creación de los constructores
depende de los atributos o parametros que se les envia
*/
#include<iostream>

using namespace std;

class Persona{
	//Atributos
	private:
		string nombre;
		int edad;
		string dni;
		
	//Métodos
	public:
		Persona(string _nombre,int _edad){//Constructor 1
			nombre = _nombre;
			edad = _edad;
		}
		
		Persona(string _dni){//Constructor 2
			dni = _dni;
		}
		
		//Métodos
		void correr(){
			cout<<"Soy "<<nombre<<", tengo "<<edad<<" anios y estoy corriendo una maraton"<<endl;
		}
		
		void correr(int km){
			cout<<"He Corrido "<<km<<" Kilometros"<<endl;
		}
};
