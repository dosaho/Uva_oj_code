#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
using namespace std;
int input[6][6];
int final[6][6]={{0,0,0,0,0,0},
                 {0,1,1,1,1,1},
                 {0,0,1,1,1,1},
                 {0,0,0,3,1,1},
                 {0,0,0,0,0,1},
                 {0,0,0,0,0,0}};
int insa[40000][30],fsa[40000][30],end,start,begin,fend,fok; 
int f[6][6];
int move[8][2]={{1,-2},{1,2},{-1,2},{-1,-2},{2,-1},{2,1},{-2,1},{-2,-1}};
int step,sain;
void force(int as);
void fforce(int as);
void sainput(int a);
void check();
void checkf();
int main()
{
        //freopen("data.out","w",stdout);
		int n,si,sj,num;
        char temp[6];
        cin>>n;
        cin.getline(temp,6);
        for(int k=1;k<=n;k++)
        {
                fok=1;
				start=0;
                end=0;
				step=15;
				sain=0;
				memset(input,0,sizeof(input));
				memset(insa,0,sizeof(insa));
				memset(fsa,0,sizeof(fsa));
				for(int i=0;i<=5;i++)
                {
						for(int j=0;j<=5;j++)
						{
								f[i][j]=final[i][j];
						}
				}
                for(int i=1;i<=5;i++)
                {
						cin.getline(temp,6);
						for(int j=1;j<=5;j++)
						{
								if(temp[j-1]==' ')
								{
										si=i;
										sj=j;
										input[i][j]=3;
								}
								else
										input[i][j]=temp[j-1]-'0';
						}
				}
				/*for(int i=1;i<=5;i++)
                {
						for(int j=1;j<=5;j++)
						{
								cout<<input[i][j]<<" ";
						}
						cout<<endl;
				}*/
				insa[sain][0]=0;
				insa[sain][1]=si;
				insa[sain][2]=sj;
				start=sain;
				for(int i=1;i<=5;i++)
        		{	
						for(int j=1;j<=5;j++)
						{
								num=5*(i-1);
								num+=j;
								insa[sain][num+2]=input[i][j];
						}
						
				}
				/*for(int p=0;p<28;p++)
				{
						cout<<insa[sain][p]<<" ";
				}
				cout<<endl;*/
				sain++;
				end=sain;
				for(int pp=0;pp<=4;pp++)
				{		
						begin=start;
						start=end;
						force(pp);
						end=sain;
						fend=sain;
				}
				/*for(int i=1;i<=5;i++)
                {
						for(int j=1;j<=5;j++)
						{
								cout<<f[i][j]<<" ";
						}
						cout<<endl;
				}*/
				si=3;
				sj=3;
				start=0;
                end=0;
				sain=0;
				fsa[sain][0]=0;
				fsa[sain][1]=si;
				fsa[sain][2]=sj;
				start=sain;
				for(int i=1;i<=4;i++)
        		{	
						for(int j=1;j<=5;j++)
						{
								num=5*(i-1);
								num+=j;
								fsa[sain][num+2]=f[i][j];
						}
						
				}
				/*for(int p=0;p<28;p++)
				{
						cout<<fsa[sain][p]<<" ";
				}
				cout<<endl;*/
				checkf();
				end=sain;
				if(fok!=0)
				{
						for(int pp=0;pp<=4;pp++)
						{		
								begin=start;
								start=end;
								fforce(pp);
								if(fok==0)
										break;
								end=sain;
						}
				}
				if(step==15)
						cout<<"Unsolvable in less than 11 move(s)."<<endl;
				else
						cout<<"Solvable in "<<step<<" move(s)."<<endl;
				
		}
}

void force(int as)
{
		int num,n;
		//cout<<begin<<endl;
		//cout<<end<<endl;
		for(int i=begin;i<end;i++)
		{
				for(int k=0;k<=7;k++)
				{
						if(insa[i][1]+move[k][0]>0&&insa[i][1]+move[k][0]<=5&&insa[i][2]+move[k][1]<=5&&insa[i][2]+move[k][1]>0)
						{
								insa[sain][0]=as+1;
								insa[sain][1]=insa[i][1]+move[k][0];
								insa[sain][2]=insa[i][2]+move[k][1];
								for(int ii=1;ii<=5;ii++)
        						{	
										for(int j=1;j<=5;j++)
										{
												num=5*(ii-1);
												num+=j;
												insa[sain][num+2]=insa[i][num+2];
										}
						
								}
								num=5*(insa[i][1]-1);
								num+=insa[i][2];
								n=5*(insa[sain][1]-1);
								n+=insa[sain][2];
								insa[sain][num+2]=insa[sain][n+2];
								insa[sain][n+2]=3;
								/*for(int k=0;k<28;k++)
								{
									cout<<insa[sain][k]<<" ";
								}*/
								check();
								//cout<<endl;
								
						}		
				}
		}
}

void check()
{
		int ok;
		for(int oo=0;oo<sain;oo++)
		{
				ok=0;
				for(int yy=1;yy<28;yy++)
				{
						if(insa[oo][yy]!=insa[sain][yy])
						{
								ok=1;
								break;
						}
				}
				if(ok==0)
						break;
		}
		if(ok==1)
				sain++;
}

void fforce(int as)
{
		int num,n;
		//cout<<begin<<endl;
		//cout<<end<<endl;
		for(int i=begin;i<end;i++)
		{
				for(int k=0;k<=7;k++)
				{
						if(fsa[i][1]+move[k][0]>0&&fsa[i][1]+move[k][0]<=5&&fsa[i][2]+move[k][1]<=5&&fsa[i][2]+move[k][1]>0)
						{
								fsa[sain][0]=as+1;
								fsa[sain][1]=fsa[i][1]+move[k][0];
								fsa[sain][2]=fsa[i][2]+move[k][1];
								for(int ii=1;ii<=5;ii++)
        						{	
										for(int j=1;j<=5;j++)
										{
												num=5*(ii-1);
												num+=j;
												fsa[sain][num+2]=fsa[i][num+2];
										}
						
								}
								num=5*(fsa[i][1]-1);
								num+=fsa[i][2];
								n=5*(fsa[sain][1]-1);
								n+=fsa[sain][2];
								fsa[sain][num+2]=fsa[sain][n+2];
								fsa[sain][n+2]=3;
								checkf();
								
								/*for(int k=0;k<28;k++)
								{
									cout<<insa[sain][k]<<" ";
								}*/
								//cout<<endl;
								
						}
						if(fok==0)
								break;
									
				}
				if(fok==0)
								break;
		}
}

void checkf()
{
		int ok=1;
		for(int oo=0;oo<sain;oo++)
		{
				ok=0;
				for(int yy=0;yy<28;yy++)
				{
						if(fsa[oo][yy]!=fsa[sain][yy])
						{
								ok=1;
								break;
						}
				}
				if(ok==0)
						break;
		}
		if(ok==1)
		{
				for(int qq=0;qq<fend;qq++)
				{
						fok=0;
						for(int yy=1;yy<28;yy++)
						{
								if(insa[qq][yy]!=fsa[sain][yy])
								{
										fok=1;
										break;
								}
						}
						if(fok==0)
						{
								step=insa[qq][0]+fsa[sain][0];
								break;
						}	
				}
				sain++;
		
		}		
}
                           
                                      
    
