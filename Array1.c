#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int ara[100000]={0},res[100000];
    int cnt=0,elem=0;
    while(n--)
    {
        int num;
        scanf("%d",&num);
        ara[num+10000]++;
        if(ara[num+10000]>cnt)
        {
            res[0]=num;
            elem=1;
            cnt=ara[num+10000];
        }
        else if(ara[num+10000]==cnt)
        {
            res[elem]=num;
            elem++;
        }
        printf("Most frequent number= %d",res[0]);
        for(int i=1;i<elem;i++)
            printf(",%d",res[i]);
        printf("\n");

    }
}
