#include <iostream>

using namespace std;

int main ()
{
	
	int altura_actual = 0;
	int recorrido = -1;
	int altura_max = 0;
	int altura_min = 99999999;// exagera el numero
	
	int subida = 0;
	int bajada = 0;
	
	int mon = 0;
	int mon_ancha = 0;
	
	int altura_pasada_2=0;
	
	while(altura_actual >= 0 ){
		int altura_pasada = altura_actual; // guardo altura pasada
		cout << "Altura Actual: ";
		cin>>altura_actual;
		
		if (altura_actual>=0){
			recorrido ++;//recorrido
		}
		
		if (altura_actual > altura_max){//guardo la altura maxima
			altura_max = altura_actual;
		}
		
		if (altura_actual < altura_min && altura_actual>0){//guarda la altura minima
			altura_min = altura_actual;
		}
		
		
		
		
		
	}
	
	cout <<"Ud recorrio un total de "<<recorrido<<" kilometros"<<endl;
	cout<<"Su maxima altura fue de "<<altura_max<<" msn"<<endl;
	cout<<"Su minima altura fue de "<<altura_min<<" msn"<<endl;
	return 0;
}
