#include <iostream>
using namespace std;


class Operacion {

    private://atributos
        
        int num1, num2;
    
    public://metodos
        Operacion(){
        //constructor por defecto
    }
    
    Operacion(int num1 , int num2){
         this ->num1 = num1;//this llamando a atributo
          this -> num2 = num2;
    }

    int suma(int num1, int num2);
    int resta(int num1, int num2);
    int multiplicacion(int num1, int num2);
    int division(int num1, int num2);

};