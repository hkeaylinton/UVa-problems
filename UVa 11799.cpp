#include <iostream>

using namespace std;

int main()
{
	int T, N, c, max, i;

	cin >> T;
	for (i = 1; i < T + 1; i++)
	{
		max = 0;
		cin >> N;
		while (N--)
		{
			cin >> c;
			if (c > max)
			{
				max = c;
			}
		}

		printf("Case %d: %d\n", i, max);
	}
}