

#include <iostream>
#include <string>
#include <memory>
#include "Smartpointers.h"
#include "Booksuni.h"
#include "multi_threading.h"
#include <thread>
#include <mutex>

using namespace std;
//std::mutex mtx;





int main()
{
   // Smartpointers obj;  
   // /*obj.UniquePtr();
   // obj.SharedPtr();
   //*/
   // Booksuni book1("english");
   // Booksuni book2 = book1;
   // Booksuni book3 = std::move(book1);
   // book3 = book2;
   // book3 = std::move(book2);
    multi_threading mt;

    
   
    mt.threadcallingfunction();
    mt.mutexcallingfunction();
    return 0;

}
 