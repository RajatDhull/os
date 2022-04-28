#include<stdio.h>

struct process{
    int arriv,burst,compl,wait,tat,priority;
};

int main(){
    printf("Enter the number of processes:\t");
    int n;scanf("%d",&n);
    struct process p1[n];
    for(int i=0;i<n;i++){
        printf("Enter the arrival and burst time and priority of process %d:\t",i+1);
        scanf("%d%d%d",&p1[i].arriv,&p1[i].burst,&p1[i].priority);
    }
    int currtime=0;
    //here sorting is done on basis of arrival time
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
    currtime+=p1[0].arriv;
    for(int i=0;i<n;i++){
        //finding next min burst
        int mostprior=0;
        int index=i;
        for(int j=i;j<n;j++){
            if((currtime>=p1[j].arriv)&&(p1[j].priority>mostprior)){
                mostprior=p1[j].priority;
                index=j;
            }
        }
        struct process temp=p1[index];
        p1[index]=p1[i];
        p1[i]=temp;

        //Calculating completion time for the current process and updating current time
        // p1[i].compl=currtime+p1[i].burst;
        // currtime+=p1[i].burst;
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
        printf("%d\t%d\t%d\t\t%d\t\t%d\n",p1[i].arriv,p1[i].burst,p1[i].compl,p1[i].tat,p1[i].wait);
    }
}