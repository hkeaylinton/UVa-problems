#include <stdio.h>

int main()
{
	int A, C, prev_X, next_X, ons, i;

	while (true)
	{
		scanf("%d", &A);
		if (A == 0)
		{
			break;
		}
		scanf("%d", &C);

		scanf(" %d", &prev_X);
		ons = A - prev_X;
		for (i = 1; i < C; i++)
		{
			scanf(" %d", &next_X);
			if (next_X < prev_X)
			{
				ons += prev_X - next_X;
			}
			prev_X = next_X;
		}

		printf("%d\n", ons);
	}

	return 0;
}