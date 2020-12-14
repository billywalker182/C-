#include <iostream>
#include "Operacion.h"
using namespace std;

int main(int argc,char ** argv){

    Operacion *p1=new Operacion();
     int a ;
     int b;
    cout<<"numero 1"<<endl;
    cin>>a;
    cout<<"numero 2"<<endl;
    cin>>b;

       cout<<"la suma es "<<p1->suma(a ,b)<<endl;
         cout<<"la resta es "<<p1->resta(a ,b)<<endl;
          cout<<"la multiplicacion es "<<p1->multiplicacion(a ,b)<<endl;
           cout<<"la division es "<<p1->division(a ,b)<<endl;














    return 0;
}