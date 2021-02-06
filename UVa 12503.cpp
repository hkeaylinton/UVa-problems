#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T, n, pos, ref, i;
	string instructions[101], dir, dummy;

	cin >> T;
	while (T--)
	{
		pos = 0;
		cin >> n;
		for (i = 1; i < n + 1; i++)
		{
			cin >> dir;

			if (dir == "LEFT")
			{
				pos--;
				instructions[i] = dir;
			}
			else if (dir == "RIGHT")
			{
				pos++;
				instructions[i] = dir;
			}
			else
			{
				cin >> dummy >> ref;
				instructions[i] = instructions[ref];
				if (instructions[i] == "LEFT")
				{
					pos--;
				}
				else
				{
					pos++;
				}
			}
		}
		cout << pos << endl;
	}

	return 0;
}