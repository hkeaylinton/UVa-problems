#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, i, count = 0;
	string people[101];
	string song[16] = { "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you" };

	cin >> n;
	for (i = 1; i < n + 1; i++)
	{
		cin >> people[i];
	}

	while (count < n)
	{
		for (i = 0; i < 16; i++)
		{
			cout << people[(count % n) + 1] << ": " << song[count % 16] << endl;
			count++;
		}
	}

	return 0;
}