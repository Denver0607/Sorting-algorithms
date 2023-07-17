#include<iostream>
using namespace std;

//Function to calculate S=1+2+3+...+n
int calcSum(int n)
{
    if (n == 1)
        return 1;
    else return n + calcSum(n - 1);
}

//Calculate the factorial n!=1*2*3*...*n
int factorial(int n)
{
    if (n == 1)
        return 1;
    else return n * factorial(n - 1);
}

//Calculate x^n
int calcPower(int x, int n)
{
    if (n == 0)
        return 1;
    else return x * calcPower(x, n - 1);
}

//Count the number of digits of a given integer
int numberOfDigits(int n)
{
    if (n == 0)
        return 0;
    else return 1 + numberOfDigits(n / 10);
}

//Verify if every digits of given integer are even
int verifyEvenDigit(int n)
{
    if (n < 10)
        return (n % 2 == 0);

    int lastDigit = n % 10;
    if (lastDigit % 2 == 0)
        return 1;
    return verifyEvenDigit(n / 10);
}

//Calculate the greatest common divisor of 2 given integers
int GCD(int a, int b)
{
    if (b == 0)
        return a;
    else return GCD(b, a % b);
}

//Count the number of common divisor of 2 given integers 
int countCommonDivisor(int a, int b)
{
    //Base case
    if (a == 0 || b == 0)
        return 0;

    int gcdValue = GCD(a, b);
    int count = 0;

    for (int i = 1; i < gcdValue;i++)
    {
        if (a % i == 0 && b % i == 0)
            count++;
    }

    return countCommonDivisor(a / gcdValue, b / gcdValue);
}

int main()
{
    int option, x, n, a, b;
    while (1)
    {
        //Define a menu
        cout << "--------------------MENU----------------------\n";
        cout << "1. Calculate the sum of S = 1 + 2 + 3 + ... + n\n";
        cout << "2. Calculate the factorial n! = 1 * 2 * 3 * ... * n\n";
        cout << "3. Calculate x^n\n";
        cout << "4. Count the number of digits of a given integer\n";
        cout << "5. Verify if every digits of given integer are even\n";
        cout << "6. Count the number of common divisor of 2 given integers\n";
        cout << "0. Stop\n";
        cout << "--------------------------\n";
        cout << "Your choice = ";
        cin >> option;
        if (option == 1)
        {
            cout << "n = ";
            cin >> n;
            cout << "S = 1 + 2 + 3 + ... + " << n << " = " << calcSum(n) << endl;
            continue;
        }
        else if (option == 2)
        {
            cout << "n = ";
            cin >> n;
            cout << "n! = 1 * 2 * 3 + ... * " << n << " = " << factorial(n) << endl;
        }
        else if (option == 3)
        {
            cout << "x = ";
            cin >> x;
            cout << "n = ";
            cin >> n;
            cout << "x^n = " << calcPower(x, n) << endl;
        }
        else if (option == 4)
        {
            cout << "n = ";
            cin >> n;
            cout << "Number of digits of " << n << " = " << numberOfDigits(n) << endl;
        }
        else if (option == 5)
        {
            cout << "n = ";
            cin >> n;
            if (verifyEvenDigit(n) == 1)
                cout << "Every digits of " << n << " are even\n";
            else cout << "Every digits of " << n << " are not even\n";
        }
        else if (option == 6)
        {
            cout << "a = ";
            cin >> a;
            cout << "b = ";
            cin >> b;
            cout << "There are " << countCommonDivisor(a,b) << "number of common divisor of " << a << " and " << b << endl;
        }
        else if (option == 0)
            break;
    }
}