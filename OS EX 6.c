/* 6. Preemptive Priority Scheduling */

#include <stdio.h>

int main()
{
    int n, i, time = 0, completed = 0;
    int bt[20], rt[20], priority[20];
    int wt[20], tat[20];
    int min, pos;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter Burst Time and Priority for P%d: ", i + 1);
        scanf("%d%d", &bt[i], &priority[i]);
        rt[i] = bt[i];
        wt[i] = 0;
    }

    while (completed < n)
    {
        min = 9999;
        pos = -1;

        for (i = 0; i < n; i++)
        {
            if (rt[i] > 0 && priority[i] < min)
            {
                min = priority[i];
                pos = i;
            }
        }

        if (pos == -1)
            break;

        rt[pos]--;
        time++;

        if (rt[pos] == 0)
        {
            completed++;
            tat[pos] = time;
            wt[pos] = tat[pos] - bt[pos];
        }
    }

    printf("\nProcess\tBurst\tPriority\tWaiting\tTurnaround\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t\t%d\t%d\n",
               i + 1, bt[i], priority[i], wt[i], tat[i]);
    }

    return 0;
}