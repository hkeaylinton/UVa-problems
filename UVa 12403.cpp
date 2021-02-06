#include <iostream>
#include <string.h>

int main()
{
	int T, x;
	int K = 0;
	char command[6];
	scanf("%d", &T);

	while (T--)
	{
		scanf("%s", &command);
		if (strcmp(command, "donate") == 0)
		{
			scanf("%d", &x);
			K += x;
		}
		else
		{
			printf("%d%s", K, "\n");
		}
	}

	return 0;
}