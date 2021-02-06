#include <iostream>
#include <string>
#include <float.h>

using namespace std;

int main()
{
	int n, p, i, j, num_candidates, r, chosen_prop, rfps = 0;
	double prices[1001], c, max_c, d, max_d, num_reqs, num_reqs_total;
	string req, prop, prop_candidates[1001];

	while (cin >> n >> p, n || p)
	{
		rfps++;
		num_reqs_total = 0, max_c = 0;
		num_candidates = 0;
		max_d = DBL_MAX;

		for (i = 0; i < n; i++)
		{
			cin.ignore();
			getline(cin, req, '\n');
			num_reqs_total++;
		}

		for (i = 0; i < p; i++)
		{
			num_reqs = 0;
			getline(cin, prop, '\n');
			cin >> d >> r;

			for (j = 0; j < r; j++)
			{
				cin.ignore();
				getline(cin, req, '\n');
				num_reqs++;
			}

			c = num_reqs / num_reqs_total;

			if (c > max_c)
			{
				num_candidates = 1;
				prices[1] = d;
				prop_candidates[1] = prop;
				max_c = c;
			}
			else if (c == max_c)
			{
				num_candidates++;
				prices[num_candidates] = d;
				prop_candidates[num_candidates] = prop;
			}
		}
		
		for (i = 1; i < num_candidates + 1; i++)
		{
			if (prices[i] < max_d)
			{
				max_d = prices[i];
				chosen_prop = i;
			}
		}

		if (rfps > 1)
		{
			cout << endl;
		}
		cout << "RFP #" << rfps << endl;
		cout << prop_candidates[chosen_prop] << endl;
	}

	return 0;
}