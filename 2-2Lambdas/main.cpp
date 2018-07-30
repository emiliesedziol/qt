#include <iostream>

using namespace std;

int main()
{

    /*
     * [capture list] (parameter list) {function body}
     * [capture list] (parameter list) ->return_value_type {function body}
     * */
  //  name the function and call it
    cout << "name the lambda function and call it" << endl;
    auto func = [](){
        cout << "Hello World!" << endl;
    };

    func();
    cout << endl;
//    ---------------------------------------------------------------

    [](){
            cout << "Hello World!" << endl;
        }();  // <-- adding the () runs the function



    // lambda function that takes parameters

    cout << "lambda function that takes parameters" << endl;
    [](int a, int b) {
        cout << "a + b = " << a + b << endl;
    }(4,5);  // returns 9
    //

    cout << endl;
    //define a lambda that returns something
    cout << endl;
    cout << "define a lamdba function and return something" << endl;
    int sum =[](int a, int b)->int {
         return a + b;
    }(4,5);

    cout << "the sum " << sum << endl;


    cout << endl;
    cout << "use the lambda inside something" << endl;
    cout << "The sum is " << [](int a, int b)->int {
        return a + b;
   }(4,5)  <<endl;

    cout << endl;

    // capture lists
    cout << "capture lists" << endl;
    int a = 8;
    int b = 4;
    [a,b]()
    {
        cout << " a is " << a << endl;
        cout << "b is " << b << endl;
        cout << " sum of a + b " << a + b << endl;
    }();

    cout << endl;

    cout << "capturing by value" << endl;
    int c = 43;
    auto func1 = [c]() {
        cout << "the value of c in func is " << c << endl;
    };

    for (int i = 1; i < 5; i++)
    {
        cout << "inside the for loop c is " << c << endl;
        func1();
        c++;
    }

    cout << endl;

    cout << "capturing by reference " << endl;

    int d = 43;
    auto func2 = [&d]() {
        cout << "the value of d in func is " << d << endl;
    };

    for (int i = 1; i < 5; i++)
    {
        cout << "inside the for loop d is " << d << endl;
        func2();
        d++;
    }

    cout << endl;
    cout << " capture everything by value " << endl;
    int e = 43;
    int f = 2;
    auto func3 = [=]() {
        cout << "the value of d in func is " << e << endl;
        cout << "f " << f << endl;
    };

    for (int i = 1; i < 5; i++)
    {
        cout << "inside the for loop e is " << e << endl;
        func3();
        e++;
    }

    cout << endl;
    cout << "capture by reference" << endl;
    int g = 43;
    int h = 2;
    auto func4 = [&]() {
        cout << "the value of g in func is " << g << endl;
        cout << "h " << h << endl;
    };

    for (int i = 1; i < 5; i++)
    {
        cout << "inside the for loop g is " << g << endl;
        func4();
        g++;
    }

    cout << "End!" << endl;
    return 0;
}
