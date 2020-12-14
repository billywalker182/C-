
/**
 * Main program - Adapted to C++
 * @author Helmuth Trefftz
 * @author Jose Luis Montoya
 */

#include <string>
#include <string.h>
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

bool simb_ln (string Datos[],int n){
	
	// WHILE ( 2 == 
	if(Datos[n] == "-" || Datos[n] == "+" || Datos[n] == "*" || Datos[n] == "/"){//EXPRESION 
		bool temp = false;
		std::string s;
		for(char num_let = 48;num_let<91;num_let++){
            s = num_let;
			if(Datos[n+1]==s){
				temp = true;
			}
		}
		if(temp){
			return true;
		}
		else{
			return false;
		}
	}
	return false;// == != 
}

void funWhile (string dato[],int longitud){
	
	// WHILE ( 
	
	if (dato[0]=="WHILE"){
		cout<<"\nEncontre un -> "<<dato[0]<<endl;
	}
	else{
		cout<<"\n\nError de Sintaxis -> :( "<<endl;
		exit(0);
	}
	if (dato[1]=="("){
		cout<<"Encontre un -> "<<dato[1]<<endl;
		//Lparen ++;
	}
	else{
		cout<<"\n\nError de Sintaxis -> :( "<<endl;
		exit(0);
	}
	
	/*if (dato[2]=="-"){
		cout<<"Encontrado -> "<<" - "<<endl;
		
		for (char num_letter = 48;num_letter<91;num_letter++){
			if(dato[3]==num_letter){
				cout<<"Encontre un -> "<<dato[3]<<endl;
			}
		}
	}*/
	
	for(int i = 2;i<longitud;i++){
		bool simbolo = true;
		bool tem = false;
		string s;
		
		if (dato[i]=="-"){
			cout<<"Encontre un -> "<<dato[i]<<endl;
			i++;// NEXT TOKEN
		}
		
		for(char num_let = 48;num_let<91;num_let++){
			 s= num_let;
			if(dato[i]==s){// DAT0[I] -> GET
				tem = true;
			}
		}
		if(tem){
			cout<<"Encontre un -> "<<dato[i]<<endl;
			i++;
		}
		else{
			cout<<"\n\nError de Sintaxis -> :( "<<endl;
			exit(0);
		}
		
		
		
		while(simbolo){
			
			// WHILE ( P == Z
			simbolo=simb_ln(dato,i);
			if(simbolo){// eXPRESION
				cout<<"Encontre un -> "<<dato[i]<<endl;
				i++;
				cout<<"Encontre un -> "<<dato[i]<<endl;
				i++;
			}
			else if (dato[i]=="==" || dato[i]=="!=" || dato[i]=="!"){
				simbolo = false;
			}
			else{
				cout<<"\n\nError de Sintaxis -> :( "<<endl;
				exit(0);
			}
		}
		if(dato[i]=="==" || dato[i]=="!=" || dato[i]=="!"){
			cout<<"Encontre un -> "<<dato[i]<<endl;
			i++;
		}
		
		
		if (dato[i]=="-"){
			cout<<"Encontre un -> "<<dato[i]<<endl;
			i++;
		}
		
		
		
		for(char num_let = 48;num_let<91;num_let++){
			 s= num_let;
			if(dato[i]==s){
				tem = true;
			}
		}
		if(tem){
			cout<<"Encontre un -> "<<dato[i]<<endl;
			i++;
		}
		else{
			cout<<"\n\nError de Sintaxis -> :( "<<endl;
			exit(0);
		}
		
		simbolo = true;
		
		while(simbolo){
			simbolo=simb_ln(dato,i);
			if(simbolo){
				cout<<"Encontre un -> "<<dato[i]<<endl;
				i++;
				cout<<"Encontre un -> "<<dato[i]<<endl;
				i++;
			}
			else if (dato[i]=="==" || dato[i]=="!=" || dato[i]=="!" || dato[i]==")" || dato[i]=="||" || dato[i]=="&&"){
				simbolo = false;
			}
			else{
				cout<<"\n\nError de Sintaxis -> :( "<<endl;
				exit(0);
			}
		}
		// WHILE ( 2 * 5 * 6 * 7 == - P || Z == Q )
		if(dato[i]=="&&"){
			cout<<"Encontre un -> "<<dato[i]<<endl;
			continue;
		}
		
		if(dato[i]=="||"){
			cout<<"Encontre un -> "<<dato[i]<<endl;
			continue;
		}
		
		if(dato[i]==")"){
			cout<<"Encontre un -> "<<dato[i]<<endl;
			cout <<"\n\tCompilado el WHILE -> :) "<<endl;
		}
		
	}
	
}

int main(int argc, char* argv[])

{
	string info[255];
	int contador=0;
	string Dato;
	
	while (true){
		cout <<"\nCompile su condicion While : "<<endl<<endl<<"\t";
		getline(cin,Dato);
		cout<<endl<<endl;
		string temp = "";
		for(int i = 0;i<Dato.length();i++){
			if(Dato[i]==' '){
				info [contador] = temp;
				contador++;
				temp = "";
			}
			else{
				temp += toupper(Dato[i]);
			}
		}
		info [contador] = temp;
	
	/*for(int i = 0;i<=contador;i++){
		cout<<info[i]<<" -> ";
	}*/
	
		funWhile(info,contador);
		contador = 0;
	}
	
	
	
	return 0;
}
