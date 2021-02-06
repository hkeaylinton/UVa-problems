#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string str;
	int n, i, j, k, Case = 0;
	bool same;

	while (cin >> str)
	{
		Case++;
		cout << "Case " << Case << ":" << endl;
		cin >> n;
		while (n--)
		{
			same = true;
			cin >> i >> j;
			if (j < i)
			{
				swap(i, j);
			}

			for (k = i + 1; k < j + 1; k++)
			{
				if (str[k] != str[i])
				{
					same = false;
				}
			}

			if (same)
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}
	}

	return 0;
}
