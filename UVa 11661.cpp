#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int L, R, D, i, min_dist, dist;
	char c;
	bool found;

	while (scanf("%d", &L) && L)
	{
		R = L;
		D = 2 * L;
		min_dist = L;

		for (i = 0; i < L; i++)
		{
			scanf(" %c", &c);
			found = false;

			if (c == 'Z')
			{
				min_dist = 0;
			}
			else if (c == 'R')
			{
				found = true;
				R = i;
			}
			else if (c == 'D')
			{
				found = true;
				D = i;
			}
			if (found)
			{
				if (R > D)
				{
					dist = R - D;
				}
				else
				{
					dist = D - R;
				}
				

				if (dist < min_dist)
				{
					min_dist = dist;
				}
			}
		}
		printf("%d\n", min_dist);
	}

	return 0;
}
