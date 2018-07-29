#include <iostream>

using namespace std;

void sayHi()
{
    cout << "Hi" << endl;
}

int summation(int a, int b) {
    return a+b;
}

int main()
{
    cout << "Simple function" << endl;
    sayHi();
    sayHi();

    cout << endl;
    cout << "Function send 2 int and return the sum of the 2 numbers" << endl;
    cout << summation(5,4) << endl;
    int a = 3;
    int b = 2;
    int c = summation(a,b);
    cout << "a " << a << " plus b " << b << " equals " << c << endl;
    cout << "Sum float -> summation(3.2f, 3.1f " << summation(3.2f, 3.1f) << ")" << endl;
    cout << "Sum double -> summation(3.2, 3.1 " << summation(3.2, 3.1) << ")" << endl;
    cout << "End!" << endl;
    return 0;
}
