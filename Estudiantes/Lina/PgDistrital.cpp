#include <iostream> // entrada y salida de datos
#include <conio.h>	//para la función getch() para que no se cierren
#include <stdlib.h> // system("pause")
#include <string.h>	//cadenas de caracteres


using namespace std;// estandar de c++ std::cout
//------------------------------------------
//		:::MENUS:::

//		:::MENU USUARIO:::
void MenuUsuario(string usuario){
	int opcion;// Variable local solo se podrá utilizar dentro de la función
	do{
		cout<<"\t:::CONFIGURACIONES  -> "<<usuario<<" :::"<<endl;
		cout<<"1.Crear."<<endl;
		cout<<"2.Leer."<<endl;
		cout<<"3.Actualizar."<<endl;
		cout<<"4.Eliminar"<<endl;
		cout<<"5.Salir"<<endl;
		cout<<"\nDigite Una Opcion de Menu: ";
		cin>>opcion;

		switch(opcion){
			case 1:
				//Crear(usuario);
				break;
			case 2:
				//Leer(usuario);
				break;
			case 3:
				//Actualizar(usuario);
				break;
			case 4:
				//Eliminar(usuario);
				break;
			case 5:
				break;
			default:cout<<"Se equivoco de opcion de Menu"<<endl;
		}
	}while(opcion != 3);
}

//		:::MENU ADMINISTRADOR:::
void MenuAdministrador(){
	int opcion;// Variable local solo se podrá utilizar dentro de la función
	do{
		cout<<"\t:::MENU ADMINISTRADOR:::"<<endl;
		cout<<"1.Estudiante."<<endl;
		cout<<"2.Profesor."<<endl;
		//cout<<"3.Materias."<<endl;
		cout<<"3.Salir"<<endl;
		cout<<"\nDigite Una Opcion de Menu: ";
		cin>>opcion;

		switch(opcion){
			case 1:
				MenuUsuario("Estudiante");
				break;
			case 2:
				MenuUsuario("Profesor");
				break;
			case 3:
				break;
			default:cout<<"Se equivoco de opcion de Menu"<<endl;
		}
	}while(opcion != 3);
}

void MenuPrincipal(){
	int opcion;// Variable local solo se podrá utilizar dentro de la función
	do{
		cout<<"\t:::PAGINA DISTRITAL:::"<<endl;
		cout<<"1.Estudiante."<<endl;
		cout<<"2.Profesor."<<endl;
		cout<<"3.Administrador."<<endl;
		cout<<"4.Salir"<<endl;
		cout<<"\nDigite Una Opcion de Menu: ";
		cin>>opcion;
		cout<<"Pase pr aca";
		switch(opcion){
			case 1:
				//MenuEstudiante();
				break;
			case 2:
				//MenuProfesor();
				break;
			case 3:
				MenuAdministrador();
				system("pause");
				break;
			case 4:
				break;
			default:cout<<"Se equivoco de opcion de Menu"<<endl;
		}
	}while(opcion != 4);
}

//------------------------------------------

//		:::FUNCION PRINCIPAL:::
int main(int argc, char *argv[]) {
	MenuPrincipal();
	system("pause");
	return 0; // debe retornar un 0
}
