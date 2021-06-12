#include<stdio.h>
int main()
{
    char s1[5000],s2[500],s3[11];
    gets(s1);
    gets(s2);
    gets(s3);
    int n=strlen(s1);
    int k=strlen(s2);
    int l=strlen(s3);
    int cnt=0;
    for(int i=0;i<=n-k;i++)
    {
       int ok=1;
       for(int j=i;j-i<k;j++)
       {
           if(s1[j]!=s2[j-i])
           {
               ok=0;
               break;
           }
       }
       if(ok)
       {
             int p=k-l;
             if(p>0)
               for(int j=i+k;j<n;j++)
               {
                   s1[j-p]=s1[j];
               }
             else
             {
                 for(int j=n-1;j>i+k-1;j--)
                 {
                     s1[j-p]=s1[j];
                 }
             }
               s1[n-p]='\0';
               n=strlen(s1);
               for(int j=i;j-i<l;j++)
               {
                   s1[j]=s3[j-i];
               }
               i=i+k;
       }
    }
    puts(s1);
}
