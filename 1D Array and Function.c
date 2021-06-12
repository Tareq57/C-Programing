#include<stdio.h>
int check_prime(long long  int n)
{
    int ok=1;
    for(int i=2;i*i<=n;i++)
    {
        if(!(n%i))
        {
            ok=0;
            break;
        }
    }
    return ok;
}
long long int factorial(int n)
{
    long long int sum=1;
    for(int i=1;i<=n;i++)
    {
        sum*=((long long int)i);
    }
    return sum;
}
int main()
{
    int n;
    scanf("%d",&n);
    long long int p=3,q=2;
    long long int sum=0;
    while(n--)
    {
        while(!check_prime(p))
            p++;
        long long int res=1;
        long long int r=q,w=p;
        if(w-r<r)
            r=w-r;
        long long int fact=factorial(r);
        for(int i=0;i<r;i++)
        {
            res*=(w-(long long int)i);
        }
        sum+=(res/fact);
        q=p;
        p++;
    }
    printf("%lld",sum);
}
