#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int T = 0, a = 0, b = 0, c = 0, temp = 0;
	int Case = 0;
	scanf("%d", &T);

	while (T--)
	{
		scanf(" %d %d %d", &a, &b, &c);
		if (a > c)
		{
			temp = a, a = c, c = temp;
		}
		if (b > c)
		{
			temp = b; b = c; c = temp;
		}
		if (a > b)
		{
			temp = a; a = b; b = temp;
		}
		
		printf("Case %d: %d\n", ++Case, b);
	}

	return 0;
}