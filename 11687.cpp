#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000010];
    while(scanf("%s",a)!=EOF)
    {
          if(a[0]=='E')
              break;
          else if(strlen(a)==1&&a[0]=='1')
              printf("1\n");
          else if(strlen(a)==1)
              printf("2\n");
          else if(strlen(a)<10)
              printf("3\n");
          else 
              printf("4\n");
    }
}
