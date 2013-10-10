#include<iostream>
#include<string.h>
#include<cstring>
#include<string>  
using namespace std;
int node[11][11][5][5],queue[1000][5],pi[11][11][5][5],color[11][11],d[11][11],outq[1000][2],flag[11][11][5];
int main()
{
    char sd,a[50],b[50],c[50];
    int yy;
    int sn,sm,en,em,n,m,numd,numd2,sn2,sm2,aa2,ioru2,snn,smm,saa,aab,s,tag;
    //freopen("816.in","r",stdin);
    //freopen("1.out","w",stdout);
    while(1)
    {
                 memset(a,0,sizeof(a));
                 memset(b,0,sizeof(b));
                 memset(c,0,sizeof(c));
                 memset(node,0,sizeof(node));
                 memset(queue,0,sizeof(queue));
                 memset(pi,0,sizeof(pi));
                 memset(color,0,sizeof(color));
                 memset(d,0,sizeof(d));
                 memset(outq,0,sizeof(outq));
                 memset(flag,0,sizeof(flag));
                 cin.getline(a,50);
                 if(strncmp("END",a,3)==0)
                              break;
                 cin.getline(b,50);
                 sn=b[0]-'0';
                 sm=b[2]-'0';
                 sd=b[4];
                 en=b[6]-'0';
                 em=b[8]-'0';
                 while(1)
                 {
                            cin.getline(c,50);
                            if(c[0]=='0')
                                break;
                            n=c[0]-'0';
                            m=c[2]-'0';
                            s=4;
                            while(c[s]!='*')
                            {
                                      /*cout<<s<<endl;
                                      system("pause");*/
                                      if(c[s]=='S')
                                          numd=1;
                                      else if(c[s]=='N')
                                          numd=2;
                                      else if(c[s]=='E')
                                          numd=3;
                                      else if(c[s]=='W')
                                          numd=4;
                                      if(numd==1)
                                      {
                                                 s++;
                                                 for(;c[s]!=' ';s++)
                                                 {
                                                         if(c[s]=='F')
                                                             numd2=2;
                                                         else if(c[s]=='L')
                                                              numd2=4;
                                                         else if(c[s]=='R')
                                                              numd2=3;
                                                         node[n][m][numd][numd2]=1;
                                                 }
                                                 s++;
                                      }
                                      else if(numd==2)
                                      {
                                                 s++;
                                                 for(;c[s]!=' ';s++)
                                                 {
                                                         if(c[s]=='F')
                                                             numd2=1;
                                                         else if(c[s]=='L')
                                                              numd2=3;
                                                         else if(c[s]=='R')
                                                              numd2=4;
                                                         node[n][m][numd][numd2]=1;
                                                 }
                                                 s++;
                                      }
                                      else if(numd==3)
                                      {
                                                 s++;
                                                 for(;c[s]!=' ';s++)
                                                 {
                                                         if(c[s]=='F')
                                                             numd2=4;
                                                         else if(c[s]=='L')
                                                              numd2=1;
                                                         else if(c[s]=='R')
                                                              numd2=2;
                                                         node[n][m][numd][numd2]=1;
                                                 }
                                                 s++;
                                      }
                                      else if(numd==4)
                                      {
                                                 s++;
                                                 for(;c[s]!=' ';s++)
                                                 {
                                                         if(c[s]=='F')
                                                             numd2=3;
                                                         else if(c[s]=='L')
                                                              numd2=2;
                                                         else if(c[s]=='R')
                                                              numd2=1;
                                                         node[n][m][numd][numd2]=1;
                                                 }
                                                 s++;
                                      }
                                      
                            }
                            
                 }
                 color[sn][sm]=1;
                 d[sn][sm]=0;
                 int sq=0,aa=0,ioru;
                 if(sd=='N')
                     aa=2;
                 else if(sd=='S')
                     aa=1;
                 else if(sd=='E')
                     aa=3;
                 else if(sd=='W')
                     aa=4;
                queue[sq][0]=sn;
                queue[sq][1]=sm;
                queue[sq][2]=aa;
                queue[sq][3]=1;
                sq=(sq+1)%1000;
                int start=0; 
                tag=0;
                while(queue[tag][0]!=0)
                {
                             
                             sn=queue[tag][0];
                             sm=queue[tag][1];
                             aa=queue[tag][2];
                             ioru=queue[tag][3];
                             aab=queue[tag][4];
                             queue[tag][0]=0;
                             queue[tag][1]=0;
                             queue[tag][2]=0;
                             queue[tag][3]=0;
                             queue[tag][4]=0;
                             tag=(tag+1)%1000;
                             sn2=sn;
                             sm2=sm;
                             //cout<<sn2<<" "<<sm2<<endl;
                             //system("pause");
                            
                                        
                                        if(aa==2)
                                        {
                                            sn2--;
                                        }
                                        else if(aa==1)
                                        {
                                            sn2++;
                                        }
                                        else if(aa==3)
                                        {
                                            sm2++;
                                        }
                                        else if(aa==4)
                                        {
                                            sm2--;
                                        }
                                        
                                        if(start==0)
                                        {
                                                    start=1;
                                                    aab=0;
                                        }
                                        /*cout<<sn<<" "<<sm<<" "<<aab<<endl;
                                        cout<<sn2<<" "<<sm2<<" "<<aa<<endl;
                                        system("pause");*/
                                                            d[sn2][sm2]=d[sn][sm]+1;
                                                            if(pi[sn2][sm2][aa][0]==0)
                                                            {
                                                                pi[sn2][sm2][aa][0]=sn;
                                                                pi[sn2][sm2][aa][1]=sm;
                                                                pi[sn2][sm2][aa][2]=aab;
                                                            }
                                                            if(sn2==en&&sm2==em)
                                                            {    
                                                                yy=0;
                                                                outq[yy][0]=sn2;
                                                                outq[yy][1]=sm2;
                                                                yy++;
                                                                snn=sn2;
                                                                smm=sm2;
                                                                saa=aa;
                                                                //cout<<snn<<" "<<smm<<" "<<saa<<endl;
                                                                break;
                                                            }
                                        
                                        if(flag[sn][sm][aa]==0)
                                        {
                                        for(int i=1;i<=4;i++)
                                        {
                                                 if(node[sn2][sm2][aa][i]==1)
                                                 {
                                                     queue[sq][0]=sn2;
                                                     queue[sq][1]=sm2;
                                                     if(i%2==0)
                                                         queue[sq][2]=i-1;
                                                     else
                                                         queue[sq][2]=i+1;
                                                     queue[sq][3]=1;
                                                     queue[sq][4]=aa;
                                                     sq=(sq+1)%1000;
                                                     //cout<<i<<endl;
                                                     
                                                 }
                                        }
                                        flag[sn][sm][aa]=1;
                                        }
                                        color[sn][sm]=2;           
                             
                             //cout<<sq<<endl;
                }       
                 //cout<<d[3][3]<<endl;
                 //cout<<sq<<endl;
                 /*for(int i=1;i<=3;i++)
                 {
                         for(int j=1;j<=3;j++)
                         {
                                 cout<<d[i][j]<<" ";
                         }
                         cout<<endl;
                 }*/
                 //system("pause");
                 int temp,temp2,temp3;
                 if(d[en][em]!=0)
                 {
                 
                 while(d[en][em]!=0)
                 {
                                    outq[yy][0]=pi[snn][smm][saa][0];
                                    outq[yy][1]=pi[snn][smm][saa][1];
                                    yy++;
                                    //cout<<"("<<pi[snn][smm][saa][0]<<","<< pi[snn][smm][saa][1]<<") " ;
                                    temp=pi[snn][smm][saa][0];
                                    temp2=pi[snn][smm][saa][1];
                                    temp3=pi[snn][smm][saa][2];
                                    snn=temp;
                                    smm=temp2;
                                    saa=temp3;
                                    //cout<<snn<<" "<<smm<<" "<<saa<<endl;
                                    d[en][em]--;
                 }
                 //cout<<endl;
                 int sp=0;
                 cout<<a<<endl;
                 cout<<"  ";
                 for(int i=yy-1;i>0;i--)
                 {
                         cout<<"("<<outq[i][0]<<","<<outq[i][1]<<")";
                         sp++;
                         if(sp!=10)
                             cout<<" ";
                         else
                         {
                             sp=0;
                             cout<<endl;
                             cout<<"  ";
                         }
                 }
                 cout<<"("<<outq[0][0]<<","<<outq[0][1]<<")"<<endl;
                 }
                 else
                 {
                     cout<<a<<endl;
                     cout<<"  No Solution Possible"<<endl;
                 }
                 
                 /*for(int i=1;i<=9;i++)
                 {
                         for(int j=1;j<=9;j++)
                         {
                                 
                                 for(int k=1;k<=4;k++)
                                 {
                                         
                                                 cout<<"( "<<i<<", "<<j<<", "<<k<<")"<<endl;
                                                 for(int l=1;l<=4;l++)
                                                 {
                                                         
                                                         cout<<node[i][j][k][l]<<" ";
                                                 }
                                                 
                                         
                                         cout<<endl;
                                         system("pause");
                                         
                                 }
                                 
                         }
                 }*/
                                         
    }   
}
                 
                 
                              
