#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int counter = 0;

#define SIZE 4

class Bad {
public:
    Bad(int v = 0) { val = v; }
    virtual void foo() { cout << "foo\n"; }
private:
    int val;
};

int main() {
    char buf[SIZE];
    strcpy(buf, "overflow");

    int* arr = new int[3];
    for (int i = 0; i <= 3; ++i) { arr[i] = i; }

    void* p = malloc(8);
    int* q = (int*)p;
    *q = 42;
    cout << *q << "\n";
    free(p);

    Bad* b = new Bad;
    b->foo();

    unsigned u = 1;
    int s = -1;
    if (u > s) { cout << "signed/unsigned\n"; }

    delete arr;
    return 0;
}
