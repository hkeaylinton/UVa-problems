#include <string>
#include <cstdio>
#include <map>
#include <iostream>

using namespace std;

int main()
{
	string names[10], name;
	int N, i, j, num_gifts, gain, loss;
	bool print_newline = false;

	while (cin >> N) // != EOF
	{
		map<string, int> profits;
		for (i = 0; i < N; i++)
		{
			cin >> names[i];
			profits[names[i]] = 0;
		}

		for (i = 0; i < N; i++)
		{
			cin >> name >> loss >> num_gifts;
			
			if (num_gifts != 0)
			{
				gain = loss / num_gifts;
				//cout << "gain: " << gain << endl;

				profits[name] -= (gain * num_gifts);

				for (j = 0; j < num_gifts; j++)
				{
					cin >> name;
					//cout << "name: " << name << endl;
					profits[name] += gain;
					//cout << "new profit: " << profits[name] << endl;
				}
			}
		}
		//printf("GOT INFO\n");
		if (print_newline)
		{
			printf("\n");
		}
		for (i = 0; i < N; i++)
		{
			//printf("Name: %s\n", names[i]);
			//printf("Balance: %s\n", profits[names[i]]);
			//printf("%s %d\n", names[i], profits[names[i]]);
			cout << names[i] << " " << profits[names[i]] << endl;
		}
		print_newline = true;
	}

	return 0;
}
