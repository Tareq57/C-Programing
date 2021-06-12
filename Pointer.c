#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* construct(char* s,char* t,int p,int q)
{
    char* res;
    res=(char*) malloc((p)*sizeof(char));
    for(int i=0;i<p;i++)
    {
        int ok=1;
        for(int j=0;j<q;j++)
        {
            if(*(s+i)==(*(t+j)))
               {
                   ok=0;
                   break;
               }
        }
        if(ok==1)
        {
            *res=*(s+i);
            res++;
        }
    }
    return res;
}
int main()
{
    char s[100],t[100];
    gets(s);
    gets(t);
    int p=strlen(s),q=strlen(t);
    char* res;
    res=(char*)malloc((p)*(sizeof(char)));
    res=construct(s,t,p,q);
    int k=strlen(res);
    for(int i=0;i<k;i++)
    {
        printf("%c",*(res+i));
    }

}
