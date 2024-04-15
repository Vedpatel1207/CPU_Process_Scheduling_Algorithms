#include<stdio.h>
#include <stdlib.h>

void rr(int n, int at[n], int bt[n], int temp[n], int tat[n], int wt[n])
{

    int cnt = 0, t = 0, Total_wt = 0, Total_tat = 0, tc = 1;
    FILE *op, *fp;
    op = fopen("outp.txt", "w");

    fp = fopen("inp.txt", "r");

    fscanf(fp, "%d", &n);

    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &at[i]);
    }
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &bt[i]);
        temp[i] = bt[i];
    }
    fscanf(fp, "%d", &tc);

    int f = -1, r = -1, ind = 0;
    int qu[n], ms[n];
    for (int i = 0; i < n; i++)
        qu[i] = i;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (at[qu[j]] < at[qu[i]])
            {
                int tmp = qu[i];
                qu[i] = qu[j];
                qu[j] = tmp;
            }
        }
    }

    fprintf(op, "%s", "Gantt Chart : ");
    int id = -1;
    int mi = 1000000000;
    for (t; cnt < n; t++)
    {
        // printf("%d\n",t);
        // printf("%d %d\n",f,r);
        while (ind < n && t >= at[qu[ind]])
        {

            if (f == -1)
                f = r = 0;
            else
                r = (r + 1) % n;
            ms[r] = qu[ind];
            ind++;
        }

        if (f == -1)
        {
            fprintf(op, "%s", "- ");

            continue;
        }
        id = ms[f];
        if (f == r)
            f = r = -1;
        else
            f = (f + 1) % n;
        int x = 0;
        if (tc > bt[id])
            x = bt[id];
        else
            x = tc;
        while (x--)
        {

            bt[id] -= 1;
            fprintf(op, "%d ", id);
            if (t >= at[qu[ind]] && ind < n)
            {
                if (f == -1)
                    f = r = 0;
                else
                    r = (r + 1) % n;
                ms[r] = qu[ind];
                ind++;
            }
            t++;
        }
        t--;

        if (bt[id] == 0)
        {
            cnt++;

            tat[id] = t + 1 - at[id];
            wt[id] = tat[id] - temp[id];

            Total_tat += tat[id];
            Total_wt += wt[id];
            id = -1;
        }
        else
        {
            r = (r + 1) % n;
            ms[r] = id;
            if (f == -1)
                f = 0;
        }
    }

    float avg_tat = (float)Total_tat / n;
    float avg_wt = (float)Total_wt / n;
    fprintf(op, "%s", "\n");
    fprintf(op, "%s %f %s", "Average Turn-Around Time : ", avg_tat, "\n");
    fprintf(op, "%s %f %s", "Average Waiting Time : ", avg_wt, "\n");
    fclose(op);
    fclose(fp);
}
