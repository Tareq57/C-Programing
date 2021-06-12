//problem-->1
#include<stdio.h>
int main()
{
  int n,x;
  scanf("%d %d",&n,&x);
  int cnt=0;
   int res=0;
  int b=1;
  while(n!=0)
  {
      res+=((n%10)*b);
      b*=x;
      n/=10;
  }
  printf("%d",res);

}

/*problem--->2
#include<stdio.h>
int main()
{
    int n,res=0;
    scanf("%d",&n);
    int cnt=0;
    int p=n;
    while(n!=0)
    {
        n/=10;
        cnt++;
    }
    int man=1;
    for(int i=1;i<cnt;i++)
    {
        man*=10;
    }
    while(p!=0)
    {
        res+=((p%10)*man);
        man/=10;
        p/=10;
    }
    if(res==1)
    {
        printf("No");
        return 0;
    }
    int ok=1;
    for(int i=2;i*i<=res;i++)
    {
        if(res%i==0)
        {
            ok=0;
            break;
        }
    }
    if(ok)
        printf("Yes");
    else
        printf("No");
}
*/

