#include<iostream>
#include <stdio.h>
using namespace std;
int main(void)
{
    int N;
    cin>>N;
        for(int u=0;u<N;u++)
        {
            int m,k,check,x,tag,i,j;
            long long max,min,mid,sum;
            int p[501]={0};
            max=0;
            min=0;
            cin>>m>>k;
            x=0;
            for(j=0;j<m;j++)
            {
                cin>>p[j];
                if(p[j]>min)
                    min=p[j];
                max+=p[j];
            }
            mid=(max+min)/2;
            while(mid!=min)
            {
                sum=0;
                check=0;
                for(i=0;i<m;i++)
                {
                    if(sum+p[i]>mid)
                    {
                        check++;
                        sum=0;
                    }
                    sum+=p[i];
                }
                if(check>=k)
                    min=mid;
                else
                    max=mid;
                mid=(max+min)/2;
            }
            int pp[501]={0};
            sum=0;
            tag=k-1;
            if(tag==m-1)
            {
                while(tag>=0)
                    {   
                        pp[tag]=1;
                        tag--;
                    }
            }
            else
            {
                for(i=m-1;i>=0;i--)
                {
                    if(tag<=0)
                        break;
                    else if(max<sum+p[i])
                    {
                        tag--;
                        sum=0;
                        pp[i]=1;
                   
                   
                    }
                    else if(tag==i)
                    {
                        do
                        {   
                            pp[tag-1]=1;
                            tag--;
                        }while(tag>=0);
                }
                sum+=p[i];
                }
            }
            for(i=0;i<m;i++)
            {
                cout<<p[i];
                if(i!=m-1)
                   cout<<" "; 
                if(pp[i]==1&&i!=m-1)
                    cout<<'/'<<" ";
            }
            cout<<endl;                
        }
}   
