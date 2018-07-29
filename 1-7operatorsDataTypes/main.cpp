#include <iostream>

using namespace std;

int main()
{
    int a = 20;
    int b = 7;
    cout << "---------------------------math operators-----------------------" << endl;
    cout << "a + b " << a + b << endl;
    cout << "a - b " << a - b << endl;
    cout << "a * b " << a * b << endl;
    cout << "a / b " << a / b << endl;  // returns 2, int doesn't have decimals
    cout << "a + b " << (float) a / b << endl;  // returns 2.85714
    cout << "a % b " << a % b << endl;  // returns 6

    cout << "" << endl;
    cout << "---------------------------logical operators-----------------------" << endl;
    if (a > b) {
        cout << "a is greater than b" << endl;
    } else
    {
        cout << " a is not greater than b" << endl;
    }

    string aa = "a";
    string bb = "b";
    if(aa == bb) {
        cout << "a == b" << endl;
    } else {
        cout << "a not == b" << endl;
    }

    cout << "" << endl;
    cout << "---------------------------loop---------" << endl;
    for (int i=1; i<11; i++)  {
        cout << "This is line " << i << " in the loop" << endl;
    }
    cout << "" << endl;
    int j = 1;
    while (j < 5) {
        cout << " while j " << j << endl;
        j++;
    }

    cout << "" << endl;
    int k = 1;
    do {
        cout << "do while k " << k << endl;
        k++;
    } while (k<6);

    return 0;
}
