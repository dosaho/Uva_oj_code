#include<stdio.h>
void sort(int x[10000],int y, int z);
int main()
{
    int A[10000],step=0,num;
    while(scanf("%d",&num)!=EOF)
    {
        step++;
        if(step==1)
            A[0]=num;
        else
            sort(A,step,num);
        if(step%2==1)
            printf("%d\n",A[(step+1)/2-1]);
        else
            printf("%d\n",(A[step/2-1]+A[step/2])/2);
    }
}
        




void sort(int x[10000],int y,int z)
{
     int j,i; 
     for(i=0;i<y-1;i++)
     {
         if(z<x[i])
             break;
     }
     for(j=y-1;j>i;j--)
         x[j]=x[j-1];
     x[i]=z;
}
