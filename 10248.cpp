#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int np[15][4],n,m,a,aa,node[10],all,good;
    //freopen("6.out","w",stdout);
    while(cin>>n>>m)
    {
                    memset(np,0,sizeof(np));
                    memset(node,0,sizeof(node));
                    all=0;
                    good=0;
                    for(int i=n;i<=m;i++)
                    {
                            if(i>=10)
                            {
                            a=i/10;
                            aa=i%10;
                            node[a]=1;
                            node[aa]=1;
                            np[a][0]++;
                            np[aa][1]++;
                            all+=2;
                            }
                    }
                     for(int i=0;i<=9;i++)
                    {
                            if(np[i][0]>np[i][1])
                                good+=np[i][1];
                            else
                                good+=np[i][0];
                    }
                    if(n<10)
                    {
                            for(int i=n;i<=9&&i<=m;i++)
                            {
                                    np[i][1]++;
                                    if(node[i]==0)
                                                  all++;
                            }
                    }
                    //cout<<all;
                    if(n==m&&a==aa&&n>=11)
                        all++;
                    //cout<<all<<" all "<<good<<" good "<<endl;
                    cout<<all-good<<endl;
    }
} 
