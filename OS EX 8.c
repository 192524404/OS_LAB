/* 8. Round Robin Scheduling */

#include <stdio.h>

int main()
{
    int n, i, quantum;
    int bt[20], rem[20];
    int time = 0, done;
    int wt[20] = {0}, tat[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    do
    {
        done = 1;

        for (i = 0; i < n; i++)
        {
            if (rem[i] > 0)
            {
                done = 0;

                if (rem[i] > quantum)
                {
                    time += quantum;
                    rem[i] -= quantum;
                }
                else
                {
                    time += rem[i];
                    wt[i] = time - bt[i];
                    rem[i] = 0;
                }
            }
        }

    } while (!done);

    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");

    for (i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];

        printf("P%d\t%d\t%d\t%d\n",
               i + 1, bt[i], wt[i], tat[i]);
    }

    return 0;
}