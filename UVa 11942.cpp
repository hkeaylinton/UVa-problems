#include <iostream>

using namespace std;

int main()
{
	int N, first, second, i;
	bool condition, ordered;

	cout << "Lumberjacks:\n";

	cin >> N;
	while (N--)
	{
		ordered = true;
		cin >> first;
		cin >> second;
		condition = (first <= second);
		first = second;

		for (i = 1; i < 9; i++)
		{
			cin >> second;
			if (condition != (first <= second))
			{
				ordered = false;
			}
			first = second;
		}

		if (ordered)
		{
			cout << "Ordered\n";
		}
		else
		{
			cout << "Unordered\n";
		}
	}

	return 0;
}