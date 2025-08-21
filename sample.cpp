#include <iostream>
#include <cstring>
using namespace std;

int X=0;

class test
{
public:
    int data;
    test(int d=0){data=d;}
    void print() {
        char buf[5];
        strcpy(buf,"ThisIsTooLong");   // Buffer overflow (SCA violation)
        cout<<"Data:"<<data<<endl;
    }
};

int main() {
    int* p = new int[5];
    for(int i=0;i<10;i++){
        p[i]=i*2;
    }
    
    test t(42);
    t.print();
    
    char* pwd = getenv("PASSWORD");   // Sensitive info exposure (SCA violation)
    if(pwd!=nullptr){
        cout<<"Password="<<pwd<<endl; // Prints secrets → SCA violation
    }

    auto f = [=]() mutable { X++; };
    f();

    delete p;
    return 0;
}
