#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display(int a[], int n, int i)
{
    int l = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[l])
        l = left;
    if (right < n && a[right] > a[l])
        l = right;
    if (l != i)
    {
        int t = a[i];
        a[i] = a[l];
        a[l] = t;
        display(a, n, l);
    }
}
void sort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        display(a, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        int t = a[0];
        a[0] = a[i];
        a[i] = t;
        display(a, i, 0);
    }
}
void printout(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        printf("\n");
    }
}
int main()
{
    int n;
    printf("Enter number of elements:");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements:", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    clock_t start = clock();
    sort(a, n);
    clock_t end = clock();
    printf("Sorted array:\n");
    printout(a, n);
    printf("\nStart time:%d", start);
    printf("\nEnd time:%d", end);
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("The time taken:%fseconds\n", time_taken);
    free(a);
    return 0;
}