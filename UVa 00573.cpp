#include <iostream>
#include <limits>

using namespace std;

int main()
{
	double H, U, D, F, height, distance, fatigue;
	int days;

	while (true)
	{
		cin >> H >> U >> D >> F;
		if (H == 0)
		{
			break;
		}

		days = 1;
		height = U;
		distance = U;
		fatigue = (F / 100) * U;

		if (height > H)
		{
			cout << "success on day " << days << endl;
			continue;
		}
		
		height -= D;
		if (height < 0)
		{
			cout << "failure on day " << days << endl;
			continue;
		}

		while (height <= H && height >= 0)
		{
			days++;
			distance = distance > fatigue ? distance - fatigue : 0;
			height += distance;

			if (height > H)
			{
				break;
			}

			height -= D;
		}

		if (height > H)
		{
			cout << "success on day " << days << endl;
		}
		else
		{
			cout << "failure on day " << days << endl;
		}
	}

	return 0;
}