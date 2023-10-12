#include<stdio.h>
#define size 100
#include<limits.h>
void calculation(int burst_time[],int arrival_time[],int process[],int n);
void main(){
    int burst_time[size];
    int arrival_time[size];
    int process[size];
    int n;
    printf("\tWELCOME TO SRTF CALCULATOR\t \n");
    printf("\nEnter the number of process:\n");
    scanf("%d",&n);
    printf("\nEnter the process number:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&process[i]);
    }
    
    printf("\nEnter the burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&burst_time[i]);
    }
    printf("\n Enter the arrival time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arrival_time[i]);
    }
    printf("\nthe table for SRTF is as follow:\n");
    printf("pn \t bt \t at\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\n",process[i],burst_time[i],arrival_time[i]);
    }
    
     calculation(burst_time,arrival_time,process,n);
}
void calculation(int burst_time[],int arrival_time[],int process[],int n){
     int gt[100] = {0};
    int wt[100] = {0};
    int tt[100] = {0};
    int completion_time[100] = {0};
    int waiting_time = 0;
    float avg_waiting_time = 0.0;
    int turnaround_time = 0;
    float avg_turnaround_time = 0.0;
    int current_time = 0;
    int completed = 0;
    int remaining_time[100];
    for (int i = 0; i < n; i++)
    {
        remaining_time[i] = burst_time[i];
    }
    while (completed<n)
    {
        int min_time = INT_MAX;
        int shortest_process = -1;
        for (int  i = 0; i < n; i++)
        {
            if (arrival_time[i]<=current_time && remaining_time[i]<min_time && remaining_time[i]>0)
            {
                min_time = remaining_time[i];
                shortest_process =  i;
            }
        }
        if (shortest_process == -1)
        {
            current_time++;
        }
        else{
            remaining_time[shortest_process]--;
            if (remaining_time[shortest_process] == 0)
            {
                completed++;
                int end_time = current_time + 1;
                tt[shortest_process] = end_time - arrival_time[shortest_process];
                wt[shortest_process] = tt[shortest_process] - burst_time[shortest_process];
                waiting_time += wt[shortest_process];
                current_time = end_time;
                completion_time[shortest_process] = end_time;
                turnaround_time+=tt[shortest_process];
            }
            else{
                current_time++;
            }
        }
        

        
    }
    printf("\n The Table for SRTF is as follows:\n");
        printf("pn \t bt \t at \t wt \t tt \t ct \n");
        for (int i = 0; i < n; i++)
        {
            printf("%d \t %d \t %d \t %d \t %d \t %d \n",process[i],burst_time[i],arrival_time[i],wt[i],tt[i],completion_time[i]);
        }
        avg_turnaround_time  = (float)turnaround_time/n;
        avg_waiting_time =  (float)waiting_time/n;
        printf("\n The Average waiting time is: %f",avg_waiting_time);
        printf("\n The Average turnaround time is: %f",avg_turnaround_time);
    
    
}