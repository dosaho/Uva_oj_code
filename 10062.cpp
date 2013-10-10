#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int check(int x[300]);
int main()
{
    char te[2000];
    int sa=0,num;
    while(gets(te))
    {
        if(sa!=0)
            printf("\n");
        int pr[300]={0};
        for(int i=0;te[i]!='\0';i++)
            pr[te[i]]++;
        for(int i=0;i<300;i++)
        {
            if(pr[i]==0)
                pr[i]=2000;
        }
        while(check(pr)!=0)
        {
            sa=pr[299];
            for(int i=298;i>=0;i--)
            {
                if(pr[i]<sa)
                {
                    sa=pr[i];
                    num=i;
                }
            }
            printf("%d %d\n",num,sa);
            pr[num]=2000;
        }
        
    }
}
        
int check(int x[300])
{
    int ch=0;
    for(int i=0;i<300;i++)
    {
        if(x[i]!=2000)
        {
            ch=1;
            break;
        }
    }
    return ch;
}
