#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	string result;
	cin >> n;

	while (n--)
	{
		cin >> result;
		int length = result.size();

		if (result[length - 1] == '5' && result[length - 2] == '3')
		{
			cout << "-\n";
		}
		else if (result[0] == '9' && result[length - 1] == '4')
		{
			cout << "*\n";
		}
		else if (result[0] == '1' && result[1] == '9' && result[2] == '0')
		{
			cout << "?\n";
		}
		else
		{
			cout << "+\n";
		}
	}

	return 0;
}