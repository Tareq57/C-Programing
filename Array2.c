#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int ara[10000];
    int mx=0;
    for(int i=0;i<n;i++){
        scanf("%d",&ara[i]);
        if(mx<ara[i])
        mx=ara[i];
    }
    while(mx>0)
    {
        for(int i=0;i<n;i++)
        {
            if(ara[i]>=mx)
                printf("** ");
            else
                printf("   ");
        }
        printf("\n");
        mx--;
    }

}
