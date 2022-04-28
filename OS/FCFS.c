#include<stdio.h>

int main(){
    int n,i;
    printf("Enter the number of processes:\t");
    scanf("%d",&n);


    int arriv[n],burst[n],compl[n],tat[n],wait[n];


    for(i=0;i<n;i++){
    printf("Enter the arrival and burst time of process %d: ",i+1);
    scanf("%d%d",&arriv[i],&burst[i]);
    }

    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arriv[i]>arriv[j]){
                temp=arriv[i];
                arriv[i]=arriv[j];
                arriv[j]=temp;

                temp=burst[i];
                burst[i]=burst[j];
                burst[j]=temp;
            }
        }
    }


    // for(int i=0;i<n;i++) printf("%d ",arriv[i]);

    //This is the code to find completion time of a process
    compl[0]=burst[0]+arriv[0];
    for(int i=1;i<n;i++){
        compl[i]=0;
        if(compl[i-1]<arriv[i]){
            compl[i]+=(arriv[i]-compl[i-1]);
        }
        compl[i]+=compl[i-1]+burst[i];
    }
    //Here comes TAT(Turn Around Time):Completion-Arrival
    for(i=0;i<n;i++){
        tat[i]=compl[i]-arriv[i];
    }
    //Wait time
    for(i=0;i<n;i++){
        wait[i]=tat[i]-burst[i];
    }
    printf("Arrival\tBurst\tCompletion\tTAT\tWait\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t\t%d\t%d\n",arriv[i],burst[i],compl[i],tat[i],wait[i]);
    }
    int sumTat=0,sumComp=0,sumWait=0;
    for(int i=0;i<n;i++){
        sumTat+=tat[i];
        sumComp+=compl[i];
        sumWait+=wait[i];
    }
    
    printf("Average TAT time: %.2f\n",(float)sumTat/n*1.0);
    printf("Average Completion time: %.2f\n",(float)sumComp/n*1.0);
    printf("Average Waiting time: %.2f\n",(float)sumWait/n*1.0);
}