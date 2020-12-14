
/**
 * Main program - Adapted to C++
 * @author Helmuth Trefftz
 * @author Jose Luis Montoya
 */

#include <string>
#include "parser.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc > 1) {
    string strNombreArchivo = argv[1];// toma de argumnetos or send parameters 
    Parser parser1(strNombreArchivo);
    parser1.program();
    
  }
// Crea un objeto en el heap --- Se REQUIERE INVOCAR el destructor para evitar memory leaks
//    Parser* parser = new Parser(strNombreArchivo);
// Call the method associated with the starting symbol of the grammar
// Como el objeto se creo como puntero en el heap (el famoso *), se debe acceder a los atributos mediante la ->
//    parser->program();
// Hace lo mismo que la linea anterior
//    (*parser).program();
//	delete parser;
// Crear el objeto localmente (en el stack). Cuando se crea así, se auto destruye cuando se deja el alcance (scope) actual 
// Como el objeto se creó local en el stack, se accede a los métodos (y atributos, si hubiera acceso directo) mediante .
	
	return 0;
}
