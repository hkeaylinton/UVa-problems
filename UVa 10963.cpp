#include <iostream>

using namespace std;

int main()
{
	int N, W, y1, y2, gap;
	bool closable = true;

	cin >> N;
	while (N--)
	{
		cin >> W;
		if (W--)
		{
			cin >> y1 >> y2;
			gap = y1 - y2;
		}
		while (W--)
		{
			cin >> y1 >> y2;
			if (y1 - y2 != gap)
			{
				closable = false;
			}
		}

		if (closable)
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
		if (N)
		{
			cout << "\n";
		}
		closable = true;
	}

	return 0;
}