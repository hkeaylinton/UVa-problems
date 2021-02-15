#include <cstdio>

int m,n,k,temp,rem; //m: # rows, n: # columns, k: # knights possible.

int main()
{
    scanf("%d %d", &m, &n);

    while (m != 0 || n != 0)
    {
        //Make so m smallest, n largest
        if (m > n)
        {
            temp = m;
            m = n;
            n = temp;
        }
        if (m == 1) //Place in line
        {
            k = n;
        }
        else if (m == 2) //Place in blocks
        {
            rem = n%4;
            k = 2 < rem ? 4*(n / 4) + 4 : 4*(n / 4) + 2*rem;
        }
        else //Place in chessboard pattern
        {
            k = (((m * n) + 1) / 2);
        }
        printf("%d knights may be placed on a %d row %d column board.\n", k, m, n);
        scanf("%d %d", &m, &n);
    }

    return 0;
}
