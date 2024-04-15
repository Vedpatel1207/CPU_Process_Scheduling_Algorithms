#include <stdio.h>
#include <stdlib.h>
#include "fcfs.c"
#include "priority.c"
#include "sjf.c"
#include "rr.c"
#include "srtf.c"
#include "lrtf.c"


int main()
{
    printf("1:-For First come first serve\n2:-For Shortest job first\n3:-For Round robin scheduling\n4:-For Priority scheduling\n5:-For Shortest Reamining Time first\n6:-For Longest Remaining time first\n7:-To exit\n");
    FILE *f;
    f = fopen("inp.txt", "r");
    int n;
    fscanf(f, "%d", &n);
    int at[n], bt[n], temp[n], tat[n], wt[n];
    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%d", &at[i]);
    }
    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%d", &bt[i]);
        temp[i] = bt[i];
    }
    fclose(f);
    int x;
    while (1)
    {
        printf("Enter your choice : ");
        scanf("%d", &x);
        if (x == 1)
            fcfs(n, at, bt, temp, tat, wt);
        else if (x == 2)
            sjf(n, at, bt, temp, tat, wt);
        else if (x == 3)
            rr(n, at, bt, temp, tat, wt);
        else if (x == 4)
            priority(n, at, bt, temp, tat, wt);
        else if (x == 5)
            srtf(n, at, bt, temp, tat, wt);
        else if (x == 6)
            lrtf(n, at, bt, temp, tat, wt);
        else if (x == 7)
            break;
        else
            printf("Enter valid choice||\n");
    }
}