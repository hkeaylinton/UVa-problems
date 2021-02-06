#include <stdio.h>
#include <string.h>

char x[1000000];

int get_i(int x_len, int i)
{
	sprintf(x, "%d", x_len);
	int x_len_next = strlen(x);
	if (x_len == x_len_next)
	{
		return ++i;
	}
	else
	{
		return get_i(x_len_next, ++i);
	}
}

int main()
{
	int i;
	
	while (scanf("%s", x) && strcmp(x, "END"))
	{
		if (strcmp(x, "1") == 0)
		{
			printf("1\n");
		}
		else
		{
			printf("%d\n", get_i(strlen(x), 1));
		}
	}

	return 0;
}
