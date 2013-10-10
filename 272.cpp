#include<stdio.h>
int main()
{
    bool sa=0;
    char a;
    while(scanf("%c",&a)==1)
    {
        if(a=='"'&&sa==0)
        {
            printf("``");
            sa=1;
        }
        else if(a=='"'&&sa==1)
        {
            printf("''");
            sa=0;
        }
        else
            printf("%c",a);
    }
}
