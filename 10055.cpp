#include<stdio.h>
#include<stdlib.h>
int main()
{
    long long a,b;
    while(scanf("%lld%lld",&a,&b)!=EOF)
    {
        if(a>b)
            printf("%lld\n",a-b);
        else 
            printf("%lld\n",b-a);
    }
}
    
