#include <cstdio>

using namespace std;

int a; //Holds number of Alice's cards
int b; //Holds number of Betty's cards
int n, i; //Placeholders
int a_found, b_found; //Number of cards found in the hands of Alice and Betty, respectively
int a_trades, b_trades; //Number of trades that can be made by Alice and Betty, respectively.

int main()
{
	scanf("%d %d", &a, &b);
	while (a)
	{
		//Holds number of cards of each value in hands of Alice and Betty, respectively.
		int alice[100001] = { 0 }, betty[100001] = { 0 };
		a_found = b_found = a_trades = b_trades = 0;

		//Get card values
		for (i = 0; i < a; i++)
		{
			scanf(" %d", &n);
			++alice[n];
		}
		for (i = 0; i < b; i++)
		{
			scanf(" %d", &n);
			++betty[n];
		}

		//Check tradable cards
		for (i = 1; i < 100001; i++)
		{
			//If Alice has the ith value in hand
			if (alice[i])
			{
				a_found += alice[i]; //Found however many cards of said value Alice has
				if (betty[i]) //If Betty also has the ith value in hand
				{
					b_found += betty[i]; //Ditto
				}
				else
				{
					++a_trades; //Otherwise, Alice can trade the ith value
				}
				continue;
			}
			//If Alice does not hold the ith value and Betty does, Betty can trade this value
			if (betty[i])
			{
				b_found += betty[i];
				++b_trades;
			}
			if (a_found >= a && b_found >= b) //If all possible cards found, exit.
			{
				break;
			}
		}
		//The amount of trades possible is the minimum of the amount of trades that Alice and Betty can make.
		printf("%d\n", a_trades < b_trades ? a_trades : b_trades);
		scanf("%d %d", &a, &b);
	}

	return 0;
}
