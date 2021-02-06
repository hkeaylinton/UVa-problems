#include <iostream>
#include <string>

using namespace std;

int main()
{
	int T, rels[10] = { 0 }, max, i, j;
	string sites[10] = { "" };
	cin >> T;

	for (i = 1; i < T + 1; i++)
	{
		max = 0;
		for (j = 0; j < 10; j++)
		{
			cin >> sites[j] >> rels[j];
			if (rels[j] > max)
			{
				max = rels[j];
			}
		}

		cout << "Case #" << i << ":" << endl;
		for (j = 0; j < 10; j++)
		{
			if (rels[j] == max)
			{
				cout << sites[j] << endl;
			}
		}
	}

	return 0;
}