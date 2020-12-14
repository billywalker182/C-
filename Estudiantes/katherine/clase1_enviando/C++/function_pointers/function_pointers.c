#include <stdio.h>
#include <stdlib.h>

struct Complex{
     double real = 0.0
     double imag = 0.0
}
const int *px;//posicion de memoria q apunta pero no puedo modificar lo q tenga a lo que estoy apuntando
int const *x;//

int compare1(const Complex* a, const Complex* b)//las variables se vueelven de solo lectura
{
    return (a->real > b->real)

}

)

int main(int argc, int argv){

    Complex x1;
    ={1.2, 0.7};//1.2+0.7j
    Complex x1={0.5,7.1}

    if(compare1(&x1, &x2))





    return 0;
}