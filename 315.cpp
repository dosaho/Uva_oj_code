#include<iostream>
#include<string.h>
#include<cstring>
#include<iomanip>
using namespace std;
int node[1000010],next[1000010],fnum[30020],flag,color[30020],temp;
void setup(int a,int b);
void DFS(int a);
int main()
{
          int allnum,N,M,A,B,max=0,AA,BB,ansnum,kk=0;
          char sa[110];
          //freopen("6.out","w",stdout);
          while(cin>>allnum)
          {
                            
                            max=0;
                            memset(fnum,-1,sizeof(fnum));
                            memset(next,-1,sizeof(next));
                            memset(node,-1,sizeof(node));
                            flag=0;
                            ansnum=0;
                            if(allnum==0)
                                         break;
                            cin.getline(sa,110);
                            for(;;)
                            {
                                   cin.getline(sa,110);
                                   if(sa[1]!=' '&&strlen(sa)>1)
                                   {
                                               A=(sa[0]-'0')*10;
                                               A=A+sa[1]-'0';
                                               kk=3;
                                   }
                                   else
                                   {
                                               A=sa[0]-'0';
                                               kk=2;
                                   }
                                   if(A==0)
                                           break;
                                   for(int i=kk;i<strlen(sa);i+=2)
                                   {
                                           if(sa[i+1]!=' '&&i+1<strlen(sa))
                                           {
                                                         B=(sa[i]-'0')*10;
                                                         B=B+sa[i+1]-'0';
                                                         i++;
                                           }
                                           else              
                                                             B=sa[i]-'0';
                                           setup(A,B);
                                           setup(B,A);
                                   }
                                  
                                   
                                           
                                   
                            } 
                            memset(color,0,sizeof(color));
                            for(int i=1;i<=allnum;i++)
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
                            for(int i=1;i<=allnum;i++)
                            {
                                    
                                    memset(color,0,sizeof(color));
                                    color[i]=2;
                                    for(int j=1;j<=allnum;j++)
                                    {
                                            temp=0;
                                            if(color[j]==0)
                                            {
                                                           temp++;
                                                           DFS(j);
                                            }
                                            if(temp<allnum-1&&temp!=0)
                                            {
                                                             ansnum++;
                                                             break;
                                            }
                                    }
                            }
                            cout<<ansnum<<endl;     
                            
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
