#include <iostream>
using namespace std;

int main() {
	int testCases, n, k, arr[1000000] = {99999}, result[1000000] = {0}, temp = 0;

	cin >> testCases;
	for (int i = 0; i < testCases; i++)
	{
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		for (int i = 0; i < n; i++)
		{
			if ( ( arr[ i ] == k ) && ( arr[ i + ( k - 1 ) ] == ( k - ( k - 1 ) ) ) )
				temp++;
		}

		result[i] = temp;
		temp = 0;
	}

	for (int i = 0; i < testCases; i++)
	{
		cout << "Case #" << i+1 << ": " << result[i] << endl;
	}
}



/*
	Input

	3
	12 3
	1 2 3 7 9 3 2 1 8 3 2 1
	4 2
	101 100 99 98
	9 6
	100 7 6 5 4 3 2 1 100

	Output

	Case #1: 2
	Case #2: 0
	Case #3: 1

 */
