#include<stdio.h>
int check(int n)
{
    int sum=1;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
           if(i*i==n)
           {
               sum+=i;
               break;
           }
           else
            sum+=(i+(n/i));
        }
    }
    if(sum==n)
        return 1;
    else
        return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=6;i<=n;i++)
    {
        int p=check(i);
        if(p)
        sum+=i;
    }
    printf("%d",sum);
}
