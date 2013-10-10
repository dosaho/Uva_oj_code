#include<stdio.h>
int main()
{
    int st=0,pst=1,std;
    float R[10][4]={0},a,b;
    char ch;
    while(scanf(" %s",&ch)!=EOF)
    {
        if(ch=='r')
        {
            for(int i=0;i<4;i++)
                scanf("%f",&R[st][i]);
        }
        else if(ch=='*')
            break;
        st++;
    }
    while(scanf("%f%f",&a,&b)!=EOF)
    {
        
        if(a>=9999.9 && b>=9999.9)
            break;
        std=0;
        for(int i=0;i<=st;i++)
        {
            if(a>R[i][0]&&a<R[i][2]&&b<R[i][1]&&b>R[i][3])
            {
                printf("Point %d is contained in figure %d\n",pst,i+1);
                std=1;
            }
        }
        if(std==0)
            printf("Point %d is not contained in any figure\n",pst);
        pst++;
    }        
}
