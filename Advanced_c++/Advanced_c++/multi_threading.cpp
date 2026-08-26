#include "multi_threading.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

bool alarmrang = false;
std::mutex mutex3;
std::condition_variable cw;
std::mutex mtx;

 void multi_threading::counter1() {
     
    
         for (int i = 1;i <= 5;i++) {
            cout << "thread 1: " << i << endl;
         }
     
     
}

 void multi_threading::counter2() {
     
         for (int i = 1;i <= 5;i++) {
             cout << "thread 2: " << i << endl;
         }
     

 }
 void multi_threading::deposit() {
     for (int i = 0; i < 100000; i++)
     {
         //simple mutex
         std::lock_guard<std::mutex> lock(mtx);
         balance++;


     }
 }
 void multi_threading::withdraw() {

     for (int i = 0; i < 100000; i++)
     {
         //simple mutex
        std::lock_guard<std::mutex> lock(mtx);
         balance--;


     }
 }
 int multi_threading::getbalance() {
     std::lock_guard<std::mutex> lock(mtx);
     return balance;
 }
 void alarm() {
     //cw
     std::this_thread::sleep_for(std::chrono::seconds(2));
     {
         std::lock_guard<std::mutex>lock(mutex3);
         alarmrang = true;
         std::cout << "alarm! ring rang!.." << std::endl;
     }
     cw.notify_one();
 }
 void sleeper() {
     // cw problem
     std::unique_lock<std::mutex>lock(mutex3);
     std::cout << "sleeper going to sleep" << std::endl;
     cw.wait(lock, [] {return alarmrang;});
     std::cout << "Woke up! Time to go to work." << std::endl;
 }

 void multi_threading::threadcallingfunction() {

     std::thread t1(&multi_threading::counter1,this);
     std::thread t2(&multi_threading::counter2, this);
     t1.join();
     t2.join();
     cout << "both threads finished" << endl;
 }
 void multi_threading::mutexcallingfunction() {

     thread t1(&multi_threading::deposit,this);
     thread t2(&multi_threading::withdraw,this);
     t1.join();
     t2.join();
     cout << "final balance is: " <<getbalance();
 }
 
 void multi_threading::calling_alarm_sleeper() {

     std::thread t1(alarm);
     std::thread t2(sleeper);
     t1.join();
     t2.join();
 }