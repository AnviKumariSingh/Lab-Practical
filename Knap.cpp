#include <stdio.h>

int main()
{
    int n, i, j;
    float capacity, profit[100], weight[100], ratio[100];
    float temp, totalProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter capacity of knapsack: ");
    scanf("%f", &capacity);

    for (i = 0; i < n; i++)
    {
        printf("Enter profit and weight of item %d: ", i + 1);
        scanf("%f %f", &profit[i], &weight[i]);

        ratio[i] = profit[i] / weight[i];
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (weight[i] <= capacity)
        {
            totalProfit += profit[i];
            capacity -= weight[i];
        }
        else
        {
            totalProfit += ratio[i] * capacity;
            break;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}