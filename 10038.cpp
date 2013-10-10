#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,a,b,sa,check[3010];
    while(scanf("%d",&n)!=EOF)
    {
        int check[3010]={0};
        sa=0;
        if(n==1)
        {
            sa=0;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);
                if(i!=0)
                {
                    if(abs(a-b)>=n||abs(a-b)<1)
                        sa=1;
                    else
                        check[abs(a-b)]=1;
                }
                b=a;
        }
        if(sa==0)
        {
            for(int i=1;i<n;i++)
            {
                if(check[i]!=1)
                {
                    sa=1;
                    break;
                }
            }
        }
        if(sa==0)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
}
