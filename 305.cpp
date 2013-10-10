#include<iostream>
using namespace std;
int main()
{
    int k,ans[20]={0},num,m,ok,p,sit;
    for(k=1;k<=14;k++)
    {
        for(m=k+1;;m++)
        {
            p=0;
            for(sit=2*k;sit>k;sit--)
            {
                if(p==0)
                    p=m%sit;
                else
                p=(p+m-1)%sit;
                if(p<=k&&p>0)
                    break;
                
            }
            if(sit==k)
            {
                ans[k]=m;
                break;
            }
        
        }
    }
    /*for(k=1;k<=14;k++)
    {
        cout<<ans[k]<<endl;
    }*/
    while(cin>>num)
    {
        if(num==0)
            break;
        else
            cout<<ans[num]<<endl;
    }
}
                                                          
    
            
