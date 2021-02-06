#include <iostream>

using namespace std;

int main()
{
	int duration, num_deps, month = 0, temp_month, current_month = 0, i;
	double down, car_value, owed, deps[101], dep, temp_dep, monthly_pay;

	while (true)
	{
		cin >> duration >> down >> car_value >> num_deps;
		
		if (duration < 0)
		{
			break;
		}

		if (num_deps--)
		{
			cin >> month >> dep;
		}
		while (num_deps--)
		{
			cin >> temp_month >> temp_dep;
			for (i = month; i < temp_month; i++)
			{
				deps[i] = dep;
			}
			month = temp_month;
			dep = temp_dep;
		}
		for (i = month; i < 101; i++)
		{
			deps[i] = dep;
		}

		owed = car_value;
		monthly_pay = owed / duration;
		car_value = (car_value + down) * (1 - deps[0]);

		while (car_value < owed)
		{
			current_month++;
			owed -= monthly_pay;
			car_value *= (1 - deps[current_month]);
		}

		cout << current_month << " month";
		if (current_month != 1)
		{
			cout << "s";
		}
		cout << endl;

		month = 0;
		current_month = 0;
	}

	return 0;
}