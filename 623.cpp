#include<iostream>
using namespace std;
int main()
{
    int carry,num,k,x,temp,sa;
    //freopen("1.out","w",stdout);
    while(cin>>num)
    {
        cout<<num<<"!"<<endl;
        int set[15000]={0};
        set[0]=1;
        k=1;
        carry=0;
        if(num!=0)
        {
            for(int j=1;j<=num;j++)
            {
                x=0;
                temp=j;
                do
                {
                    x++;
                    temp/=10;
                }while(temp!=0);
                k+=x;
                for(int i=0;i<k;i++)
                {
                    set[i]*=j;
                    set[i]+=carry;
                    carry=set[i]/10;
                    set[i]%=10;
                }
            }
        }
        for(sa=k;set[sa]==0;sa--);
        for(int i=sa;i>=0;i--)
            cout<<set[i];
        cout<<endl;
    }
}
