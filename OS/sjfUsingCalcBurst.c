#include<stdio.h>

struct process{
    int arriv,burst,assumedBurst,compl,wait,tat;
};

int main(){
    printf("Enter the number of processes:\t");
    int n;scanf("%d",&n);
    struct process p1[n];
    for(int i=0;i<n;i++){
        printf("Enter the arrival time of process %d:\t",i+1);
        scanf("%d",&p1[i].arriv);
    }
    printf("Enter the burst of 1st process:\t");scanf("%d",&p1[0].burst);
    int t;
    printf("Enter value of assumed burst for process 1:\t");scanf("%d",&p1[0].assumedBurst);
    for(int i=1;i<n;i++){
        p1[i].burst=(p1[i-1].assumedBurst+p1[i-1].burst)/2;
    }
    int currtime=0;
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

    //Completion time logic
    // p1[0].compl=p1[0].burst+p1[0].arriv;
    currtime+=p1[0].arriv;
    for(int i=0;i<n;i++){
        
        //finding next min burst
        int minburst=9999;
        int index=i;
        for(int j=i;j<n;j++){
            if((currtime>=p1[j].arriv)&&(p1[j].burst<minburst)){
                minburst=p1[j].burst;
                index=j;
            }
        }
        struct process temp=p1[index];
        p1[index]=p1[i];
        p1[i]=temp;

        //Calculating completion time for the current process and updating current time
        if(p1[i].arriv<=currtime)
        {p1[i].compl=currtime+p1[i].burst;
        currtime+=p1[i].burst;}
        if(p1[i].arriv>currtime){
            p1[i].compl=p1[i].arriv+p1[i].burst;
            currtime=p1[i].arriv+p1[i].burst;
        }
    }

    //TAT and Waiting time
    for(int i=0;i<n;i++){
        p1[i].tat=p1[i].compl-p1[i].arriv;
        p1[i].wait=p1[i].tat-p1[i].burst;
    }
    printf("Arrival\tBurst\tCompletion\tTAT\t\tWaiting\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",p1[i].arriv,p1[i].burst,p1[i].compl,p1[i].tat,p1[i].wait);
    }
}