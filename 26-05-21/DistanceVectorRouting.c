#include<stdio.h>

struct node
{
    unsigned dist[20];
    unsigned from[20];
}rt[10];

int main()
{
    int costmat[20][20];
    int nodes,i,j,k,count=0;
    printf("\nEnter the number of nodes : ");
    scanf("%d",&nodes);//Enter the nodes
    printf("\nEnter the cost matrix : \n");//Enter 99 if path doesn't exist
    for(i=0;i<nodes;i++)
    {
        for(j=0;j<nodes;j++)
        {
            scanf("%d",&costmat[i][j]);
            costmat[i][i]=0;
            rt[i].dist[j]=costmat[i][j];//initialise the distance equal to cost matrix
            rt[i].from[j]=j;
        }
    }
    do
    {
        count=0;
        for(i=0;i<nodes;i++)
            for(j=0;j<nodes;j++)
	        for(k=0;k<nodes;k++)
        	    if(rt[i].dist[j]>costmat[i][k]+rt[k].dist[j])
                    {
	                //We calculate the minimum distance
                        rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
                        rt[i].from[j]=k;
                        count++;
                    }
     }while(count!=0);
     for(i=0;i<nodes;i++)
     {
         printf("\n\n\n For router %d\n",i+1);
         printf("\nNode\tCost\tNext Hop\n");
         for(j=0;j<nodes;j++)
         {
            printf("\t\n %d\t%d\t%d ",j+1,rt[i].dist[j],rt[i].from[j]+1);
         }
     }
     printf("\n\n");
     return 0;
}
