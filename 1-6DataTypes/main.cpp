#include <iostream>
#include <string>

using namespace std;

int main()
{
    string hello = "Hello World";
    int count = 7;

    cout << "The message is " << hello << endl;
    cout << "The count is " << count << endl;

    cout << "size of int " << sizeof(int) << endl;
    cout << "size of hello " << sizeof(hello) << endl;

    cout<<""<<endl;

    cout << "size of int " << sizeof(int) << " bytes" << endl;
    cout << "size of char " << sizeof(char) << " bytes" << endl;
    cout << "size of boolean " << sizeof(bool) << " bytes" << endl;
    cout << "size of float " << sizeof(float) << " bytes" << endl;
    cout << "size of double " << sizeof(double) << " bytes" << endl;
    cout << "size of wchar_t " << sizeof(wchar_t) << " bytes" << endl;


    unsigned int var1= 200;
    cout << "var1 is " << var1 << endl;  // returns 200
    var1 *= -1;
    cout << "var1 is " << var1 << endl;  // returns 4294967096

    return 0;
}
