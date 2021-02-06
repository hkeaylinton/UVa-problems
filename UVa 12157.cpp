#include <iostream>
#include <math.h>

using namespace std;

int Mile(double secs)
{
	return 10 * ceil((secs+1) / 30);
}

int Juice(double secs)
{
	return 15 * ceil((secs+1) / 60);
}

int main()
{
	int T, N, i, secs, juice_cost, mile_cost;

	cin >> T;
	for (i = 1; i < T + 1; i++)
	{
		juice_cost = 0, mile_cost = 0;
		cin >> N;
		while (N--)
		{
			cin >> secs;
			juice_cost += Juice(secs);
			mile_cost += Mile(secs);
		}

		cout << "Case " << i << ": ";
		if (mile_cost < juice_cost)
		{
			cout << "Mile " << mile_cost << endl;
		}
		else if (mile_cost > juice_cost)
		{
			cout << "Juice " << juice_cost << endl;
		}
		else
		{
			cout << "Mile Juice " << mile_cost << endl;
		}
	}

	return 0;
}