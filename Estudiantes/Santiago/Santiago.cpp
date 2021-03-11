#include <iostream>

using namespace std;

int main ()
{
	string respuesta = "s"; // si el usuario continua o no ingresando 
	int numTarjeta = 0;// vamos guardar el numero 1000 y 9999
	int pri,seg,ter,cua;// guardar 1080 pri=1, seg=0, ter=8, cuA=0
	int suma;
	int nuevo_digito;
	
	while(respuesta == "s" | respuesta=="S"){// esta en s para ingresar de una vez al ciclo
		cout<<"Ingrese el Numero de la Tarjeta: ";
		cin>>numTarjeta;//guardar
	
		if(numTarjeta>=1000 && numTarjeta<=9999){// que este dentro de este rango
			pri = numTarjeta / 1000;
			seg = numTarjeta / 100;
			ter = numTarjeta / 10;
			cua = numTarjeta % 10; // 2035 % 10 -> 108
			suma = pri + seg + ter + cua;
			if (suma % 2 == 0){
				// par
				nuevo_digito = numTarjeta * 10;
			}
			else{
				//impar
				nuevo_digito = (numTarjeta*10) + 1;	
			}
			cout << "Su Numero Tarjeta es :"<<nuevo_digito<<endl;
		
		}
		else{
			cout<<"Ingrese un numero entre 1000 y 9999"<<endl<<endl;
		}
		
		cout<<"Presione SI para continuar, NO para Salir(S/N): ";
		cin>>respuesta;
	}
	
	cout<<"Muchas gracias"<<endl;
	return 0;
}
