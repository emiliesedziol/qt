#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    int guessNumber;
    int randomNumber;

    srand(time(NULL));
    randomNumber = rand() % 10 + 1;

    bool correct = false;

    while (correct==false) {
        cout << "Enter a number between 1 - 10 ";
        cin >> guessNumber;
        cout << endl;
        if (guessNumber!=randomNumber){
            cout << "quess is not correct, try again" << endl;
        } else {
            cout << "Guess is correct" << endl;
            correct = true;
        }
    }

    cout << "End!" << endl;
    return 0;
}
