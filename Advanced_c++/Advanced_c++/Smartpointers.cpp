#include "Smartpointers.h"

#include <memory>
#include "iostream"

using namespace std;

class Book {
private:
    string bookname;
    int price;
public:
    void SetData(string b, int p) {

        bookname = b;
        price = p;
    }

    void ShowData() {

        cout << "book name is : " << bookname << endl;
        cout << "price is : " << price << endl;
    }

};
class Student {

private:
    string name;
    int marks;
public:
    void SetData(string n, int m) {

        name = n;
        marks = m;
    }

    void ShowData() {

        cout << "name is : " << name << endl;
        cout << "marks are : " << marks << endl;
    }
};


void Smartpointers::UniquePtr() {


    unique_ptr<Student> uni_ptr = make_unique<Student>();
    uni_ptr->SetData("rao",25);
    uni_ptr->ShowData();
    unique_ptr<Student> uni_ptr2 = move(uni_ptr);
    uni_ptr2->ShowData();
    if (uni_ptr == nullptr) {
        cout << "ptr 1 is null"<<endl;
    }
}

void Smartpointers::SharedPtr() {

    //shared ptr

    shared_ptr<Book> shptr = make_shared<Book>();
    shptr->SetData("theorybook", 100);
    shptr->ShowData();
    cout << "use count before copy : " << shptr.use_count() << endl;
    shared_ptr<Book>shptr2 = shptr;
    cout << "use count after copy : " << shptr.use_count() << endl;
    cout << "use count after copy : " << shptr2.use_count() << endl;
}


