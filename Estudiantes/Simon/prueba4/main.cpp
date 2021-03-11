#include <windows.h>
#include <GL/glut.h>  // GLUT, includes glu.h and gl.h

#include <math.h>

float radio=10;
float calx;//Posicion en x
float caly;//Posicion en y


void inicio()
{
    glMatrixMode(GL_PROJECTION);//sirve para el uso de la pantalla
    gluOrtho2D(-100,100,-100,100);//2 primeros inicio y fin de las x y la segunda inicio de la y y fin
    glClearColor(0.0,0.0,1.0,0.0);//Colores RGB
}

void pantalla()
{
    glClear(GL_COLOR_BUFFER_BIT);
	//inserte su codigo aqui
	
	glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
		for(float i=0; i<10; i+=0.01){
		calx = radio * cos(i);
		caly = radio * sin(i);
		glVertex2f(calx,caly);// Para movelor hacia la izquierda calx-10
		}
	glEnd();
	
	
    glFlush();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);//inicializa las funciones de GLUT
    glutInitWindowSize(500,500);//ancho y largo de la pantalla
    glutInitWindowPosition(100,100);//Posicioin de la ventana
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutCreateWindow("Sesgado");
    inicio();
    glutDisplayFunc(pantalla);

    glutMainLoop();//se repite y no se cierra

    return EXIT_SUCCESS;
}
