#include <iostream>

using namespace std;

int main()
{
	int n, f, a, b, c, sum;
	cin >> n;

	while (n--)
	{
		cin >> f;
		sum = 0;
		while (f--)
		{
			cin >> a >> b >> c;
			sum += a * c;
		}
		cout << sum << endl;
	}

	return 0;
}