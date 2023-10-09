#include<stdio.h>
void calculation(int process[],int burst_time[],int arrival_time[],int n,int time_quantmn);
void main(){
    int process[100];
    int burst_time[100];
    int arrival_time[100];
    int priority[100];
    int n;
    int time_quantmn;
    printf("Ronit Satish Mehta 60009230207\n");
    printf("enter the number of process:\n");
    scanf("%d",&n);
    printf("Enter the Time slice for each process:\n");
    scanf("%d",&time_quantmn);
    printf("enter the process id:");
    for (int i = 0; i < n; i++)
    {
        printf("\t");
        scanf("%d",&process[i]);
    }
    printf("enter the burst time for the given process:");
    for (int i = 0; i < n; i++)
    {
        printf("\t");
        scanf("%d",&burst_time[i]);
    }
    printf("enter the arrival time for the given process:");
    for (int i = 0; i < n; i++)
    {
        printf("\t");
        scanf("%d",&arrival_time[i]);
    }
    printf("the table for SJF is as follows:\n");
    printf("pn \t bt  \t at");
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        printf("%d \t %d  \t %d",process[i],burst_time[i],arrival_time[i]);
    }
    
    calculation( process, burst_time, arrival_time, n,time_quantmn);
    
}
void calculation(int process[],int burst_time[],int arrival_time[],int n,int time_quantmn){
    int gt[100] = {0};
    int temp1;
    int temp2;
    int i = 0;
    int time = 0;
    int remaining_time[100];
    int temp3;
    int wt[100] = {0};
    int tt[100] = {0};
    int completion_time[100] = {0};
    int waiting_time = 0;
    float avg_waiting_time = 0.0;
    int turnaround_time = 0;
    float avg_turnaround_time = 0.0;
    for (int i = 0; i < n; i++)
    {
        remaining_time[i]=burst_time[i];
    }
    
    while (i<n)
    {
        for (int k = 0; k < n; k++)
        {
           if (remaining_time[i]>0)
           {
            if (remaining_time[i]<=time_quantmn)
            {
                time += remaining_time[i];
                remaining_time[i]=0;
                completion_time[i]= time;
                i++;
            }
            else{
                time+=time_quantmn;
                remaining_time[i]-=time_quantmn;
                
            }
            
           }
           
            
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        tt[i]= completion_time[i] - arrival_time[i];
        wt[i]=tt[i] - burst_time[i];
    }
    for ( i = 0; i < n; i++)
    {
        waiting_time+=wt[i];
        turnaround_time+=tt[i];
    }
    avg_turnaround_time = (float)turnaround_time/n;
    avg_waiting_time = (float)waiting_time/n;
    printf("\n the table for Round Robin is as follows:\n");
    printf("pn \t bt \t at \t wt \t tt \t ct");
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        printf("%d \t %d \t %d \t %d \t %d \t %d  ",process[i],burst_time[i],arrival_time[i],wt[i],tt[i],completion_time[i]);
    }
    printf("\nthe avg waiting time is:%f",avg_waiting_time);
    printf("\nthe average turnaround time is:%f",avg_turnaround_time);


}