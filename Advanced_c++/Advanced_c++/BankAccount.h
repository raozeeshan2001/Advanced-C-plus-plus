#pragma once
#include <mutex>
#include <thread>

class BankAccount {
public:
    BankAccount(int initialBalance);

    std::mutex mtx;
    int balance;
};

void transfer(BankAccount& from, BankAccount& to, int amount);
