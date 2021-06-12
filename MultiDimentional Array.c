#include<stdio.h>
int A[5][5],B[5][5],row1,col1,row2,col2;
int ok=0,flag=0;
void INA()
{
    scanf("%d %d",&row1,&col1);
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<col1;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    ok=1;
    return ;
}
void INB()
{
    scanf("%d %d",&row2,&col2);
    for(int i=0;i<row2;i++)
    {
        for(int j=0;j<col2;j++)
        {
            scanf("%d",&B[i][j]);
        }
    }
    flag=1;
    return ;
}
void OUT(int mat[][5],int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    return ;
}
void plus(int mat1[][5],int mat2[][5],int r1,int c1,int r2,int c2)
{
    int res[5][5];
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            res[i][j]=mat1[i][j]+mat2[i][j];
        }
    }
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            printf("%d ",res[i][j]);
        }
        printf("\n");
    }
    return ;
}
void minus(int mat1[][5],int mat2[][5],int r1,int c1,int r2,int c2)
{
    int res[5][5];
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            res[i][j]=mat1[i][j]-mat2[i][j];
        }
    }
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            printf("%d ",res[i][j]);
        }
        printf("\n");
    }
    return ;
}
void into(int mat1[][5],int mat2[][5],int r1,int c1,int r2,int c2)
{
    int res[5][5];
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            res[i][j]=0;
            for(int k=0;k<r2;k++)
            {
                res[i][j]+=(mat1[i][k]*mat2[k][j]);
            }
        }
    }
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            printf("%d ",res[i][j]);
        }
        printf("\n");
    }
    return ;
}
void divide(int mat[][5],int r,int c,int n)
{
    double res[5][5];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            res[i][j]=((double)mat[i][j]/(double)n);
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%.2lf ",res[i][j]);
        }
        printf("\n");
    }
}
void getCofactor(int mat[][5],int temp[][5],int p,int q,int n)
{
    int i=0,j=0;
    for (int row=0;row<n;row++)
    {
        for (int col=0;col<n;col++)
        {
            if (row!=p&&col!=q)
            {
                temp[i][j]=mat[row][col];
                j++;
                if (j==n-1)
                {
                    j=0;
                    i++;
                }
            }
        }
    }
}
int determinantOfMatrix(int mat[][5],int n)
{
    int D=0;
    if (n==1)
        return mat[0][0];
    int temp[n][n];
    int sign = 1;
    for (int f=0;f<n;f++)
    {
        getCofactor(mat,temp,0,f,n);
        D+=sign*mat[0][f]*determinantOfMatrix(temp, n - 1);
        sign=-sign;
    }
    return D;
}
void trans(int mat[][5],int r,int c)
{
    int res[5][5];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            res[i][j]=mat[j][i];
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",res[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    while(1)
    {
        char str[101];
    gets(str);
    int k=strlen(str);
    int p=0;
    for(int i=0;i<k;i++)
    {
        if(str[i]==' ')
        {
            p++;
            continue;
        }
        str[i-p]=str[i];
    }
    str[k-p]='\0';
        if(str[0]=='e'||str[0]=='E')
        {
            break;
        }
        if(str[0]=='I'||str[0]=='i')
        {
            if(str[2]=='A'||str[2]=='a')
               {

                INA();
                continue;
               }
            if(str[2]=='B'||str[2]=='b')
            {
                INB();
                continue;
            }
        }
        if(str[0]=='O'||str[0]=='o')
        {
                if(ok==0&&flag==0)
                printf("NO MATRIX FOUND\n");
                else if(flag==0)
                    printf("NO B MATRIX FOUND\n");
                else if(ok==0)
                    printf("NO A MATRIX FOUND\n");
                else
                    if(str[3]=='B'||str[3]=='b')
                      OUT(B,row2,col2);
                   else
                      OUT(A,row1,col1);
        }
        if(str[1]=='+')
        {
                if(ok==0&&flag==0)
                printf("NO MATRIX FOUND\n");
                else if(flag==0)
                    printf("NO B MATRIX FOUND\n");
                else if(ok==0)
                    printf("NO A MATRIX FOUND\n");
                else
                {
                    if(row1!=row2||col1!=col2)
                    {
                        printf("Addition not possible\n");
                    }
                    else
                    {
                        plus(A,B,row1,col1,row2,col2);
                    }
                }
        }
        if(str[1]=='-')
        {
                if(ok==0&&flag==0)
                printf("NO MATRIX FOUND\n");
                else if(flag==0)
                    printf("NO B MATRIX FOUND\n");
                else if(ok==0)
                    printf("NO A MATRIX FOUND\n");
                else
                {
                    if(row1!=row2||col1!=col2)
                    {
                        printf("subtraction not possible\n");
                    }
                    else
                    {
                        if(str[0]=='A'||str[0]=='a')
                        minus(A,B,row1,col1,row2,col2);
                        else
                            minus(B,A,row2,col2,row1,col1);
                    }
                }
        }
        if(str[1]=='*')
        {
                if(ok==0&&flag==0)
                printf("NO MATRIX FOUND\n");
                else if(flag==0)
                    printf("NO B MATRIX FOUND\n");
                else if(ok==0)
                    printf("NO A MATRIX FOUND\n");
                else
                {
                    if((col1!=row2&&(str[0]=='A'||str[0]=='a'))||(col2!=row1&&(str[0]=='B'||str[0]=='b')))
                    {
                        printf("multiplication not possible\n");
                    }
                    else
                    {
                        if(str[0]=='A'||str[0]=='a')
                        into(A,B,row1,col1,row2,col2);
                        else
                            into(B,A,row2,col2,row1,col1);
                    }
                }
        }
        if(str[1]=='/')
        {
            int gh=str[2]-48;

            if(str[0]=='A'||str[0]=='a')
                if(ok==0)
                printf("division not possible\n");
                else
                divide(A,row1,col1,gh);
            else
                if(flag==0)
                printf("division not possible\n");
                else
                divide(B,row2,col2,gh);

        }
        if(str[0]=='D'||str[0]=='d')
        {

            if(str[3]=='A'||str[3]=='a')
            {
                if(row1!=col1||ok==0)
                {
                    printf("determinant is not possible\n");
                }
                else
                {
                   printf("%d\n",determinantOfMatrix(A,row1));
                }
            }
            else
            {
                if(row2!=col2||flag==0)
                {
                    printf("determinant is not possible\n");
                }
                else
                {
                    printf("%d\n",determinantOfMatrix(B,row2));
                }
            }
        }
        if(str[0]=='T'||str[0]=='t')
        {
            if(str[5]=='A'||str[5]=='a')
            {
                if(ok==0)
                    printf("tranversion is not possible\n");
                else
                    trans(A,row1,col1);
            }
            if(str[5]=='B'||str[5]=='b')
            {
                if(flag==0)
                    printf("transversion is not possible\n");
                else
                    trans(B,row2,col2);
            }

        }
        printf("\n");

    }
}
