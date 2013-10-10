#include<stdio.h>
int main()
{
    float ans,H,M;
    char a;
    while(scanf("%f%c%f",&H,&a,&M)!=EOF)
    {
        if(H==0&&M==0)
            break;
        ans=30*H+M/2-6*M;
        if(ans<0)
            ans=-ans;
        if(ans>=360)
            ans=0;
        else if(ans>=180)
            ans=360-ans;
        printf("%.3f\n",ans);
    }
}
