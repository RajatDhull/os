#include <stdio.h>

int isZero(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
            return 0;
    }
    return 1;
}

int main()
{

    int n;
    printf("Enter total number of recource types:\t");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter number of instances of resource %d\t", (i + 1));
        scanf("%d", &arr[i]);
    }

    int p;
    printf("Enter total number of processes:\t");
    scanf("%d", &p);
    int alloc[p][n];
    printf("Enter the allocated resources rowwise:\n");
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    // getting n resources
    // int avail[n];
    // printf("Enter the resources available:\n");
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &avail[i]);
    // }

    // this is for the total used resources
    int used[n];
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < p; j++)
        {
            sum += alloc[j][i];
        }
        used[i] = sum;
    }
    // for(int i=0;i<n;i++){
    //     printf("%d ",used[i]);
    // }
    int avail[n];
    for (int i = 0; i < n; i++)
    {
        avail[i] = arr[i] - used[i];
    }

    int max[p][n];
    printf("Enter the max resources needed rowwise:\n");
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    int need[p][n];
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < n; j++)
        {
            need[i][j] = (max[i][j] - alloc[i][j]);
        }
    }
    int curr = 0;

    int mark[p];
    for (int i = 0; i < p; i++)
    {
        mark[i] = 0;
    }

    int sequence[p];

    for (int k = 0; k < p; k++)
    {
        for (int i = 0; i < p; i++)
        {
            if (mark[i] == 0)
            {
                int flag = 0;
                for (int j = 0; j < n; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }
                // printf("Flag is %d\n",flag);
                if (flag == 0)
                {
                    sequence[curr] = i;
                    curr++;
                    mark[i] = 1;
                    for(int r=0;r<n;r++){
                        avail[r]+=alloc[i][r];
                    }
                }
            }
        }
    }

    int flag=0;
    for(int i=0;i<p;i++){
        // printf("%d ",mark[i]);
        if(mark[i]==0){
            flag=1;
        }
    }

    if(flag){
        printf("All processes are not allocated resources, hence system is not safe\n");
    }
    else{
        printf("The sequence is:\n");
        for(int i=0;i<p;i++){
            printf("P%d -> ",sequence[i]);
        }
    }

}
