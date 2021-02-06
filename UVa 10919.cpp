#include <stdio.h>

int main()
{
	int k, m, c, r, course, courses[100], i, num_reqs_met;
	bool reqs_met;

	while (scanf("%d", &k) && k)
	{
		reqs_met = true;
		scanf("%d", &m);

		for (i = 0; i < k; i++)
		{
			scanf("%d", &courses[i]);
		}
		
		while (m--)
		{
			num_reqs_met = 0;
			scanf("%d %d", &c, &r);
			while (c--)
			{
				scanf("%d", &course);
				for (i = 0; i < k; i++)
				{
					if (courses[i] == course)
					{
						num_reqs_met += 1;
					}
				}
			}
			
			if (num_reqs_met < r)
			{
				reqs_met = false;
			}
		}

		if (reqs_met)
		{
			printf("%s", "yes\n");
		}
		else
		{
			printf("%s", "no\n");
		}
	}

	return 0;
}