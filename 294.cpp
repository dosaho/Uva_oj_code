#include<iostream>
#include<cmath>
#include <string.h>
using namespace std;
int main()
{
    int m,Num;
    char primet[50001];
    memset(primet,1,50000);
    m=(int)(sqrt(1000000000)+0.001);
    //freopen("1.out","w",stdout);
    for(int i=2;i<m;i++)
    {
        if(primet[i]==1)
        {
            for(int j=i*2;j<m;j=j+i)
            {
                primet[j]=0;
            }
        }
    }
    int k=0,prime[4000];
    for(int i=2;i<m;i++)
    {
        if(primet[i]==1)
        {
            prime[k]=i;
            k++;
        }
        
    }
    
    cin>>Num;
    int l,r,sm,sap=0,ini,temp;
    for(int p=0;p<Num;p++)
    {
        cin>>l>>r;
        sm=(int)(sqrt(r)+0.001);
        int save[10][10005];
        memset(save,0,sizeof(save));
        /*system("pause");
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                cout<<save[i][j]<<" ";
            }
            cout<<endl;
        }*/
        for(int i=l;i<=r;i++)
        {
            save[0][i-l]=i;
            save[1][i-l]=1;
        }
        /* for(int j=0;j<r-l+1;j++)
            {
                cout<<save[0][j]<<" ";
            }
            cout<<endl;
            system("pause");*/
        for(int i=0;i<=3400;i++)
        {
            if(l%prime[i]==0)
                ini=0;
            else
                ini=prime[i]-(l%prime[i]);
            //cout<<i<<endl;
            for(int j=ini;j<r-l+1;j=j+prime[i])
            {
                /*cout<<save[0][j]<<endl;
                system("pause");*/
                temp=0;
                while(save[0][j]%prime[i]==0)
                {
                    temp++;
                    save[0][j]/=prime[i];
                }
                if(temp>0)
                    save[1][j]*=(temp+1);
            }
            
            if(prime[i]>sm)
            {    
                sap=i;
                break;
            }
            
        }
        if(sap==0)
            sap=3400;
        //cout<<sap<<endl;
        /*for(int i=0;i<r-l+1;i++)
        {
                cout<<save[1][i]<<" ";
        }
        system("pause");*/
        int MAX,check=0;
        MAX=save[1][0];
        for(int i=0;i<r-l+1;i++)
        {
            if(save[0][i]>1)
               save[1][i]*=2; 
            if(save[1][i]>MAX)
            {
                MAX=save[1][i];
                check=i;
            }
        }
        cout<<"Between "<<l<<" and "<<r<<", "<<l+check<<" has a maximum of "<<MAX<<" divisors."<<endl;
        
    }
}
    
