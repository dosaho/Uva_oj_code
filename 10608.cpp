#include<iostream>
#include<string.h>
using namespace std;
int node[1000010],next[1000010],fnum[30020],flag,color[30020],temp;
void setup(int a,int b);
void DFS(int a);
int main()
{
          int allnum,N,M,A,B,max=0;
          cin>>allnum;
          //freopen("6.out","w",stdout);
          for(int j=0;j<allnum;j++)
          {
                            
                            
                            max=0;
                            cin>>N>>M;
                            memset(fnum,-1,sizeof(fnum));
                            memset(next,-1,sizeof(next));
                            memset(node,-1,sizeof(node));
                            memset(color,0,sizeof(color));
                            flag=0;
                            for(int i=0;i<M;i++)
                            {
                                    cin>>A>>B;
                                    setup(A,B);
                                    setup(B,A);
                            }
                            for(int i=1;i<=N;i++)
                            {
                                    temp=0;
                                    if(color[i]==0)
                                    {
                                              temp++;
                                              DFS(i);
                                    }
                                    if(temp>max)
                                        max=temp;
                            }     
                            cout<<max<<endl;
                            
                            
                                                               
                                                                                 
          }
}

void setup(int a,int b)
{
               int repeat,trace;
               if(fnum[a]==-1)
               {
                              fnum[a]=flag;
                              node[flag]=b;
                              flag++;
               }
               else
               {
                              trace=fnum[a];
                              repeat=1;
                              while(node[trace]!=-1)
                              {
                                                    if(node[trace]==b)
                                                    {
                                                                      repeat=0;
                                                                      break;
                                                    }
                                                    if(next[trace]==-1)
                                                    {
                                                                       next[trace]=flag;
                                                                       trace=next[trace];
                                                                       flag++;
                                                    }
                                                    else
                                                                       trace=next[trace];
                                                                                                       
                              }
                              if(repeat==1)
                                           node[trace]=b;
               }
} 

void DFS(int aa)
{
             int bb,cc;
             color[aa]=1;
             bb=fnum[aa];
             for(;;)
             {
                    if(color[node[bb]]==0)
                    {                      
                                           temp++;
                                           DFS(node[bb]);
                    }
                    if(next[bb]==-1)
                                    break;
                    else            
                                    bb=next[bb];
             }
             
             color[aa]=2;
}         
