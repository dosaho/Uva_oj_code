#include<stdio.h>
#include<math.h>
int main()
{
    int st=0,pst=1,std;
    float R[10][5]={0},a,b,r;
    char ch;
    while(scanf(" %s",&ch)!=EOF)
    {
        if(ch=='r')
        {
            R[st][0]='r';
            for(int i=1;i<5;i++)
                scanf("%f",&R[st][i]);
        }
        if(ch=='c')
        {
            R[st][0]='c';
            for(int i=1;i<4;i++)
                scanf("%f",&R[st][i]);
        }
        else if(ch=='*')
            break;
        st++;
    }
    /*for(int i=0;i<10;i++)
    {
        for(int j=0;j<5;j++)
            printf("%f ",R[i][j]);
        printf("\n");
    }*/
    while(scanf("%f%f",&a,&b)!=EOF)
    {
        
        if(a>=9999.9 && b>=9999.9)
            break;
        std=0;
        for(int i=0;i<=st;i++)
        {
            if(R[i][0]=='r')
            {
                if(a>R[i][1]&&a<R[i][3]&&b<R[i][2]&&b>R[i][4])
                {
                    printf("Point %d is contained in figure %d\n",pst,i+1);
                    std=1;
                }
            }
            else if(R[i][0]=='c')
            {
                r=sqrt((a-R[i][1])*(a-R[i][1])+(b-R[i][2])*(b-R[i][2]));
                if(r<R[i][3])
                {
                    printf("Point %d is contained in figure %d\n",pst,i+1);
                    std=1;
                }
            }
        }
        if(std==0)
            printf("Point %d is not contained in any figure\n",pst);
        pst++;
    }        
}
