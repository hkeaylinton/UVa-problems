#include<iostream>

using namespace std;

int main()
{
	int T, N, lows, highs, current, next, diff, i;

	cin >> T;
	for (i = 1; i < T+1; i++)
	{
		cin >> N;
		lows = 0, highs = 0;

		if (N--)
		{
			cin >> current;
			while (N--)
			{
				cin >> next;
				diff = next - current;
				if (diff < 0)
				{
					lows++;
				}
				else if (diff > 0)
				{
					highs++;
				}
				current = next;
			}
		}

		printf("Case %d: %d %d\n", i, highs, lows);
	}

	return 0;
}