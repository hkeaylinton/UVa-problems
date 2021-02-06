#include <iostream>

using namespace std;

int main()
{
	int T, L, W, H;
	cin >> T;
	int Case = 0;

	while (T--)
	{
		cin >> L >> W >> H;
		if (L > 20 || W > 20 || H > 20)
		{
			printf("Case %d: bad\n", ++Case);
		}
		else
		{
			printf("Case %d: good\n", ++Case);
		}
	}

	return 0;
}