#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int u,l,sa,A[30][30],w[30][30],ii,jj,check,flag[30],set;
    char na[30],nb[30],namet[30][30];
    //freopen("data.out","w",stdout);
    set=1;
    while(cin>>u>>l)
    {
                    memset(A,0,sizeof(A));
                    memset(w,0,sizeof(w));
                    memset(flag,0,sizeof(flag));
                    memset(na,0,sizeof(na));
                    memset(nb,0,sizeof(nb));
                    memset(namet,0,sizeof(namet));
                    sa=1;
                    if(u==0)
                            break;
                    for(int i=1;i<=l;i++)
                    {
                            cin>>na>>nb;
                            if(sa==0)
                            {
                                     strcpy(namet[sa],na);
                                     sa++;
                                     ii=0;      
                            }
                            else
                            {
                                     check=0;
                                     for(int j=1;j<=sa;j++)
                                     {
                                             if(strcmp(namet[j],na)==0)
                                             {
                                                 ii=j;
                                                 check=1;
                                                 break;
                                             }
                                     }
                                     if(check==0)
                                     {
                                                 strcpy(namet[sa],na);
                                                 sa++;
                                                 ii=sa-1;
                                     }
                            }
                            check=0;
                            for(int j=1;j<=sa;j++)
                            {
                                    if(strcmp(namet[j],nb)==0)
                                    {
                                        jj=j;
                                        check=1;
                                        break;
                                    }
                            }
                            if(check==0)
                            {
                                        strcpy(namet[sa],nb);
                                        sa++;
                                        jj=sa-1;
                            }
                            A[ii][jj]=1;
                            w[ii][jj]=1;
                    }
                    /*for(int i=1;i<=u;i++)
                    {
                            for(int j=1;j<=u;j++)
                                cout<<A[i][j]<<" ";
                            cout<<endl;
                    }
                    cout<<endl;*/
                    for(int i=1;i<=u;i++)
                    {
                            for(int j=1;j<=u;j++)
                            {
                                    if(i==j)
                                            w[i][j]=0;
                                    else if(w[i][j]!=1)
                                            w[i][j]=100000;
                            }                              
                    }
                    int temp,temp2;
                    for(int k=1;k<=u;k++)
                    {
                            for(int i=1;i<=u;i++)
                            {
                                    for(int j=1;j<=u;j++)
                                    {
                                         temp=w[i][j];
                                         temp2=w[i][k]+w[k][j];
                                         if(temp<temp2)
                                             w[i][j]=temp;
                                         else
                                             w[i][j]=temp2;
                                    }
                            }
                    }
                    for(int i=1;i<=u;i++)
                    {
                            for(int j=1;j<=u;j++)
                            {
                                    if(w[i][j]>=100000)
                                        w[i][j]=0;
                                    else
                                        w[i][j]=1;
                            }                              
                    }
                    /*for(int i=1;i<=u;i++)
                    {
                            for(int j=1;j<=u;j++)
                                cout<<w[i][j]<<" ";
                            cout<<endl;
                    }*/
                    if(set!=1)
                            cout<<endl;
                    cout<<"Calling circles for data set "<<set<<":"<<endl;
                    set++;
                    for(int i=1;i<=u;i++)
                    {
                            if(flag[i]==0)
                            {
                                          flag[i]=1;
                                          cout<<namet[i];
                                          for(int j=i+1;j<=u;j++)
                                          {
                                                    if(w[i][j]==1&&w[j][i]==1)
                                                    {
                                                                              flag[j]=1;
                                                                              cout<<", "<<namet[j];
                                                    }
                                          }
                                          cout<<endl;
                            }
                            
                    }     
                    
                    
    }
}
                            
                            
                                      
                            
                    
    
