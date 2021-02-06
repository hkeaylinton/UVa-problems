#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int ch1, ch2;

	cin >> ch1 >> ch2;
	while (ch1 != -1)
	{
		cout << min(abs(ch1 - ch2), min(abs(ch2 - (ch1 + 100)), abs(ch1 - (ch2 + 100)))) << endl;
		cin >> ch1 >> ch2;
	}

	return 0;
}