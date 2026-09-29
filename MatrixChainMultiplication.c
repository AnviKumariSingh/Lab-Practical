#include <limits.h>
#include <stdio.h>

int m[20][20];
int s[20][20];

void print_parentheses(int i, int j)
{
    if (i == j)
    {
        printf("A%d", i);
    }
    else
    {
        printf("(");

        print_parentheses(i, s[i][j]);
        print_parentheses(s[i][j] + 1, j);

        printf(")");
    }
}

int get_chain(int p[], int n)
{
    int q, j;

    for (int i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }

    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return m[1][n];
}

int main()
{
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    int p[n + 1];
    printf("Enter the dimensions of matrices: ");
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    int min_cost = get_chain(p, n);
    printf("Minimum number of multiplications is %d\n", min_cost);
    printf("Optimal Parenthesization is: ");
    print_parentheses(1, n);
    printf("\n");
    return 0;
}