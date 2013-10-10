#include<iostream>
#include<string.h>
#include<iomanip>
#define INF 2E14 
using namespace std;
long long matrix[60][60],s[60],d[60],pi[60],n,m,item;
void init(long long a,long long b);
void relax(long long a,long long b);
int main()
{
    char aa,bb,trace,tr;
    int check,min;
    //freopen("6.out","w",stdout);
    for(int k=1;;k++)
    {
                 memset(matrix,0,sizeof(matrix));
                 cin>>n;
                 if(n==-1)
                          break;
                 for(int i=1;i<=n;i++)
                 {
                         cin>>aa>>bb;
                         if(aa<=90)
                                   aa-=64;
                         else
                                   aa-=70;
                         if(bb<=90)
                                   bb-=64;
                         else
                                   bb-=70;
                         matrix[aa][bb]=1;
                         matrix[bb][aa]=1;
                 }
                 cin>>item>>aa>>bb;
                 if(aa<=90)
                     aa-=64;
                 else
                     aa-=70;
                 if(bb<=90)
                     bb-=64;
                 else
                     bb-=70;
                 init(bb,item);
                 for(int i=1;i<=52;i++)
                 {
                         check=0;
                         for(int j=1;j<=52;j++)
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
                         s[min]=1;
                         for(int j=1;j<=52;j++)
                         {
                                 if(matrix[min][j]!=0)
                                     relax(min,j);
                         }
                 }
                 cout<<"Case "<<k<<":"<<endl;
                 cout<<d[aa]<<endl;
                 trace=aa;
                 while(trace!=bb)
                 {
                                 
                                 tr=trace;
                                 if(trace<=26)
                                     tr+=64;
                                 else 
                                     tr+=70;
                                     cout<<tr<<"-";
                                 trace=pi[trace];
                 }
                 tr=trace;
                 if(trace<=26)
                     tr+=64;
                 else 
                     tr+=70;
                 cout<<tr<<endl;
                 
                 
    }
}

void init(long long a,long long b)
{
     memset(s,0,sizeof(s));
     memset(pi,0,sizeof(pi));
     for(int i=1;i<=52;i++)
         d[i]=INF;
     d[a]=item;
}
void relax(long long a,long long b)
{
     long long temp,temp1=0,temp3=0;
     if(a<=26)
     {
                temp=d[a];
                temp1=temp*20;
                temp1/=19;
                temp3=temp1/20;
                if(temp1%20!=0)
                    temp3++;
                
                while(temp1-temp3!=temp)
                {
                    temp1++;
                    temp3=temp1/20;
                    if(temp1%20!=0)
                        temp3++;
                }
                if(d[b]>temp1)
                {
                    d[b]=temp1;
                    pi[b]=a;
                }
     }
     else
     {
         temp1=d[a];
         temp1++;
         if(d[b]>temp1)
         {           
                     d[b]=temp1;
                     pi[b]=a;
         }
     }
     //cout<<"temp  "<<temp1<<endl;
                
                  
}
                         
                              
