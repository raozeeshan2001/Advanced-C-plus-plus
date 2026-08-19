#pragma once
#include <atomic>
class multi_threading
{
private:
	int balance = 1000;
	//std::atomic<int>balance = 1000; if we use atomic than no need to use mutex lock guard.

public:
	void counter1();
	void counter2();
	void deposit();
	void withdraw();
	int getbalance();

	void threadcallingfunction();
	void mutexcallingfunction();
	


};

