#include "lista.h"

lista::lista()
{
 setPrimerptr(0);
 setUltimoptr(0);
}

lista::~lista()
{
	;
}



void lista::setPrimerptr(nodo *pr){
	Primerptr=pr;
	
}
void lista::setUltimoptr(nodo *ult){
	Ultimoptr=ult;
	
}
nodo *lista::getPrimerptr(){
	return Primerptr;
	
}
nodo *lista::getUltimoptr(){
	 return Ultimoptr;
	
	
}

void lista::Imprimir(){
	
	cout<<"PrimerPtr "<<getPrimerptr()<<endl;
	cout<<"UltimoPtr "<<getUltimoptr()<<endl;
	system("pause");
	
}
void lista::InsertarInicio(nodo *x){
	nodo *tem=new nodo();
	tem=x;
	if(getPrimerptr()==0){
		Primerptr=tem;
		Ultimoptr=tem;
	}else{
		Primerptr->setSiguienteptr(tem);
		Primerptr=tem;
	}	
}
void lista::Mostrar(){
	nodo *aux=Ultimoptr;
	cout<<"\tMostrar"<<endl;
	while(aux!=0){
		aux->Imprimir();
		aux=aux->getSiguienteptr();
	}
	system("pause");
}
void lista:: InsertarFinal(nodo *y){
	nodo *tem=new nodo();
	tem=y;
	if(getPrimerptr()==0){
		setPrimerptr(tem);
		setUltimoptr(tem);
	}else{
		tem->setSiguienteptr(Ultimoptr);
		Ultimoptr=tem;
	}
	
	
}
void lista::EliminarInicio(nodo *xy){
	/*nodo *tem=new nodo();
	tem=xy;
	if(getPrimerptr()!=0){
		setPrimerptr(0);
		Primerptr->setSiguienteptr(tem);
	}*/
	
}
void lista::EliminarFinal(nodo *xy){
	
	
}
// Guardar ofstream () getnombre getprecio

