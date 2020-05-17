#include <iostream>
using namespace std;

int main() {
	int testCases, arrivalDay, totalBusRoutes, buses[1000] = {0}, day = 2, latestDay = 0, results[1000] = {0}, checks[1000] = {false};

	for (int i = 0; i < testCases; i++)
	{
		cin >> totalBusRoutes >> arrivalDay;
		for (int i = 0; i < totalBusRoutes; i++)
		{
			cin >> buses[i];
		}

		/* for (int i = 0; i < totalBusRoutes; i++)
		{

			if((buses[i] % day == 0) && (day > arrivalDay/2))
			{
				checks[i] = true;
			}

			if(checks[i])
			{
				day++;
				if((buses[i + 1] % day == 0) && (day > arrivalDay/2))
				{
					checks[i+1] = true;
				}
			}
		} */


		bool check = false;
		int index;
		for (int i = 0; i < totalBusRoutes; i++)
		{
			for (int j = 2; j <= buses[totalBusRoutes]; j++)
			{
				if (buses[i] % j == 0)
				{
					if(j == buses[i])
					{
						check = true;
						index = j;
					}
				}

			}
		}



		results[i] = latestDay;
		latestDay = 0;
	}

	for (int i = 0; i < testCases; i++)
		{
			cout << "Case #" << i+1 << ": " << results[i] << endl;
		}
}
