#include <iostream>
using namespace std;

int *hIndex(int numOfTestCases, int numOfPapers, int *&numOfCitations, int *&output);

int main()
{
    int numOfTestCases, numOfPapers;

    cin >> numOfTestCases;

    for (int i = 0; i < numOfTestCases; i++)
    {
        cin >> numOfPapers;
        int *numOfCitations = new int[numOfPapers];
        int *output = new int[numOfPapers];

        for (int j = 0; j < numOfPapers; j++)
        {
            cin >> numOfCitations[j];
        }

        output = hIndex(numOfTestCases, numOfPapers, numOfCitations, output);

        cout << "Case #" << i + 1
             << ":";

        for (int j = 0; j < numOfPapers; j++)
        {
            cout << " " << output[j];
        }
        cout << endl;
        delete[] output;
        delete[] numOfCitations;
    }
}

int *hIndex(int numOfTestCases, int numOfPapers, int *&numOfCitations, int *&output)
{

    for (int i = 0; i < numOfPapers; i++)
    {
        if (i == 0)
        {
            if (numOfCitations[0] > numOfCitations[i + 1])
            {
                output[i] = numOfCitations[i + 1];
            }
            else
            {
                output[i] = numOfCitations[i];
            }
        }
        else
        {
            int min = numOfCitations[0];
            for (int j = 0; j <= i - 1; j++)
            {
                if (min > numOfCitations[j + 1])
                    min = numOfCitations[j + 1];

                if (numOfCitations[i] <= numOfCitations[j])
                {
                    output[i] = numOfCitations[i];
                    break;
                }
                else
                {

                    output[i] = min;
                }
            }
        }
    }

    return output;
}