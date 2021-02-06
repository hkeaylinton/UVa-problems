#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N, m_count, f_count, i;
	string tracks;

	scanf("%d", &N);
	getline(cin, tracks);

	while (N--)
	{
		m_count = 0;
		f_count = 0;

		getline(cin, tracks);
		for (i = 0; i < tracks.length(); i++)
		{
			if (tracks[i] == 'M')
			{
				m_count++;
			}
			else if (tracks[i] == 'F')
			{
				f_count++;
			}
		}

		if (m_count == f_count && m_count > 1)
		{
			printf("LOOP\n");
		}
		else
		{
			printf("NO LOOP\n");
		}
	}

	return 0;
}