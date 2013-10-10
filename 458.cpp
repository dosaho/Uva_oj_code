#include<stdio.h>
int main()
{
    char a;
    while((a=getchar())!=EOF)
    {
        if(a!='\n')
        {    
            a-=7;
        }
        printf("%c",a);
    }
}
