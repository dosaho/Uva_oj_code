#include<iostream>
#include<string.h>
using namespace std;
int matrix[50][2000],deg[50],edge[2000],num;
void euler(int a,int b);
int main()
{
          int a,b,c,checke,max,st;
          //freopen("6.out","w",stdout);
          while(cin>>a>>b)
          {
                          memset(matrix,0,sizeof(matrix));
                          memset(deg,0,sizeof(deg));
                          memset(edge,0,sizeof(edge));
                          max=0;
                          num=0;
                          if(a==0&&b==0)
                                        break;
                          if(a>b)
                                 st=b;
                          else
                                 st=a;
                          cin>>c;
                          if(c>max)
                                   max=c;
                          deg[a]++;
                          deg[b]++;
                          matrix[a][c]++;
                          matrix[b][c]++;
                          while(cin>>a>>b)
                          {
                                        if(a==0&&b==0)
                                                      break;
                                        cin>>c;
                                        if(c>max)
                                                 max=c;
                                        deg[a]++;
                                        deg[b]++;
                                        matrix[a][c]++;
                                        matrix[b][c]++;
                          }
                          checke=0;
                          for(int i=1;i<=44;i++)
                          {
                                  if(deg[i]%2!=0)
                                  {    
                                       checke=1;
                                       break;
                                  }
                          }
                          if(checke==1)
                          {
                                       cout<<"Round trip does not exist."<<endl<<endl;
                          }
                          else
                          {
                                       euler(st,max);
                                       for(int i=num-1;i>0;i--)
                                               cout<<edge[i]<<" ";
                                       cout<<edge[0];
                                       cout<<endl<<endl;
                          }
                                       
          }
}

void euler(int st,int max)
{
     int temp=0,x;
     /*cout<<st<<" st"<<endl;
     system("pause");*/
     while(deg[st]!=0)
     {
                      for(int i=1;i<=max;i++)
                      {
                              if(matrix[st][i]!=0)
                              {
                                      temp=i;
                                      x=i;
                                      matrix[st][i]--;
                                      deg[st]--;
                                      break;
                              }
                      }
                      
                      //cout<<temp<<endl;
                      for(int i=1;i<=44;i++)
                      {
                              if(matrix[i][temp]!=0)
                              {
                                      matrix[i][temp]--;
                                      deg[st]--;
                                      temp=i;
                                      break;
                              }
                      }                 
                      euler(temp,max);
                      edge[num]=x;
                      num++;
     }
}
                      
                                          
                          
