#include<stdio.h>
int main()
{
    int n,A,F,step;
    while(scanf("%d",&n)!=EOF)
    {
        step=1;
        while(scanf("%d%d",&A,&F)!=EOF)
        {
            for(int t=0;t<F;t++)
            {
                for(int i=1;i<=A;i++)
                {
                    for(int j=0;j<i;j++)
                        printf("%d",i);
                    printf("\n");
                }
                for(int i=A-1;i>0;i--)
                {
                    for(int j=0;j<i;j++)
                        printf("%d",i);
                    printf("\n");
                }
                if(step!=n || t+1!=F)
                    printf("\n");
            }
            if(step==n)
                break;
            step++;
        }
    }
}
                        
