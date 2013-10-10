#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    unsigned int N,done,temp,step,z,c,time=0,n;
    int o,j,i;
    while(scanf("%u",&n)!=EOF)
    {
        
        time=0;
        while(time!=n&&scanf("%u",&N)!=EOF)
        {
            
            
            done=0;
            step=0;
            while(done==0)
            {
                
                char a[40]={0};
                temp=N;
                for(i=0;temp!=0;i++)
                {
                    a[i]=temp%10;
                    temp/=10;
                }
                
                for(j=0;j<i;j++)
                {
                    c=1;
                    for(o=0;o<=i-j-2;o++)
                    {    
                        c*=10;
                    }
                    temp+=a[j]*c;
                
                }
                
                N+=temp;
                
                step+=1;
                temp=N;
                for(i=0;temp!=0;i++)
                {
                    a[i]=temp%10;
                    temp/=10;
                }
                if(i%2==0)
                {
                    z=0;
                    for(j=0;j<i/2;j++)
                    {
                        if(a[j]!=a[i-j-1])
                        {
                            z=1;
                            break;
                        }
                    }
                }
                else if(i%2==1)
                {
                    z=0;
                    for(int j=0;j<(i+1)/2;j++)
                    { 
                        if(a[j]!=a[i-j-1])
                        {
                            z=1;
                            break;
                        }
                    }
                }
                if(z==0)
                {
                    done=1;
                    printf("%u %u\n",step,N);
                }
            }
        time++;
        }
    }
}
