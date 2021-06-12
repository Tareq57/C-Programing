#include<stdio.h>
int ara[35],check[35],n;
void dfs(int p)
{
    if(check[n]==1)
        return ;
    if(p-ara[p]>0&&check[p-ara[p]]==0)
    {
        check[p-ara[p]]=1;
        dfs(p-ara[p]);
    }
    if(p+ara[p]<=n&&check[p+ara[p]]==0)
    {
        check[p+ara[p]]=1;
        dfs(p+ara[p]);
    }
    return ;

}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&ara[i]);
    }
    dfs(1);
    if(check[n]==1)
        printf("YES");
    else
        printf("NO");

}
