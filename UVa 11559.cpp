#include <iostream>

using namespace std;

int main()
{
	int N, B, H, W, p, a, i, cost = 0, min_cost;

	while (scanf("%d %d %d %d", &N, &B, &H, &W) != EOF)
	{
		min_cost = B + 1;
		while (H--)
		{
			cin >> p;
			cost = N * p;
			for (i = 0; i < W; i++)
			{
				cin >> a;
				if (cost <= B && N <= a && cost < min_cost)
				{
					min_cost = cost;
				}
			}
		}
		if (min_cost <= B)
		{
			cout << min_cost << endl;
		}
		else
		{
			cout << "stay home" << endl;
		}
	}
	return 0;
}