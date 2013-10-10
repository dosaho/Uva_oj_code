#include<stdio.h>
#include<string.h>
int main()
{
    int carry,p,i,j;
    char a[10],b[10];
    while((scanf("%s",a)&&scanf("%s",b))!=EOF)
    {
        int c[10]={0},d[10]={0};
        if(strlen(a)==1&&strlen(b)==1&&a[0]=='0'&&b[0]=='0')
            break;
        carry=0;
        
        for(i=10;i>10-strlen(a);i--)
        {    
            c[i]=a[strlen(a)-11+i]-'0';
        }
        for(i=10;i>10-strlen(b);i--)
        {    
            d[i]=b[strlen(b)-11+i]-'0';
        }
        for(i=10;i>=0;i--)
        {
            c[i]+=d[i];
            if(c[i]>=10)
            {
                c[i-1]+=1;
                carry++;
            }
        }   
        if(carry==0)
            printf("No carry operation.\n");
        else if(carry==1)
            printf("1 carry operation.\n");
        else 
            printf("%d carry operations.\n",carry);
    }
}
