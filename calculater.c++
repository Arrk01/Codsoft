#include <iostream>
using namespace std;
int main()

{
    cout << "\n//-----------SIMPLE -----------//";
    cout << "\n//---------CALCULATOR-----------//\n";
    int First_number, Second_number, choice;
    int Addition, Subtraction, Multiplication, Division;

    do
    {
        cout << "\n\nEnter First number:";
        cin >> First_number;
        cout << "Enter Second number:";
        cin >> Second_number;
        cout << "\n 1.Addition \n 2.Subtraction \n 3.Multiplication \n 4.Division \n 5.Exit \n\n Enter your choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Addition = First_number + Second_number;
            cout << "\nThe Addition is:" << Addition;
            break;
        case 2:
            Subtraction = First_number - Second_number;
            cout << "\nThe Subtraction is:" << Subtraction;
            break;
        case 3:
            Multiplication = First_number * Second_number;
            cout << "\nThe Multiplication is:" << Multiplication;
            break;
        case 4:
            Division = First_number / Second_number;
            cout << "\nThe Division is:" << Division;
            break;
        case 5:
            exit(4);
        default:
            cout << "\nWrong choice!!\n";
        }
        cout << "\n\nDone!!";
    } while (choice != 5);
    return 0;
}