u/ e9 1ru.45k4ek
22l42u3@@??#include<stdio.h>
int main()
{
    int in1,in2,temp,step,maxcycle,sa,i,ci1,ci2;
    while(scanf("%d %d",&in1,&in2)==2)
    {
        ci1=in1;
        ci2=in2;          
        if(in1>in2)
        {
            temp=in1;
            in1=in2;
            in2=temp;
        }
        maxcycle=0;
        for(i=in1;i<=in2;i++)
        {
            step=1;
            sa=i;
            while(sa!=1)
            {
                if(sa%2==0)
                    sa/=2;
                else 
                    sa=3*sa+1;
                step++;
            }
            if(step>maxcycle)
                maxcycle=step;
        }
        printf("%d %d %d\n",ci1,ci2,maxcycle);
    }
}
