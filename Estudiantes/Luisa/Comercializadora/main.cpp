#include <stdio.h>
#include <stdlib.h>


//		::::FUNCIONES:::
void Menu(){//Mostrar menu usuario
	printf("\t:::VENTAS DE PRODUCTOS DEL MES DE MARZO:::\n");
	printf("1.Unidades Vendidas Semanalmente por Vendedor\n");
	printf("2.Total de Unidades Vendidas Semanalmente por Producto\n");
	printf("3.Valor Vendido Semanalmente por Producto\n");
	printf("4.Suma Total de las Unidades Vendidas de Cada Producto\n");
	printf("5.Comisiones Para Vendedor Por Producto\n");
	printf("6.Comision Total por Vendedor en el Mes de Marzo\n");
	printf("7.Total a Pagar en Comisiones\n");
	printf("8.Semana En que se vendio Mas Unidades  del Producto A\n");
	printf("9.Semana En que se vendio Menos Unidades  del Producto B\n");
	printf("10.Vendedor Con Mas Ventas\n");
	printf("11.Salir\n");
	printf("\nDigite Una Opcion de Menu: ");
}

void PrimerPunto(int tempProducto[8][3]){
	printf("\n");
	
	
	printf("\t:::PRIMERA SEMANA:::\n");
	printf("Producto A: Juan %d -- Maria %d -- Luis %d\n",tempProducto[0][0],tempProducto[0][1],tempProducto[0][2]);
	printf("Producto B: Juan %d -- Maria %d -- Luis %d\n\n",tempProducto[1][0],tempProducto[1][1],tempProducto[1][2]);
	
	printf("\t:::SEGUNDA SEMANA:::\n");
	printf("Producto A: Juan %d -- Maria %d -- Luis %d\n",tempProducto[2][0],tempProducto[2][1],tempProducto[2][2]);
	printf("Producto B: Juan %d -- Maria %d -- Luis %d\n\n",tempProducto[3][0],tempProducto[3][1],tempProducto[3][2]);
	
	printf("\t:::TERCERA SEMANA:::\n");
	printf("Producto A: Juan %d -- Maria %d -- Luis %d\n",tempProducto[4][0],tempProducto[4][1],tempProducto[4][2]);
	printf("Producto B: Juan %d -- Maria %d -- Luis %d\n\n",tempProducto[5][0],tempProducto[5][1],tempProducto[5][2]);
	
	printf("\t:::CUARTA SEMANA:::\n");
	printf("Producto A: Juan %d -- Maria %d -- Luis %d\n",tempProducto[6][0],tempProducto[6][1],tempProducto[6][2]);
	printf("Producto B: Juan %d -- Maria %d -- Luis %d\n",tempProducto[7][0],tempProducto[7][1],tempProducto[7][2]);
}

void SegundoPunto(int tempProducto[8][3]){
	printf("\n");
	printf("\t:::PRIMERA SEMANA:::\n");
	printf("Producto A: %d\n",tempProducto[0][0]+tempProducto[0][1]+tempProducto[0][2]);
	printf("Producto B: %d\n\n",tempProducto[1][0]+tempProducto[1][1]+tempProducto[1][2]);
	
	printf("\t:::SEGUNDA SEMANA:::\n");
	printf("Producto A: %d\n",tempProducto[2][0]+tempProducto[2][1]+tempProducto[2][2]);
	printf("Producto B: %d\n\n",tempProducto[3][0]+tempProducto[3][1]+tempProducto[3][2]);
	
	printf("\t:::TERCERA SEMANA:::\n");
	printf("Producto A: %d\n",tempProducto[4][0]+tempProducto[4][1]+tempProducto[4][2]);
	printf("Producto B: %d\n\n",tempProducto[5][0]+tempProducto[5][1]+tempProducto[5][2]);
	
	printf("\t:::CUARTA SEMANA:::\n");
	printf("Producto A: %d\n",tempProducto[6][0]+tempProducto[6][1]+tempProducto[6][2]);
	printf("Producto B: %d\n",tempProducto[7][0]+tempProducto[7][1]+tempProducto[7][2]);
}

void TercerPunto(int tempProducto[8][3]){
	printf("\n");
	printf("\t:::PRIMERA SEMANA:::\n");
	printf("Producto A: %d\n",(tempProducto[0][0]+tempProducto[0][1]+tempProducto[0][2])*150);
	printf("Producto B: %d\n\n",(tempProducto[1][0]+tempProducto[1][1]+tempProducto[1][2])*90);
	
	printf("\t:::SEGUNDA SEMANA:::\n");
	printf("Producto A: %d\n",(tempProducto[2][0]+tempProducto[2][1]+tempProducto[2][2])*150);
	printf("Producto B: %d\n\n",(tempProducto[3][0]+tempProducto[3][1]+tempProducto[3][2])*90);
	
	printf("\t:::TERCERA SEMANA:::\n");
	printf("Producto A: %d\n",(tempProducto[4][0]+tempProducto[4][1]+tempProducto[4][2])*150);
	printf("Producto B: %d\n\n",(tempProducto[5][0]+tempProducto[5][1]+tempProducto[5][2])*90);
	
	printf("\t:::CUARTA SEMANA:::\n");
	printf("Producto A: %d\n",(tempProducto[6][0]+tempProducto[6][1]+tempProducto[6][2])*150);
	printf("Producto B: %d\n",(tempProducto[7][0]+tempProducto[7][1]+tempProducto[7][2])*90);
}

void CuartoPunto(int tempProducto[8][3]){
	
	int ValorProductos[2] = {0,0};// crear variable para guaradar cantidad productos
	
	for(int columnas=0;columnas<3;columnas++){
		for(int filas=0;filas<7;filas+=2){
			ValorProductos[0] = ValorProductos[0] + tempProducto[filas][columnas];//sumar productos a
		}
		
	}
	
	for(int columnas=0;columnas<3;columnas++){
		for(int filas=1;filas<8;filas+=2){
			ValorProductos[1] = ValorProductos[1] + tempProducto[filas][columnas];//sumar productos b
		}
		
	}
	
	/*int ValorProductoA = 	tempProducto[0][0]+tempProducto[0][1]+tempProducto[0][2]+
							tempProducto[2][0]+tempProducto[2][1]+tempProducto[2][2]+
							tempProducto[4][0]+tempProducto[4][1]+tempProducto[4][2]+
							tempProducto[6][0]+tempProducto[6][1]+tempProducto[6][2];
							
	int ValorProductoB = 	tempProducto[1][0]+tempProducto[1][1]+tempProducto[1][2]+
							tempProducto[3][0]+tempProducto[3][1]+tempProducto[3][2]+
							tempProducto[5][0]+tempProducto[5][1]+tempProducto[5][2]+
							tempProducto[7][0]+tempProducto[7][1]+tempProducto[7][2];*/
	
	printf("\n");						
	printf("Producto A: %d\n",ValorProductos[0]*150);//mostrar valor de los productos a
	printf("Producto B: %d\n",ValorProductos[1]*90);//mostrar valor de los productos b
}

void QuintoPunto(int tempProducto[8][3]){
	printf("\n");
	printf("\t:::PRIMERA SEMANA:::\n");
	printf("Producto A: Juan %f -- Maria %f -- Luis %f\n",tempProducto[0][0]*150*0.09,tempProducto[0][1]*150*0.09,tempProducto[0][2]*150*0.09);
	printf("Producto B: Juan %f -- Maria %f -- Luis %f\n\n",tempProducto[1][0]*90*0.06,tempProducto[1][1]*90*0.06,tempProducto[1][2]*90*0.06);
	
	printf("\t:::SEGUNDA SEMANA:::\n");
	printf("Producto A: Juan %f -- Maria %f -- Luis %f\n",tempProducto[2][0]*150*0.09,tempProducto[2][1]*150*0.09,tempProducto[2][2]*150*0.09);
	printf("Producto B: Juan %f -- Maria %f -- Luis %f\n\n",tempProducto[3][0]*90*0.06,tempProducto[3][1]*90*0.06,tempProducto[3][2]*90*0.06);
	
	printf("\t:::TERCERA SEMANA:::\n");
	printf("Producto A: Juan %f -- Maria %f -- Luis %f\n",tempProducto[4][0]*150*0.09,tempProducto[4][1]*150*0.09,tempProducto[4][2]*150*0.09);
	printf("Producto B: Juan %f -- Maria %f -- Luis %f\n\n",tempProducto[5][0]*90*0.06,tempProducto[5][1]*90*0.06,tempProducto[5][2]*90*0.06);
	
	printf("\t:::CUARTA SEMANA:::\n");
	printf("Producto A: Juan %f -- Maria %f -- Luis %f\n",tempProducto[6][0]*150*0.09,tempProducto[6][1]*150*0.09,tempProducto[6][2]*150*0.09);
	printf("Producto B: Juan %f -- Maria %f -- Luis %f\n",tempProducto[7][0]*90*0.06,tempProducto[7][1]*90*0.06,tempProducto[7][2]*90*0.06);
}

void SextoPunto(int tempProducto[8][3]){
	
	float Vendedor[3] = {0,0,0};// crear arreglo para cada vendedor
	int cont = 0;
	
	for(int columnas=0;columnas<3;columnas++){
		for(int filas=0;filas<8;filas++){
			if(filas%2==0){
				Vendedor[cont] = Vendedor[cont] + (tempProducto[filas][columnas]*150*0.09);//guardando las comisiomes de a
			}
			else{
				Vendedor[cont] = Vendedor[cont] + (tempProducto[filas][columnas]*90*0.06);//guardando las comisiones de b
			}
		}
		cont ++;//Indicar a que vendedor va esa comisión
	}
	
	/*float Juan =  tempProducto[0][0]*150*0.09+tempProducto[1][0]*90*0.06+
					tempProducto[2][0]*150*0.09+tempProducto[3][0]*90*0.06+
					tempProducto[4][0]*150*0.09+tempProducto[5][0]*90*0.06+
					tempProducto[6][0]*150*0.09+tempProducto[7][0]*90*0.06;
				
	float Maria = 	tempProducto[0][1]*150*0.09+tempProducto[1][1]*90*0.06+
					tempProducto[2][1]*150*0.09+tempProducto[3][1]*90*0.06+
					tempProducto[4][1]*150*0.09+tempProducto[5][1]*90*0.06+
					tempProducto[6][1]*150*0.09+tempProducto[7][1]*90*0.06;
				
	float Luis  = 	tempProducto[0][2]*150*0.09+tempProducto[1][2]*90*0.06+
					tempProducto[2][2]*150*0.09+tempProducto[3][2]*90*0.06+
					tempProducto[4][2]*150*0.09+tempProducto[5][2]*90*0.06+
					tempProducto[6][2]*150*0.09+tempProducto[7][2]*90*0.06;*/
				
	printf("Juan:  %f\n",Vendedor[0]);
	printf("Maria: %f\n",Vendedor[1]);
	printf("Luis:  %f\n",Vendedor[2]);
}

void SeptimoPunto(int tempProducto[8][3]){
	
	//Comision Producto A
	float ProductoA = 0;
	
	for(int col=0;col<3;col++){
		for(int fila=0;fila<7;fila+=2){
			ProductoA = ProductoA + tempProducto[fila][col];//suma total del producto A en cantidad
		}
	}
	
	float ComisionA = ProductoA * 150 * 0.09;//comision por el producto A
	
	//Comision Producto B
	float ProductoB = 0;
	
	for(int col=0;col<3;col++){
		for(int fila=1;fila<8;fila+=2){
			ProductoB = ProductoB + tempProducto[fila][col];//suma total producto B
		}
	}
	
	float ComisionB = ProductoB * 90 * 0.06;//comision producto b
	
				
	printf("\nComisiones mes de Marzo:  %f\n",ComisionA+ComisionB);//mostrar comision total
}

void OctavoPunto(int tempProducto[8][3]){
	
	
	int Semanas[4]={0,0,0,0};//cantidad productos A vendidos por semana
	int cont = 0;//indicar la semana
	
	for(int fila=0;fila<8;fila+=2){
		for(int columna=0;columna<3;columna++){
			Semanas[cont] = Semanas[cont] + tempProducto[fila][columna];//sumar productos por semana 
		}
		cont = cont+1;
	}
	
	int Temp = 0;//variable temporal que nos va indicar cual esla cantidad mayor de la semana que se vendio
	int tempSemana = 0;//salida, indicar cual es esa semana
	
	for(int i = 0; i<4; i++){
		if (Semanas[i]>Temp){
			Temp = Semanas[i];//guarda el mayor valor
			tempSemana = i;//guarda la semana con mayor valor
		}
	}
	
	printf("\nLa Semana %d se vendio MAS Unidades del Producto A",tempSemana+1);//muestra la semana

}

void NovenoPunto(int tempProducto[8][3]){
	
	int Semanas[4]={0,0,0,0};
	int cont = 0;
	
	for(int fila=1;fila<8;fila+=2){
		for(int columna=0;columna<3;columna++){
			Semanas[cont] = Semanas[cont] + tempProducto[fila][columna];//suma unidades del producto b
		}
		cont = cont+1;
	}
	
	
	int Temp = 9999999;//Indicar menor unidadses
	int tempSemana = 0;//semana esta ese menor unidades
	
	for(int ii = 0; ii<4; ii++){
		if (Semanas[ii]<Temp){
			Temp = Semanas[ii];//guarda la cantidad menor
			tempSemana = ii;//guarda la semana que tiene la menor cantidad
		}
	}
	
	printf("\nLa Semana %d se vendio MENOS Unidades del Producto B",tempSemana+1);//muestra la cantidad

}

void DecimoPunto(int tempProducto[8][3]){
	int valorProducto[8][3];//entrada
	int _temp = 0;//entrada
	int _posi = 0;//salida
	int _posj = 0;//entrada
	for(int i=0;i<8;i++){
		for(int j=0;j<3;j++){
			if(i%2==0){
				valorProducto[i][j] = tempProducto[i][j]*150;//dar valor a cada producto A que se vendio
			}
			else{
				valorProducto[i][j] = tempProducto[i][j]*90;//dar valor a cada producto B que se vendio
			}
		}
	}
	
	for(int i=0;i<8;i++){
		for(int j=0;j<3;j++){
			if(valorProducto[i][j]>_temp){
				_temp = valorProducto[i][j];//Identificar cual es el producto vale
				_posi = i;//(i/2)+1->semana,producto//semana
				_posj = j;//columna Nombre//nombre
			}
		}
	}
	
	if(_posj==0){
		printf("\nNombre: Juan");//si se cumple muestra el vendedor
	}
	else if(_posj==1){
		printf("\nNombre: Maria");
	}
	else{
		printf("\nNombre: Luis");
	}
	printf("\nSemana: %d",(_posi/2)+1);//numero de la semana en que mas se vendio
	if(_posi%2==0){
		printf("\nProducto: A");
	}
	else{
		printf("\nProducto: B");
	}
};

int main(int argc, char** argv) {
	int cantidadProducto[8][3] = {{50,30,45},{60,50,40},{20,35,25},{40,50,45},{30,18,15},{10,15,20},{25,35,15},{18,21,20}};
	int opcion =  0;
	do{
		Menu();
		scanf("%d",&opcion);
		switch(opcion){
			case 1:
				PrimerPunto(cantidadProducto);
				printf("\n");
				break;
			case 2:
				SegundoPunto(cantidadProducto);
				printf("\n");
				break;
			case 3:
				TercerPunto(cantidadProducto);
				printf("\n");
				break;
			case 4:
				CuartoPunto(cantidadProducto);
				printf("\n");
				break;
			case 5:
				QuintoPunto(cantidadProducto);
				printf("\n");
				break;
			case 6:
				SextoPunto(cantidadProducto);
				printf("\n");
				break;
			case 7:
				SeptimoPunto(cantidadProducto);
				printf("\n");
				break;
			case 8:
				OctavoPunto(cantidadProducto);
				printf("\n");
				break;
			case 9:
				NovenoPunto(cantidadProducto);
				printf("\n");
				break;
			case 10:
				DecimoPunto(cantidadProducto);
				printf("\n");
				break;	
			case 11:
				break;
			default:printf("Se equivoco de opcion de Menu\n");
		}
		printf("\n");
		system("pause");
		system("cls");
	}while(opcion != 11);
	
	return 0;
}
