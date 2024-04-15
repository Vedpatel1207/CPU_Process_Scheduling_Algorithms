#include<stdio.h>
#include <stdlib.h>

void fcfs(int n, int at[n], int bt[n], int temp[n], int tat[n], int wt[n])
{
    FILE *op;
    op = fopen("outp.txt", "w");

    int cnt = 0, t = 0, Total_wt = 0, Total_tat = 0;

    fprintf(op, "%s", "Gantt Chart : ");

    int id = -1;
    int mi = 1000000000, ind = -1;
    for (t; cnt < n; t++)
    {
        mi = 100000000;
        ind = -1;

        for (int j = 0; j < n; j++)
        {

            if (bt[j] > 0 && at[j] <= t && at[j] < mi)
            {
                ind = j;
                mi = at[j];
            }
        }
        if (ind == -1 && id == -1)
        {
            fprintf(op, "%s", "- ");

            continue;
        }
        if (ind != -1)
            id = ind;
        bt[id] -= 1;
        fprintf(op, "%d ", id);

        if (bt[id] == 0)
        {
            cnt++;

            tat[id] = t + 1 - at[id];
            wt[id] = tat[id] - temp[id];

            Total_tat += tat[id];
            Total_wt += wt[id];
            id = -1;
        }
    }

    float avg_tat = (float)Total_tat / n;
    float avg_wt = (float)Total_wt / n;
    fprintf(op, "%s", "\n");
    fprintf(op, "%s %f %s", "Average Turn-Around Time : ", avg_tat, "\n");
    fprintf(op, "%s %f %s", "Average Waiting Time : ", avg_wt, "\n");

    fclose(op);
}