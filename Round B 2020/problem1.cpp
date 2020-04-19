#include <iostream>
using namespace std;

int main() {
	int testCases, checkpointNum, checkpoint[10000] = {0}, peaks = 0, result[10000] = {0};

	cin >> testCases;
	for (int i = 0; i < testCases; i++)
	{
		cin >> checkpointNum;
		for (int i = 0; i < checkpointNum; i++)
		{
			cin >> checkpoint[i];
		}

		for (int i = 1; i < checkpointNum - 1; i++)
		{
			if (checkpoint[i] > checkpoint[i-1] && checkpoint[i] > checkpoint[i+1])
			{
				peaks++;
			}

		}
		result[i] = peaks;
		peaks = 0;
	}

	for (int i = 0; i < testCases; i++)
	{
		cout << "Case #" << i+1 << ": " << result[i] << endl;
	}
}
