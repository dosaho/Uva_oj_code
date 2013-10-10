#include<stdio.h>
#include<ctype.h>
int main()
{
    char a[1000];
    int count;
    while(gets(a))
    {
        count=0;
        for(int i=0;a[i]!='\0';i++)   
        {    
            /*printf("%c",a[i]);*/
            if(isalpha(a[i])!=0&&isalpha(a[i+1])==0)
                count++;
        }
        printf("%d\n",count);
    }
}
                        
