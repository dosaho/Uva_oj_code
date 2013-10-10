#include<stdio.h>
int main()
{
    unsigned long long int N;
    while(scanf("%ld",&N)!=EOF)
    {
        N=(1+N)*(N+1)/4;
        N=6*N-9;
        printf("%ld\n",N);
    }
}
