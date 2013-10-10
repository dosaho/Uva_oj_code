#include<stdio.h>
int main()
{
    int sum,block[100],n,check,set=1;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        check=0;
        if(n==0)
            break;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&block[i]);
            sum+=block[i];
        }
        sum/=n;
        for(int i=0;i<n;i++)
        {
            if(block[i]>sum)
                check=check+block[i]-sum;
        }
        printf("Set #%d\n",set);
        printf("The minimum number of moves is %d.\n\n",check);
        set++;
    }
}
