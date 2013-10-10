#include<iostream>
#include<string.h>
using namespace std;
int buf[30],base,depth,r,c,m,map[7][7],check[4][4],flag;
void comb(int a,int b);
int main()
{
    int ll;
    char tmp;
    //freopen("6.out","w",stdout);
    for(int oo=1;;oo++)
    {
            
            cin>>r>>c;
            
            flag=0;
            
            memset(check,0,sizeof(check));
            memset(buf,0,sizeof(buf));
            if(r==0)
                    break;
            
            for(int i=1;i<=3;i++)
            {
                for(int j=1;j<=3;j++)
                {
                    cin>>tmp;
                    if(tmp=='*')
                            check[i][j]=1;
                    else if(tmp=='.')
                            check[i][j]=0;
                }
            }
            if(oo!=1)
                cout<<endl;
            cout<<"Case #"<<oo<<endl;
            
                    base=1;
                    for(m=1;m<=r*c;m++)
                    {
                            depth=1;
                            comb(base,depth);
                            if(flag==1)
                                break;
                    }
                    if(flag==0)
                            cout<<"Impossible.";
            
    }
}           
            
void comb(int a,int b)
{
        int i,o,nn,aa,bb,aaa,bbb,checkok,os;
        for(i=a;i<=r*c;i++)
        {
                buf[b]=i; 
                if(b==m)
                {
                        memset(map,0,sizeof(map));
                        for(int p=1;p<=m;p++)
                        {
                                //cout<<buf[p]<<" ";
                                aa=buf[p]/c;
                                bb=buf[p]%c;
                                if(buf[p]%c!=0)
                                    aa++;
                                else
                                    bb=c;
                                os=0;
                                if(aa>2)
                                {
                                    for(int kk=1;kk<=c;kk++)
                                    {
                                        if(map[aa-2][kk]%2==0)
                                        {
                                            os=1;
                                            break;
                                        }
                                    }
                                }
                                if(os==1)
                                    break;
                                aa--;
                                bb--;
                                //cout<<"aa "<<aa<<" bb "<<bb<<endl;
                                for(int y=1;y<=9;y++)
                                {
                                    //cout<<"aa "<<aa<<" bb "<<bb<<endl;
                                    aaa=y/3;
                                    bbb=y%3;
                                    if(y%3!=0)
                                        aaa++;
                                    else
                                        bbb=3;
                                    //cout<<"aaa "<<aaa<<" bbb "<<bbb<<endl;    
                                    if(aa>0&&bb>0&&aa<=r&&bb<=c)
                                    {    
                                        
                                            map[aa][bb]+=check[aaa][bbb];
                                        
                                    }
                                    bb++;
                                    if(y%3==0)
                                    {
                                        bb-=3;
                                        aa++;
                                    }
                                    
                                    
                                }
                                
                        }
                        //cout<<endl;
                        
                        checkok=0;
                        for(int ii=1;ii<=r;ii++)
                        {
                            for(int jj=1;jj<=c;jj++)
                            {
                                if(map[ii][jj]%2==0)
                                {        
                                        checkok=1;
                                        break;
                                }
                                
                            }
                            //cout<<endl;
                        }
                        /*for(int ii=1;ii<=r;ii++)
                            {
                                for(int jj=1;jj<=c;jj++)
                                {
                                    cout<<map[ii][jj]<<" ";
                                }
                                cout<<endl;
                            }
                            system("pause");*/
                        if(checkok==0)
                        {
                            flag=1;
                            /*for(int ii=1;ii<=r;ii++)
                            {
                                for(int jj=1;jj<=c;jj++)
                                {
                                    cout<<map[ii][jj]<<" ";
                                }
                                cout<<endl;
                            }*/
                            for(int p=1;p<m;p++)
                            {
                                cout<<buf[p]<<" ";
                            }
                            cout<<buf[m];
                            //system("pause");
                            break;
                            
                        }
                        if(os==1)
                            break;
                        
                }    
                                    
                else if((r*c)<(m-b+1))
                        break;
                else
                {
                        memset(map,0,sizeof(map));
                        for(int p=1;p<=b;p++)
                        {
                                //cout<<buf[p]<<" ";
                                aa=buf[p]/c;
                                bb=buf[p]%c;
                                if(buf[p]%c!=0)
                                    aa++;
                                else
                                    bb=c;
                                os=0;
                                if(aa>2)
                                {
                                    for(int kk=1;kk<=c;kk++)
                                    {
                                        if(map[aa-2][kk]%2==0)
                                        {
                                            os=1;
                                            break;
                                        }
                                    }
                                }
                                if(os==1)
                                    break;
                                aa--;
                                bb--;
                                //cout<<"aa "<<aa<<" bb "<<bb<<endl;
                                for(int y=1;y<=9;y++)
                                {
                                    //cout<<"aa "<<aa<<" bb "<<bb<<endl;
                                    aaa=y/3;
                                    bbb=y%3;
                                    if(y%3!=0)
                                        aaa++;
                                    else
                                        bbb=3;
                                    //cout<<"aaa "<<aaa<<" bbb "<<bbb<<endl;    
                                    if(aa>0&&bb>0&&aa<=r&&bb<=c)
                                    {    
                                        
                                            map[aa][bb]+=check[aaa][bbb];
                                        
                                    }
                                    bb++;
                                    if(y%3==0)
                                    {
                                        bb-=3;
                                        aa++;
                                    }
                                    
                                    
                                }
                                
                        }
                        //cout<<endl;
                        
                        checkok=0;
                        for(int ii=1;ii<=r;ii++)
                        {
                            for(int jj=1;jj<=c;jj++)
                            {
                                if(map[ii][jj]%2==0)
                                {        
                                        checkok=1;
                                        break;
                                }
                                
                            }
                            //cout<<endl;
                        }
                        /*for(int ii=1;ii<=r;ii++)
                            {
                                for(int jj=1;jj<=c;jj++)
                                {
                                    cout<<map[ii][jj]<<" ";
                                }
                                cout<<endl;
                            }
                            system("pause");*/
                        if(checkok==0)
                        {
                            flag=1;
                            /*for(int ii=1;ii<=r;ii++)
                            {
                                for(int jj=1;jj<=c;jj++)
                                {
                                    cout<<map[ii][jj]<<" ";
                                }
                                cout<<endl;
                            }*/
                            for(int p=1;p<m;p++)
                            {
                                cout<<buf[p]<<" ";
                            }
                            cout<<buf[m];
                            //system("pause");
                            break;
                            
                        }
                        if(os==1)
                            break;
                        comb(i+1,b+1);
                }
                
                if(flag==1)
                    break;
        }
}               
        
        
        
        
        
        
        
        
       
