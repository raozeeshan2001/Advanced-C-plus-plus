#include "BankAccount.h"
#include <condition_variable>
#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>


// deadlock concept

BankAccount::BankAccount(int initialBalance) : balance(initialBalance) {}

void transfer(BankAccount& from, BankAccount& to, int amount) {
    //std::lock_guard<std::mutex>lock1(from.mtx); can cause deadlock
  // std::lock_guard<std::mutex>lock2(to.mtx);
    std::lock(from.mtx, to.mtx);//good way or use scoped_lock
    std::lock_guard<std::mutex> lock1(from.mtx, std::adopt_lock);
    std::lock_guard<std::mutex> lock2(to.mtx, std::adopt_lock);

    from.balance -= amount;
    to.balance += amount;
}
