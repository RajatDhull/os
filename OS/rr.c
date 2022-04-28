#include<stdio.h>

struct process{
    int arriv,tempburst,burst,compl,wait,tat;
};

int main(){
    printf("Enter the number of processes:\t");
    int n;scanf("%d",&n);
    struct process p1[n];
    for(int i=0;i<n;i++){
        printf("Enter the arrival and burst time of process %d:\t",i+1);
        scanf("%d%d",&p1[i].arriv,&p1[i].burst);
    }
    printf("Enter the time quantum:\t");
    int t;scanf("%d",&t);
    for(int i=0;i<n;i++) p1[i].tempburst=p1[i].burst;
    //This is sorting according to arrival time using bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p1[j].arriv >p1[j+1].arriv)
            {
                struct process p2=p1[j];
                p1[j]=p1[j+1];
                p1[j+1]=p2;
            }
        }
    }


    int currtime=0;
    int max=0;
    //this will check that which process will be the last...means that which process will remain till last so that we can count total cycles
    for(int i=0;i<n;i++){
        if(p1[i].burst+p1[i].arriv>max) max=p1[i].burst+p1[i].arriv;
    }
    int cycles;
    if(max%t==0) cycles=max/t;
    if(max%t!=0) cycles=max/t+1;

    for(int i=0;i<cycles;i++){
        for(int j=0;j<n;j++){
            if(currtime<p1[j].arriv) break;
            else if(p1[j].burst>=t){
                p1[j].burst-=t;
                currtime+=t;
                if(p1[j].burst==0) p1[j].compl=currtime;
            }
            else if(p1[j].burst>0&&p1[j].burst<t){
                currtime+=p1[j].burst;
                p1[j].burst=0;
                p1[j].compl=currtime;
            }
        }
    }
    //TAT and Waiting time
    for(int i=0;i<n;i++){
        p1[i].tat=p1[i].compl-p1[i].arriv;
        p1[i].wait=p1[i].tat-p1[i].tempburst;
    }
    printf("Arrival\tBurst\tCompletion\tTAT\t\tWaiting\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t\t%d\t\t%d\n",p1[i].arriv,p1[i].tempburst,p1[i].compl,p1[i].tat,p1[i].wait);
    }
}