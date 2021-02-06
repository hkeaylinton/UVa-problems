#include <iostream>

using namespace std;

int main()
{
	int n, m, c, i, ci, power, max_power, powers[21] = { 0 }, sequence = 0;
	bool fuse_blown;

	cin >> n >> m >> c;
	while (n != 0 && m != 0 && c != 0) 
	{
		sequence++;
		bool on_off[21] = { false };
		fuse_blown = false;
		power = 0, max_power = 0;
		for (i = 1; i < n + 1; i++)
		{
			cin >> powers[i];
		}
		for (i = 0; i < m; i++)
		{
			cin >> ci;
			on_off[ci] = !on_off[ci];
			power = on_off[ci] ? power + powers[ci] : power - powers[ci];
			if (power > c)
			{
				fuse_blown = true;
			}
			if (power > max_power)
			{
				max_power = power;
			}
		}
		cout << "Sequence " << sequence << endl;
		if (fuse_blown)
		{
			cout << "Fuse was blown." << endl;
		}
		else
		{
			cout << "Fuse was not blown." << endl;
			cout << "Maximal power consumption was " << max_power << " amperes." << endl;
		}
		cout << endl;

		cin >> n >> m >> c;
	}

	return 0;
}