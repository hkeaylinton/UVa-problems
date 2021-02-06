#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int digital_sum(int n)
{
	int sum;
	while (n >= 10)
	{
		sum = 0;
		while (n != 0)
		{
			sum += (n % 10);
			n = n / 10;
		}
		n = sum;
	}

	return n;
}

int main()
{
	//char name1[25], name2[25], c;
	string name1, name2;
	char c;
	int score1, score2, i, temp, a_val = (int)('a');

	//while (scanf("%s", name1) && scanf("%s", name2))
	while (getline(cin, name1) && getline(cin, name2))
	{
		score1 = 0, score2 = 0;

		for (i = 0; name1[i]; i++)
		{
			c = name1[i];
			if (c >= 'a' && c <= 'z')
			{
				score1 += c - 'a' + 1;
			}
			else if (c >= 'A' && c <= 'Z')
			{
				score1 += c - 'A' + 1;
			}
		}

		score1 = digital_sum(score1);

		for (i = 0; name2[i]; i++)
		{
			c = name2[i];
			if (c >= 'a' && c <= 'z')
			{
				score2 += c - 'a' + 1;
			}
			else if (c >= 'A' && c <= 'Z')
			{
				score2 += c - 'A' + 1;
			}
		}

		score2 = digital_sum(score2);

		if (score1 > score2)
		{
			temp = score1, score1 = score2; score2 = temp;
		}

		printf("%.2f %%\n", 100 * (double)score1 / score2);
	}

	return 0;
}
