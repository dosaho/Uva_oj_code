#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
int matrix[510][510],s[510],d[512],n,m;
float r[510][510];
void init(int a);
void relax(int a,int b);
int main()
{
    //freopen("6.out","w",stdout);
    int a,b,l,min,temp2,sa,sb,saa,check;
    float temp,max;
    for(int k=1;;k++)
    {
                    cin>>n>>m;
                    memset(matrix,0,sizeof(matrix));
                    memset(r,0,sizeof(r));
                    if(n==0)
                            break;
                    for(int i=1;i<=m;i++)
                    {
                            cin>>a>>b>>l;
                            matrix[a][b]=l;
                            matrix[b][a]=l;
                    }
                    init(1);
                    for(int i=1;i<=n;i++)
                    {
                            check=0;
                            for(int j=1;j<=n;j++)
                            {
                                    if(s[j]==0)
                                    {
                                               if(check==0)
                                               {
                                                   min=j;
                                                   check=1;
                                               }
                                               else
                                               {
                                                   if(d[j]<d[min])
                                                       min=j;
                                               }
                                    }                      
                            }
                            //cout<<"min "<<min<<endl;
                            s[min]=1;
                            
                            for(int j=1;j<=n;j++)
                            {
                                    if(matrix[min][j]!=0)
                                        relax(min,j);
                            }
                    }
                    max=0;
                     //for(int i=1;i<=n;i++)
                        //cout<<"d: "<<d[i]<<endl;
                     for(int i=1;i<=n;i++)
                     {
                           for(int j=1;j<=n;j++)
                           {  
                                   if(matrix[i][j]!=0)
                                   {
                                       if(d[i]>d[j])
                                       {
                                           temp=matrix[i][j]-d[i]+d[j];
                                           r[i][j]=d[i]+temp/2;
                                       }
                                       else
                                       {
                                           temp=matrix[i][j]-d[j]+d[i];
                                           r[i][j]=d[j]+temp/2;
                                       }
                                       if(r[i][j]>max)
                                       {
                                                      sa=i;
                                                      sb=j;
                                                      max=r[i][j];
                                       }
                                   }
                           }
                     }
                     saa=0;
                     for(int i=1;i<=n;i++)
                     {
                             if(d[i]>=max)
                             {
                                         saa=i;
                                         max=d[i];
                             }
                     }
                     if(saa!=0)
                     {
                               cout<<"System #"<<k<<endl;
                               cout<<"The last domino falls after "<<fixed<<setprecision(1)<<max<<" seconds, at key domino "<<saa<<"."<<endl<<endl;
                     }
                     else
                     {
                               cout<<"System #"<<k<<endl;
                               cout<<"The last domino falls after "<<fixed<<setprecision(1)<<max<<" seconds, between key dominoes "<<sa<<" and "<<sb<<"."<<endl<<endl;
                     }
    }
}

void init(int a)
{
     memset(s,0,sizeof(s));
     for(int i=1;i<=n;i++)
         d[i]=10000000;
     d[a]=0;
}
void relax(int a,int b)
{
     if(d[b]>d[a]+matrix[a][b]||d[b]==-1)
     {
         d[b]=d[a]+matrix[a][b];
     }
}
