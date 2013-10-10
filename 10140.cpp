#include<iostream>
#include<cmath>
#include <string.h>
void sieve(int l,int r,char primet[1000010]);
int prime[1000000];
using namespace std;
int main()
{
    int m,Num;
    char primet[1000010];
    //freopen("1.out","w",stdout);
    int l,r,sm,sap=0,ini,temp,k;
    while(cin>>l>>r)
    {
        memset(primet,1,1000010);
        memset(prime,1,1000000);
        sieve(l,r,primet);
        int al=0,ar=0,bl=0,br=0,min=1,max=1;
        k=0;
        for(int i=0;i<r-l+1;i++)
        {
            if(primet[i]==1&&l+i!=1)
            {
                prime[k]=i;
                k++;
            }            
        }
        if(k>=2)
        {
            min=prime[1]-prime[0];
            max=prime[1]-prime[0];
            al=prime[0];ar=prime[1];
            bl=prime[0];br=prime[1];
        }
        for(int i=1;i<k-1;i++)
        {
            temp=prime[i+1]-prime[i];
            if(temp>max)
            {
                max=temp;
                al=prime[i];ar=prime[i+1];
            }
            if(temp<min)
            {
                min=temp;
                bl=prime[i];br=prime[i+1];
            }
                  
        }
        if(k>=2)
            cout<<bl+l<<","<<br+l<<" are closest, "<<al+l<<","<<ar+l<<" are most distant."<<endl;
        else
            cout<<"There are no adjacent primes."<<endl;
    }
}
    
void sieve(int a,int b,char c[1000010])
{
     int k=0,m;
     m=(int)(sqrt(b)+0.001);
     for(int i=2;i<=m;i++)
     {
         if(a%i==0)
             k=0;
         else
             k=i-a%i;
         for(int j=k;j<=b-a;j=j+i)
         {
             if((a+j)/i>1)
                 c[j]=0;    
         }
     }
}
