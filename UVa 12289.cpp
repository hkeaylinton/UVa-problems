#include <iostream>
#include <string.h>

using namespace std;

const int ARR_SIZE = 5 * sizeof(char);

int main()
{
	char number[5];
	int N = 0;
	int one_count = 0;

	cin >> N;
	while (N--)
	{
		memset(number, 0, ARR_SIZE);
		cin >> number;
		if (strlen(number) == 3)
		{
			one_count = 0;
			if (number[0] == 'o')
			{
				one_count++;
			}
			if (number[1] == 'n')
			{
				one_count++;
			}
			if (number[2] == 'e')
			{
				one_count++;
			}

			if (one_count > 1)
			{
				printf("1\n");
			}
			else
			{
				printf("2\n");
			}
		}
		else
		{
			printf("3\n");
		}
		
	}

	return 0;
}