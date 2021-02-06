#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	char word[14];
	int Case = 1;
	
	while (scanf("%s", &word) != EOF)
	{
		if (strcmp(word, "#") == 0)
		{
			break;
		}

		else if (strcmp(word, "HELLO") == 0)
		{
			printf("Case %d: ENGLISH\n", Case);
		}

		else if (strcmp(word, "HOLA") == 0)
		{
			printf("Case %d: SPANISH\n", Case);
		}

		else if (strcmp(word, "HALLO") == 0)
		{
			printf("Case %d: GERMAN\n", Case);
		}

		else if (strcmp(word, "BONJOUR") == 0)
		{
			printf("Case %d: FRENCH\n", Case);
		}

		else if (strcmp(word, "CIAO") == 0)
		{
			printf("Case %d: ITALIAN\n", Case);
		}

		else if (strcmp(word, "ZDRAVSTVUJTE") == 0)
		{
			printf("Case %d: RUSSIAN\n", Case);
		}

		else
		{
			printf("Case %d: UNKNOWN\n", Case);
		}

		++Case;
	}

	return 0;
}