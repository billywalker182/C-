#include <stdio.h>
#include <stdlib.h>


//		:::VARIABLES GLOBALES:::
int matriz[100][100];//Matriz
int tam = 0;//Para dar el tamaño a la matriz
int sumaFila[100];//
int sumaCol[100];
int sumaDiagonal = 0;
int triangularSuperior[100];
int triangularInferior[100];
int numSuperior = 0;
int numInferior = 0;
int diagonalSecundaria = 0;

//		:::FUNCIONES:::

void LimpiarVariables(){
	sumaDiagonal = 0;
	numSuperior = 0;
	numInferior = 0;
	diagonalSecundaria = 0;
	for(int i = 0;i<tam;i++){
		sumaFila[i]=sumaCol[i]=0;
	}
}
void Menu(){//mostrar menu usuario
	printf("\t:::ARREGLO BIDIMIENSIONAL:::\n");
	printf("1.Crera Matriz.\n");
	printf("2.Mostrar Matriz Por Fila.\n");
	printf("3.Total Filas, Fila con Mayor Total.\n");
	printf("4.Promedio Columnas, Columna con Menor Valor.\n");
	printf("5.Sumatoria de los Valores Ubicados en la Diagonal Principal.\n");
	printf("6.Numeros Pares Ubicados en la Matriz Triangular Superior.\n");
	printf("7.Numeros Impares Ubicados en la Matriz Triangular Inferior.\n");
	printf("8.Promedio de los Valores Ubicados en la Diagonal Secundaria.\n");
	printf("9.Salir\n");
	printf("\nDigite Una Opcion de Menu: ");
}

//	:::CREAR MATRIZ:::
void CrearMatriz(){
	
	//numero = rand () % (N-M+1) + M;   // Este está entre M y N
	tam = rand () % (10-2+1) + 2;   // Tamaño de la Matriz(2 - 10)//crear tamaño aleatorio de matriz
	
	for(int i=0;i<tam;i++){
		for(int j=0;j<tam;j++){
				matriz[i][j] = rand () % (50-1+1) + 1;//ingresar a la matriz datos aleatorios de 1 a 50
		}
		
	}
}

//			::::MOSTRAR LA MATRIZ:::
void MostrarMatriz(){
	printf("\n");
	LimpiarVariables();
	for(int i=0;i<tam;i++){//filas
		printf("Fila %d: ",i);
		for(int j=0;j<tam;j++){//columnas
			printf("%d  ",matriz[i][j]);//Mostrar matriz
			sumaFila[i] = sumaFila[i] + matriz[i][j];//suma de cada fila
			sumaCol[i] = sumaCol[i] + matriz[j][i];//suma de cada columna
			
			if(j==(tam-1)-i){
				diagonalSecundaria = diagonalSecundaria + matriz[i][j];//suma diagonal secundaria
			}
			if(i==j){//Diagonal Principal
				sumaDiagonal = sumaDiagonal + matriz[i][j];//Suma diagonal
			}
			if(i>=j){//Triangular Superior
				if(matriz[i][j]%2==0){//numeros pares de triangular superior
					triangularSuperior[numSuperior] = matriz[j][i];
					numSuperior++;
				}
				
			}
			else{
				if(matriz[i][j]%2!=0){//numeros  impares triangular inferior
					triangularInferior[numInferior] = matriz[j][i];
					numInferior++;
				}
			}
		}
		printf("\n");
	}
}

//		:::Al calcular el total por filas. Cuál es la fila con mayor total. :::
void TotalFila(){
	MostrarMatriz();//mostrar matriz
	printf("\n");
	int _temp = 0;
	int _num = 0;
	for(int i=0;i<tam;i++){
		printf("Valor Fila %d: %d\n",i,sumaFila[i]);
		if(sumaFila[i]>_temp){
			_temp = sumaFila[i];//indicar cual fila es mayor
			_num = i;
		}
		sumaFila[i] = 0;
	}
	printf("\nLa Fila Con Mayor Total es la: %d\n",_num);//mostrar la fila con mayor valor
}

//	:::Al calcular el promedio por columnas. Cuál es la columna con menor valor. :::
void PromedioColumna(){
	MostrarMatriz();//mostra matriz
	printf("\n");
	int _temp = 9999999;
	int _num = 0;
	float _tam = tam;
	for(int i=0;i<tam;i++){
		float resultado = sumaCol[i] / _tam;//proemdio columnas
		printf("Valor Promedio Columna %d: %f\n",i,resultado);//mostrar el promedio columna
		if(sumaCol[i]<_temp){
			_temp = sumaCol[i];//promedio columna con menor valor
			_num = i;
		}
	}
	printf("\nLa Columna Con Menor Promedio es la: %d\n",_num);//mostrar promedio columna de menos valor
}

//	::: Sumatoria de los valores ubicados en la diagonal principal. :::

void DiagonalPrincipal(){
	MostrarMatriz();//mostrar matriz
	printf("\nLa Suma de la Diagonal principal es: %d",sumaDiagonal);//mostrar suma diagonal
}

//:::Cuantos números pares están ubicados en la matriz triangular superior:::
void NumerosPares(){
	MostrarMatriz();//mostrar matriz
	printf("\nLos Numeros Pares de la Matriz Triangular Superior Son: %d",numSuperior);//mostrar cantidad numeros pares
}

// :::Cuantos números impares están ubicados en la matriz triangular inferior. :::
void NumerosImpares(){
	MostrarMatriz();// mostrar matriz
	printf("\nLos Numeros Impares de la Matriz Triangular Inferior Son: %d",numInferior);//mostrar cantidad numeros impares
}

//		:::Promedio de los valores ubicados en la diagonal secundaria:::
void PromedioDiagonalSecundaria(){
	MostrarMatriz();//mostrar matriz
	float _tam = tam;
	float tempPromedio = diagonalSecundaria / _tam;
	printf("%d",diagonalSecundaria);//mostrar suma diagonal secundaria
	printf("\nPromedio de los Valores de la Diagonal Secundaria: %f",tempPromedio);//mostrar promedio de la diagonal secundaria
}


//	:::funcion principal:::
int main(int argc, char** argv) {
	int opcion = 0; // guardar dato para el menu
	do{
		Menu();
		scanf("%d",&opcion);//usuario ingrese lo guarda en la opcion menu
		switch(opcion){
			case 1:
				CrearMatriz();
				printf("\n");
				break;
			case 2:
				MostrarMatriz();
				printf("\n");
				break;
			case 3:
				TotalFila();
				printf("\n");
				break;
			case 4:
				PromedioColumna();
				printf("\n");
				break;
			case 5:
				DiagonalPrincipal();
				printf("\n");
				break;
			case 6:
				NumerosPares();
				printf("\n");
				break;
			case 7:
				NumerosImpares();
				printf("\n");
				break;
			case 8:
				PromedioDiagonalSecundaria();
				printf("\n");
				break;		
			case 9:
				break;
			default:printf("Se equivoco de opcion de Menu\n");
		}
		printf("\n");
		system("pause");
		system("cls");
	}while(opcion != 9);
	return 0;
}
