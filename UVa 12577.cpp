#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	char inp[5];
	cin >> inp;
	int Case = 0;

	while (strcmp(inp, "*") != 0)
	{
		if (strcmp(inp, "Hajj") == 0)
		{
			cout << "Case " << ++Case << ": " << "Hajj-e-Akbar" << endl;
		}
		else
		{
			cout << "Case " << ++Case << ": " << "Hajj-e-Asghar" << endl;
		}
		cin >> inp;
	}

	return 0;
}