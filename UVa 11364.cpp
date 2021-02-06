#include <iostream>

using namespace std;

int main()
{
	int t, n, x;
	cin >> t;

	while (t--)
	{
		int max = 0, min = 99;
		cin >> n;
		while (n--)
		{
			cin >> x;
			if (x > max)
			{
				max = x;
			}
			if (x < min)
			{
				min = x;
			}
		}

		cout << 2 * (max - min) << endl;
	}
}