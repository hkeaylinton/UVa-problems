#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		n = (63 * n + 7492) * 5 - 498;
		cout << (abs(n) / 10) % 10 << endl;
	}

	return 0;
}