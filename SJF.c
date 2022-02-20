#include <stdio.h>
#include <conio.h>

int main()
{
    int bt[20], p[20], wt[20], tat[20], i, j, n, total = 0;
    float avgWT, avgTAT;
    printf("Enter number of process -- ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter burst time for process %d:", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }


    for (i = 0; i < n; i++)
    {
        int position = i;
        for (j = i + 1; j < n; j++)
        {
            if (bt[j] < bt[position])
                position = j;
        }

        int temp = bt[i];
        bt[i] = bt[position];
        bt[position] = temp;

        temp = p[i];
        p[i] = p[position];
        p[position] = temp;
    }

    wt[0] = 0;

    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];

        total += wt[i];
    }

    avgWT = (float)total / n;
    total = 0;

    printf("\tPROCESS \tBURST TIME \tWAITING TIME \tTURNAORUND TIME\n");
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        printf("\nPROCESS%d\t\t  %d\t\t    %d\t\t%d", p[i], bt[i], wt[i], tat[i]);
    }

    avgTAT = (float)total / n;
    printf("\nAverage Waiting Time=%f", avgWT);
    printf("\nAverage Turnaround Time=%f\n", avgTAT);

    return 0;
}
