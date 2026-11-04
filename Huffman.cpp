#include <stdio.h>

int f[200], l[200], r[200], p[200];
char ch[200];

void print(int i, int code[], int top)
{
    int j;

    if (l[i] == -1 && r[i] == -1)
    {
        printf("%c : ", ch[i]);
        if (top == 0)
            printf("0");
        for (j = 0; j < top; j++)
            printf("%d", code[j]);
        printf("\n");
        return;
    }

    code[top] = 0;
    print(l[i], code, top + 1);

    code[top] = 1;
    print(r[i], code, top + 1);
}

int main()
{
    int n, i, k, a, b, code[200];

    printf("Enter number of characters: ");
    scanf("%d", &n);

    for (i = 0; i < 2 * n - 1; i++)
        p[i] = l[i] = r[i] = -1;

    for (i = 0; i < n; i++)
    {
        printf("Enter character and frequency: ");
        scanf(" %c %d", &ch[i], &f[i]);
    }

    for (k = n; k < 2 * n - 1; k++)
    {
        a = b = -1;
        for (i = 0; i < k; i++)
        {
            if (p[i] == -1)
            {
                if (a == -1 || f[i] < f[a])
                    b = a, a = i;
                else if (b == -1 || f[i] < f[b])
                    b = i;
            }
        }

        l[k] = a;
        r[k] = b;
        f[k] = f[a] + f[b];
        p[a] = p[b] = k;
    }

    printf("\nHuffman Codes:\n");
    print(2 * n - 2, code, 0);

    return 0;
}