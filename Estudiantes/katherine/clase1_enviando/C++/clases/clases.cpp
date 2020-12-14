#include <iostream>
#include <string>

//using namespace std;

class Book{
   private:
      
   public:
      int id;
      int qty;
      std::string title;
      std::string author;
      
      Book(int _id, int _qty, std::string _title, std::string _author){
         id = _id;
         qty = _qty;
         title = _title;
         author = _author;
      }
};

void restar_libro(Book *book)//funcion a la que se le envia un libro que no devuelve nada
{
    book->qty--;// la flecha dice desapuntar el book e ir al elemento
}

int main(int argc, char **argv) {
   Book *book1;//APUNTADOR A LA DIRECCIÓN DONDE QUEDO CREADO BOOK1
   
   book1 = new Book(1, 10, "Programación en C", "Camilo Camacho");//LO CREA Y DEVUELVE LA DIRECCIÓN

   std::cout << "book1->id = " << book1->id << std::endl;
   std::cout << "book1->qty = " << book1->qty << std::endl;
   std::cout << "book1->title = " << book1->title << std::endl;
   std::cout << "book1->author = " << book1->author << std::endl;

    restar_libro(book1);

    std::cout << "book1->id = " << book1->id << std::endl;
   std::cout << "book1->qty = " << book1->qty << std::endl;
   std::cout << "book1->title = " << book1->title << std::endl;
   std::cout << "book1->author = " << book1->author << std::endl;

   return 0;
}

//cuando se usa punto es decir acceda al elemento de  la estructura
// flecha va al apuntador que apunta a la estructura y busca el elemento que queremos 
//