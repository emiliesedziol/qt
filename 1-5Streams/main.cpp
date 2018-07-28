#include <iostream>
#include <string>

//using namespace std;  - remove and std::   can be used on the lines referring to the library

int main()
{
    std::cout << "Hello World!" << std::endl;  // std:: indicates from std library

    //2.cerr
    std::cerr << " There was an error" << std::endl;

    //3.log
    std::clog << "This is a log message" << std::endl;

    //4.cin
    std::string name;

    std::cout << "Please enter a name: ";
    std::cin >> name;
    std::cout << "The name is " << name << std::endl;




    return 0;
}
