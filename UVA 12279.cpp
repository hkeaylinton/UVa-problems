#include <iostream>

using namespace std;

int main()
{
	int N, event, emoogle;
	int Case = 0;

	while (scanf("%d", &N), N)
	{
		emoogle = 0;
		while (N--)
		{
			scanf("%d", &event);
			if (event > 0)
			{
				++emoogle;
			}
			else
			{
				--emoogle;
			}
		}
		
		printf("Case %d: %d\n", ++Case, emoogle);
	}

	return 0;
}