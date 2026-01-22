#include <iostream>
using namespace std;

int main() {
    int *ptr = new int;

    cout << "plz enter number prooo \n";
    cin >> *ptr;
    cin >> ptr[0];

    cout << "way 1 = "<< *ptr << endl;
    cout << "way 2 = " << ptr[0] << endl;

    delete ptr;
}
