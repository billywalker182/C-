#include <iostream>
#include <string.h>
#include <cstdlib>
#include "Ficha.h"

using namespace std;

bool Ficha::FichaExiste(){
	bool banderax = false;
	bool banderay = false;
	string x = "ABCDEF";
	string y = "123456";
	
	for(int i=0;i<6;i++){
		if(ficha[0]==x[i]){
			banderax = true;
		}
		if(ficha[1]==y[i]){
			banderay = true;
		}
	}
	
	if(banderax && banderay){
		return true;
	}
	else{
		return false;
	}
}
