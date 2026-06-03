#pragma once


#include "iostream"
#include "string"

using namespace std;// move semantics copy and move constructors
class Booksuni
{
public:
	string* title;

	Booksuni() {
		title = nullptr;
		cout << "default constructor called"<<endl;
	}

	Booksuni(string t) {//normal constructor

		title = new string (t);
		cout << "normal constructor called" << endl;
	}
	Booksuni(const Booksuni & other) {//copy constructor
		title = new string(*other.title);
		cout << "copy constructor called" << endl;

	}
	Booksuni( Booksuni&& other) {//move constructor
		title = other.title;
		other.title = nullptr;
		cout << "move constructor called" << endl;

	}
	Booksuni&operator=(Booksuni&other){//copy assignment operator//for existing object copy
	
		if (this == &other)
			return *this;
		delete title;  // remove old memory

		title = new string (*other.title); // steal pointer
	

		cout << "copy Assignment Operator called" << endl;

		return *this;
	}
	Booksuni& operator=(Booksuni&& other) {//move ass operator//for existing object move

		if (this == &other)
			return *this;
		delete title;  // remove old memory

		title = other.title; // steal pointer
		other.title = nullptr;

		cout << "Move Assignment Operator called" << endl;

	     return *this;
	}

	~Booksuni() {//destructor
		delete title;
		cout << "desctructor called" << endl;
	}
	

};

