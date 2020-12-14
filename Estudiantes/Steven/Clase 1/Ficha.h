//		:::DECLARACIÓN DE LA CLASE FICHA:::

#include<iostream>


using namespace std;


class Ficha{
	//Atributos
	private:
		string ficha;

	public:
		//Metodos
		
		Ficha(){
			
		}
		
		
		//28-08-20
		void setFicha(string Ficha){
			ficha="";
			for(int i=0;i<Ficha.length();i++){
				ficha += toupper(Ficha[i]);//mayuscula
			}
		}
		string getFicha(){
			return ficha;
		}
		
		bool FichaExiste();
	
};
