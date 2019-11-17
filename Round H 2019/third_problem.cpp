#include <iostream>
using namespace std;

bool canBeMultipleOf11(int integer);

int main()
{
    int numOfTestCases;
    int integer;
    cin >> numOfTestCases;
    for (int i = 0; i < numOfTestCases; i++)
    {
        bool decision;
        cin >> integer;

        decision = canBeMultipleOf11(integer);

        if (decision)
        {
            cout << "\nCase #" << i + 1 << ": YES";
        }
        else
        {
            cout << "\nCase #" << i + 1 << ": NO";
        }

        cout << endl;
    }
}

bool canBeMultipleOf11(int integer)
{
    int num1[9], num2[9] = {0}, result;

    for (int i = 0; i < 9; i++)
    {
        int remainder;
        remainder = integer % 10;
        num1[i] = remainder;

        integer = (integer - remainder) / 10;
    }

    for (int i = 1; i < 9; i++)
    {
        if (i % 2 == 0)
            result = num1[i] - num1[i + 1];
        else
            result = num1[i] + num1[i + 1];
    }

    if (result == 0)
        return true;
    else
        return false;
}
