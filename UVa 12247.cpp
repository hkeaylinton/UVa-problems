#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int princess[3], prince[2], init_val;

/*
Recursively determines lowest possible card that prince can be given
for a guaranteed win by starting with a first guess and checking the guess
card isn't already held by prince or princess. If it is, increments guess by 1
and checks again. Returns -1 if no such card exists.

Args:
	queue<int> cant_be:
		Queue of card values that the card given to the prince cannot be.
		This consists of all card values in the hands of prince/princess
		that logically need to be checked.

Returns:
	Lowest possible card that prince can be given, or -1 if no such card exists.
*/
int get_lowest_possible(queue<int> cant_be, int val)
{
	if (cant_be.size())
	{
		if (val == cant_be.front())
		{
			cant_be.pop();
			return get_lowest_possible(cant_be, ++val);
		}
		else
		{
			if (val == 53)
			{
				return -1;
			}
			return val;
		}
	}
	else
	{
		if (val == 53)
		{
			return -1;
		}
		return val;
	}
}

int main()
{
	scanf("%d %d %d %d %d", &princess[0], &princess[1], &princess[2], &prince[0], &prince[1]);
	while (princess[0])
	{
		sort(princess, princess + 3);
		sort(prince, prince + 2);

		//Holds card values that the lowest possible card given to prince cannot be
		queue<int> cant_be;
		
		//If princes' highest > princess' highest
		if (prince[0] > princess[2])
		{
			//Guess 1 for lowest possible card, compare with all cards to check neither
			//prince nor princess have 1.
			cant_be.push(princess[0]);
			cant_be.push(princess[1]);
			cant_be.push(princess[2]);
			cant_be.push(prince[0]);
			cant_be.push(prince[1]);
			init_val = 1;
			printf("%d\n", get_lowest_possible(cant_be, init_val));
		}
		//If prince's highest > princess' highest, but princess' highest > prince's lowest
		else if (prince[1] > princess[2] && princess[2] > prince[0])
		{
			//If prince's lowest > princess' 2nd highest, guess 1 above princess' 2nd highest
			if (prince[0] > princess[1])
			{
				cant_be.push(prince[0]);
				cant_be.push(princess[2]);
				cant_be.push(prince[1]);
				init_val = princess[1] + 1;
			}
			//Otherwise, can guess one above princess' highest
			else
			{
				cant_be.push(prince[1]);
				init_val = princess[2] + 1;
			}
			printf("%d\n", get_lowest_possible(cant_be, init_val));
		}
		//If princess' highest > prince's highest and prince's lowest > princess' 2nd highest
		else if (princess[2] > prince[1] && prince[0] > princess[1])
		{
			cant_be.push(prince[0]);
			cant_be.push(prince[1]);
			cant_be.push(princess[2]);
			init_val = princess[1] + 1;
			printf("%d\n", get_lowest_possible(cant_be, init_val));
		}
		else
		{
			printf("-1\n");
		}

		scanf("%d %d %d %d %d", &princess[0], &princess[1], &princess[2], &prince[0], &prince[1]);
	}

	return 0;
}