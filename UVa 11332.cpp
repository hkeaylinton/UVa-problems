#include <iostream>
#include <math.h>

using namespace std;

int digit_sum(int n)
{
	int length = floor(log10(n)) + 1;
	//cout << "initial length: " << length << endl;
	int sum = 0;
	int digit;

	while (length--)
	{
		//cout << "length now: " << length << endl;
		digit = (int)(n / pow(10,length)) % 10;
		//cout << "digit: " << digit << endl;
		sum += digit;
	}

	if (floor(log10(sum)) == 0)
	{
		return sum;
	}
	return digit_sum(sum);
}

int main()
{
	int n;

	while (true)
	{
		cin >> n;
		if (n)
		{
			cout << digit_sum(n) << endl;
		}
		else
		{
			break;
		}
	}
	return 0;
}