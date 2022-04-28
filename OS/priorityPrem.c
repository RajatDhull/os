#include<stdio.h>

struct process{
    int arriv,burst,compl,wait,tat,tempburst,priority;
};

int main(){
    printf("Enter the number of processes:\t");
    int n;scanf("%d",&n);
    struct process p1[n];
    for(int i=0;i<n;i++){
        printf("Enter the arrival and burst time and priority of process %d:\t",i+1);
        scanf("%d%d%d",&p1[i].arriv,&p1[i].burst,&p1[i].priority);
    }
    for(int i=0;i<n;i++) p1[i].tempburst=p1[i].burst;
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
    int sum=0;
    for(int i=0;i<n;i++) sum+=p1[i].burst;
    sum+=p1[0].arriv;

    if(sum<p1[n-1].arriv+p1[n-1].burst) sum=p1[n-1].arriv+p1[n-1].burst;
    for(int i=0;i<=sum;i++){
        int mostprior=0,flag=0,pnum=0;
        for(int j=0;j<n;j++){
            if(p1[j].burst>0&&currtime>=p1[j].arriv&&mostprior<p1[j].priority) {mostprior=p1[j].priority;flag=1;pnum=j;}
        }
        if(!flag) currtime++;
        if(flag){
            p1[pnum].burst--;
            currtime++;
            if(p1[pnum].burst==0) p1[pnum].compl=currtime;
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