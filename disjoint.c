#include<stdio.h>
#include<stdlib.h>
struct DisjSet
{
    int parent[10];
    int rank[10];
    int n;
}dis;

void makeSet()
{
    int i;
    for(i=0;i<dis.n;i++)
    {
        dis.parent[i]=i;
        dis.rank[i]=0;
    }
}
void displaySet()
{
    int i;
    printf("\nParent Array:\n");
    for(i=0;i<dis.n;i++)
    {
        printf("%d",dis.parent[i]);
    }
    printf("\nRank Array:\n");
    for(i=0;i<dis.n;i++)
    {
        printf("%d",dis.rank[i]);
    }
    printf("\n");
}

int find(int x)
{
    if(dis.parent[x] != find(dis.parent[x]))
    {
        dis.parent[x] = find(dis.parent[x]);
    }
    return dis.parent[x];
}

void Union(int x, int y)
{
    int xset = find(x);
    int yset = find(y);

    if(xset == yset)
    {
        return;
    }
    if(dis.rank[xset] < dis.rank[yset])
    {
        dis.parent[xset] = yset;
        dis.rank[xset] = -1;
    }
    else if(dis.rank[xset] > dis.rank[yset])
    {
        dis.parent[yset] = xset;
        dis.rank[yset] = -1;
    }
    else
    {
        dis.parent[yset] = xset;
        dis.rank[xset] = dis.rank[xset] + 1;
        dis.rank[yset] = -1;
    }
}

void main()
{
    int n,x,y,ch,wish;
    printf("How many elements?");
    scanf("%d",&dis.n);
    makeSet();

    printf("\nMENU\n");
    printf("\n1.Union \n2.Find \n3.Display\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    do
    {
        switch(ch)
        {
            case 1:
            printf("Enter the elements to perform union:");
            scanf("%d%d",&x,&y);
            Union(x,y);
            break;

            case 2:
            printf("Enter the elements to check if connected components:");
            scanf("%d%d",&x,&y);

            if(find(x) == find(y))
            printf("Connected components\n");
            else
            printf("Not connected components\n");
            break;

            case 3:
            displaySet();
            break;
        }    
        printf("Do you wish to continue(1/0)?:");
        scanf("%d",&wish);
    }while(wish == 1);
}