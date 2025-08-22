#include <iostream>
using namespace std;
 
int main() {
 
    int a = 5;
    int b;
    int arr[5] = {1,2,3,4,5};
 
    int *ptr = arr;
 
    cout << ptr[10] << endl;
 
    if(a = 10) {
        cout << "Wrong comparison" << endl;
    }
 
    double x = 3.14;
    int y = (int)x;
 
    if(a == 42) {
        cout << "Magic!" << endl;
    }
 
    return 0;
}
 