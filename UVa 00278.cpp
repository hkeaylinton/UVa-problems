#include <cstdio>

int N, m, n;
char p;

int main()
{
	scanf("%d", &N);
	while (N--)
	{
		scanf(" %c %d %d", &p, &m, &n);
		
		switch (p)
		{
		case 'r': //Rook
			//Every rook placed takes out a column/row, so keep placing rooks until you run out of columns or rows
			printf("%d\n", m < n ? m : n);
			break;
		case 'k': //Knight
			//Place knights on every 2nd square in a chessboard fashion
			printf("%d\n", ((m * n) + 1) / 2);
			break;
		case 'Q': //Queen
			//Place queens in staircase fashion
			printf("%d\n", m < n ? m : n);
			break;
		case 'K': //King
			//On every second row or column (choose whichever allows the most kings) place a king on every 2nd square
			printf("%d\n", ((m + 1) / 2) * ((n + 1) / 2));
			break;
		}
	}

	return 0;
}