

#include <iostream>
#include <string>
#include <memory>
#include "Smartpointers.h"
#include "Booksuni.h"
#include "BankAccount.h"
#include "multi_threading.h"
#include <thread>
#include <mutex>

using namespace std;
//std::mutex mtx;


//class BankAccount
//{
//public:
//    BankAccount(int initialBalance) : balance(initialBalance) {}
//
//    std::mutex mtx;
//    int balance;
//
//   
//};




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
 
   /* mt.threadcallingfunction();
    mt.mutexcallingfunction();*/
    ///////////////////////////deadlock prevention
    /*BankAccount accountA(1000);
    BankAccount accountB(1000);
    std::thread t1(transfer, std::ref(accountA), std::ref(accountB), 100);
    std::thread t2(transfer, std::ref(accountB), std::ref(accountA), 50);
    t1.join();
    t2.join();

    std::cout << "A: " << accountA.balance << "\n";
    std::cout << "B: " << accountB.balance << "\n";*/
    //////////////////////////////////////////////
    mt.calling_alarm_sleeper();

    return 0;

}
 