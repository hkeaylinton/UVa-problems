#include <iostream>

using namespace std;

int main()
{
	char ch;
	bool first_quote = true; 

	while (cin.get(ch))
	{
		if (ch == '\"')
		{
			if (first_quote == true)
			{
				cout << "``";
			}
			else
			{
				cout << "''";
			}
			first_quote = !first_quote;
		}
		else
		{
			cout << ch;
		}
	}

	return 0;
}