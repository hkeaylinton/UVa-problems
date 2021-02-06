#include <iostream>

using namespace std;

int main()
{
	int k = 1;
	int m, n, a, b;

	while (k != 0)
	{
		cin >> k;
		if (k == 0)
		{
			break;
		}
		cin >> m >> n;
		for (int i = 0; i < k; i++)
		{
			cin >> a >> b;
			if (a < m) //West half
			{
				if (b < n) //SW quadrant
				{
					cout << "SO" << endl;
				}
				else if (b > n) //NW quadrant
				{
					cout << "NO" << endl;
				}
				else //Border
				{
					cout << "divisa" << endl;
				}
			}
			else if (a > m) // East half
			{
				if (b < n) //SE quadrant
				{
					cout << "SE" << endl;
				}
				else if (b > n) //NE quadrant
				{
					cout << "NE" << endl;
				}
				else //Border
				{
					cout << "divisa" << endl;
				}
			}
			else //On X border
			{
				cout << "divisa" << endl;
			}
		}
	}

	return 0;
}