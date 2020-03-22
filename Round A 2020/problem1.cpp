#include <iostream>
using namespace std;

// brute force
int maxHouses(int totalHouses, int budget, int prices[]);

// recursive approach
int maxHouses(int totalHouses, int budget, int prices[], int price, int houses, int k);
int main()
{
	system("clear");
	int testCases, totalHouses, budget, price = 0, houses = 0, k = 0;
	int *prices = new int[totalHouses];
	cin >> testCases;
	int *result = new int [testCases];

	for (int i = 0; i < testCases; i++)
	{
		cin >> totalHouses >> budget;

		for (int j = 0; j < totalHouses; j++)
		{
			cin >> prices[j];
		}

		result[i] = maxHouses(totalHouses, budget, prices, price, houses, k) - 1;
	}

	for (int i = 0; i < testCases; i++)
	{
		cout << "Case #" << i + 1 << ": " <<  result[i] << endl;
	}

	delete[] result;
	delete[] prices;
}

/* brute force */
int maxHouses(int totalHouses, int budget, int prices[])
{
	int houses = 0, price = 0;
	for (int j = 0; j < totalHouses; j++)
	{
		price += prices[j];
		if(price <= budget)
			houses++;
		else
			price-=prices[j];
	}
	return houses;
}

/* recusive */

int maxHouses(int totalHouses, int budget, int prices[], int price, int houses, int k)
{
	if(k > totalHouses)
		return houses;
	price+=prices[k];
	if (price <= budget)
	{
		k++;
		houses++;
		return maxHouses(totalHouses, budget, prices, price, houses, k);
	}
	else
		price-=prices[k];
	k++;
	return maxHouses(totalHouses, budget, prices, price, houses, k);
}

/*
	Total houses: N
	ith House Costs: $Ai
	Budget: $B


	Input
	3
	4 100
	20 90 40 90
	4 50
	30 30 10 10
	3 300
	999 999 999

	Output
	Case #1: 2
	Case #2: 3
	Case #3: 0
 */
