#include<iostream>
#include"glut.h"
#include"stdio.h"
#include"stdlib.h"
#include<math.h>
#include <ctime>
using namespace std;
int screenWidth = 840;
int screenHeight = 680;
float n;
void setpixel(GLint x, GLint y)
{
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();

}
struct punto
{
	float x, y;
};
void dibujar_triangulo(punto, punto);
void dibujar_sierpinski(punto a, punto b, punto c, size_t n)
{
	punto ab, bc, ca;
	if (n == 0){
		dibujar_triangulo(a, b);
	dibujar_triangulo(a, c);
	dibujar_triangulo(b, c);}
	else
	{
		ab.x = (a.x + b.x) / 2; ab.y = (a.y + b.y) / 2; // Mitad ab
		bc.x = (b.x + c.x) / 2; bc.y = (b.y + c.y) / 2; // Mitad bc
		ca.x = (c.x + a.x) / 2; ca.y = (c.y + a.y) / 2; // Mitad ca
		dibujar_sierpinski(a, ab, ca, n - 1);
		dibujar_sierpinski(ab, b, bc, n - 1);
	dibujar_sierpinski(ca, bc, c, n - 1);
	}
}
void dibujar_triangulo(punto a, punto b)
{
	glBegin(GL_POINTS);
	GLint i;
	float x, y, ax, ay, delta;
	if (abs(b.x - a.x) >= abs(b.y - a.y)) {
		delta = abs(b.x - a.x);
	}
	else {
		delta = abs(b.y - a.y);
	}
	ax = (b.x - a.x) / delta;
	ay = (b.y - a.y) / delta;
	i = 1;
	x = (float)a.x;
	y = (float)a.y;
	while (i <= delta) {
		setpixel(roundf(x), roundf(y));
		x = x + ax;
		y = y + ay;
		i++;
	}
}
void myDisplay(void)
{
	punto a, b, c;
	a.x = 400; a.y = 700;
	b.x = 700; b.y =100;
	c.x = 100; c.y = 100;
	dibujar_sierpinski(a, b, c, n);
	glFlush();
}

void ingresodedatos(void)
{
	cout << "***PARCIAL DE PROGRAMACION:TRIANGULO DE SIERPINSKI***"<<endl;
	cout << "Ingrese el numero de iteraciones"<<endl;
	cout << "recuerde que el numero debe ser entero y positivo" << endl;
	char dato[10];
	do {
		cin >> dato;
		n = atoi(dato);
		cout << "dato incorrecto, vuelva a ingresar el numero: ";
		
	} while ((n < 1) || (n - (int)n > 0)&&n>=0 || n==0);
	cout << "El numero digitado es " << (int)n;
}
int main(int argc, char** argv)
{
	ingresodedatos();
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(30, 30);
	glutInit(&argc, argv);
	glutCreateWindow("Triángulo de Sierpinski");	
	glutDisplayFunc(myDisplay);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 840.0, 0.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, 840, 1000);
	glutMainLoop();
}//cierra el main
