/*Create a program that generates a random number and asks the
user to guess it. Provide feedback on whether the guess is too
high or too low until the user guesses the correct number.*/

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
    int start, end, number, Guess_number;

    srand(time(0));

    cout << "\n\n\t//-------NUMBER GUESSING-------//\n";
    cout << "\n\n//-------ENTER THE RANGE OF NUMBERS--------//\n";
    cout << "\nEnter the starting point: ";
    cin >> start;
    cout << "Enter the ending point: ";
    cin >> end;

    Guess_number = start + rand() % (end - start + 1);

    cout << "\nGuess a number: ";
    cin >> number;

    while (1)
    {
        if (number < Guess_number)
        {
            cout << "\nYour guess is LOW!!\n\tTry to guess again: ";
            cin >> number;
        }
        else if (number > Guess_number)
        {
            cout << "\nYour guess is HIGH!!\n\tTry to guess again: ";
            cin >> number;
        }
        else
        {
            cout << "\n\nCONGRATS!! You guessed the correct number\n\n";
            break;
        }
    }

    return 0;
}

//codsoft