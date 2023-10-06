#include<stdio.h>
void waiting_time(int process[],int bursttime[],int n,int arrivaltime[]);
void main(){
    int process[100];
    int burst_time[100];
    int arrival_time[100];
    int n;
    printf("Ronit Satish Mehta SAP ID: 60009230207 \n");
    printf("enter the number of the process:");
    scanf("%d",&n);
    printf("enter the name of the process:\n");
    for(int i=0;i<n;i++){
         scanf("%d",&process[i]);
    }
    printf("enter the burst time of the process:\n");
    for(int i =0;i<n;i++){
        scanf("%d",&burst_time[i]);
    }
    printf("Enter Arrival time of the process:\n");
    for (int i = 0; i < n; i++)
    {
       scanf("%d",&arrival_time[i]);
    }
    printf("the table for FCFS is as follows:\n");
    printf("pn \t bt \t at");
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        printf("%d \t %d \t %d ",process[i],burst_time[i],arrival_time[i]);
    }
    waiting_time( process, burst_time, n,arrival_time);   
}
void waiting_time(int process[],int bursttime[],int n,int arrivaltime[]){
  int gt[100] = {0};
    int temp1;
    int temp2;
    int temp3;
    int wt[100] = {0};
    int tt[100] = {0};
    int completion_time[100] = {0};
    int waiting_time = 0;
    float avg_waiting_time = 0.0;
    int turnaround_time = 0;
    float avg_turnaround_time = 0.0;
for (int i = 0; i < n+1; i++)
{
   gt[i + 1] = gt[i] + bursttime[i];
}
for (int i = 0; i < n; i++)
{if (i == 0) {
            completion_time[i] =  bursttime[i];
        } else {
            completion_time[i] = completion_time[i - 1] + bursttime[i];
        }

}
for (int i = 0; i < n; i++)
{
    tt[i] = completion_time[i] - arrivaltime[i];
}
for (int i = 0; i < n; i++)
{
    turnaround_time = turnaround_time + tt[i];
}
for (int i = 0; i < n; i++)
{
   wt[i] = tt[i] - bursttime[i];
}
for (int i = 0; i < n; i++)
{
    waiting_time = waiting_time + wt[i];
}

printf("\n the gantt chart is as follows:\n");
for (int i = 0; i < n; i++)
{
    printf("%d \t",process[i]);
}
printf("\n");
for (int i = 0; i <= n; i++)
{
    printf("%d \t",gt[i]);
}

 printf("\n the table for FCFS is as follows:\n");
 printf("pn \t bt \t at \t wt \t tt \t ct");
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        printf("%d \t %d \t %d \t %d \t %d \t %d  ",process[i],bursttime[i],arrivaltime[i],wt[i],tt[i],completion_time[i]);
    }
    avg_turnaround_time = (float)turnaround_time/n;
    avg_waiting_time = (float)waiting_time/n;
    printf("\nThe Average waiting time is: %f", avg_waiting_time);
    printf("\nThe Average TurnAround time is:%f",avg_turnaround_time);
}

