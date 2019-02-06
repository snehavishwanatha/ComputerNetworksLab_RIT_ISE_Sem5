#include<stdio.h>
struct node
{
    unsigned dist[20];
    unsigned from[20];
}right[10];
int main()
{
    int cost[20][20];
    int n,i,j,k,count=0;
    printf("\nEnter the number of n : ");
    scanf("%d",&n);//Enter the n
    printf("\nEnter the cost matrix :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
            right[i].dist[j]=cost[i][j];
            right[i].from[j]=j;
        }
    }
        do
        {
            count=0;
            for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            for(k=0;k<n;k++)
                if(right[i].dist[j]>cost[i][k]+right[k].dist[j])
                {
                    right[i].dist[j]=right[i].dist[k]+right[k].dist[j];
                    right[i].from[j]=k;
                    count++;
                }
        }while(count!=0);
        for(i=0;i<n;i++)
        {
            printf("\n\n For router %d\n",i+1);
            for(j=0;j<n;j++)
            {
                printf("\t\nnode %d via %d Distance %d",j+1,right[i].from[j]+1,right[i].dist[j]);
            }
        }
    printf("\n\n");

}

