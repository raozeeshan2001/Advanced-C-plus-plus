

#include <iostream>
#include <string>
#include <memory>
#include "Smartpointers.h"
#include "Booksuni.h"

using namespace std;




int main()
{
    Smartpointers obj;  
    /*obj.UniquePtr();
    obj.SharedPtr();
   */
    Booksuni book1("english");
    Booksuni book2 = book1;
    Booksuni book3 = std::move(book1);
    book3 = book2;
    book3 = std::move(book2);
 
   
    
 
    

}
 