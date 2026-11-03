#include <stdio.h>
#include <string.h>

int c[100][100];
char b[100][100];

void LCS_LENGTH(char X[], char Y[], int m, int n)
{
    int i, j;

    for (i = 0; i <= m; i++)
        c[i][0] = 0;

    for (j = 0; j <= n; j++)
        c[0][j] = 0;

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = '\\';
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = '^';
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = '<';
            }
        }
    }
}

void PRINT_LCS(char X[], int i, int j)
{
    if (i == 0 || j == 0)
        return;

    if (b[i][j] == '\\')
    {
        PRINT_LCS(X, i - 1, j - 1);
        printf("%c", X[i - 1]);
    }
    else if (b[i][j] == '^')
    {
        PRINT_LCS(X, i - 1, j);
    }
    else
    {
        PRINT_LCS(X, i, j - 1);
    }
}

int main()
{
    char X[100], Y[100];
    int m, n;

    printf("Enter first string: ");
    scanf("%99s", X);

    printf("Enter second string: ");
    scanf("%99s", Y);

    m = strlen(X);
    n = strlen(Y);

    LCS_LENGTH(X, Y, m, n);

    printf("Length of LCS: %d\n", c[m][n]);

    printf("Longest Common Subsequence: ");
    PRINT_LCS(X, m, n);
    printf("\n");

    return 0;
}