#include<iostream>
#include<stdlib.h>
using namespace std;
int comp(const void *a,const void *b);
int compb( const void *a, const void *b);
int compc( const void *a, const void *b);
void array(int* a);
void binary(int N);
int le,pnum;
int x[100];
int st[200],stlist[200],checkt[10005]={0},tet[70][200];
int main()
{
    int Num,w,temp=1,fia;
    //freopen("812.in", "r", stdin);
    //freopen("879.out", "w", stdout);
    while(cin>>Num)
    {
        if(Num==0)
            break;
        int pt[Num+1][200],check,sa,MAX;
        int all=0,b;
        for(int i=0;i<10005;i++)
            checkt[i]=0;
        for(int i=0;i<Num;i++)
        {
            for(int j=0;j<51;j++)
            {
                pt[i][j]=-1;
                tet[i][j]=10000;
            }
        }
        for(int i=0;i<Num;i++)
        {
            cin>>w;
            for(int j=1;j<=w;j++)
            {
                cin>>b;
                pt[i][j]=10-b+pt[i][j-1];
                if(j==1)
                    pt[i][j]+=1;
            }
        }
        /*for(int i=0;i<Num;i++)
        {
            for(int j=0;j<51;j++)
            {
                cout<<pt[i][j]<<" ";
            }
            cout<<endl;
        }*/
        if(temp!=1)
            cout<<endl;
        cout<<"Workyards "<<temp<<endl;
        MAX=0;
        pnum=0;
        for(int i=0;i<Num;i++)
        {
            for(int j=0;j<51;j++)
                st[j]=pt[i][j];  
            for(int j=0;j<51;j++)
                stlist[j]=j;  
            qsort(stlist,51,sizeof(int),comp);
            if(st[stlist[0]]>0)
                MAX+=st[stlist[0]];
            for(sa=0;st[stlist[sa]]>=0&&st[stlist[sa]]==st[stlist[sa+1]];sa++);
           /*for(int j=0;j<51;j++)
             cout<<stlist[j]<<" ";
               cout<<endl;
            system("pause");*/
            qsort(stlist,sa+1,sizeof(int),compb);
            /*for(int j=0;j<51;j++)
                 cout<<stlist[j]<<" ";
                cout<<endl;
            system("pause");*/
            if(st[stlist[0]]>0)
                pnum+=stlist[0];
            if(st[stlist[0]]>=0)
            {
                if(st[stlist[0]]>0)
                {
                    for(int j=0;;j++)
                    {
                        if(st[stlist[j]]!=st[stlist[0]] )
                            break;       
                        tet[i][j]=stlist[j];
                    }
                }
                else
                {
                    tet[i][0]=0;
                    for(int j=0;;j++)
                    {
                        if(st[stlist[j]]!=st[stlist[0]] )
                            break;       
                        tet[i][j+1]=stlist[j];
                    }
                }
            }
        }
        
        
        
        /*for(int i=0;i<Num;i++)cout<<pnum<<endl;
        {
            for(int j=0;j<10;j++)
            {
                cout<<tet[i][j]<<" ";
            }
            cout<<endl;
        }system("pause");*/
        cout<<"Maximum profit is "<<MAX<<"."<<endl;
        checkt[pnum]=1;
        cout<<"Number of pruls to buy:";
         /*for(int j=0;j<51;j++)
                 cout<<st[j]<<" ";
                cout<<endl;
            system("pause");*/
        int h,fia=0;
        
        for(int p=0;p<Num-1;p++)
        {
            int o=0;
            int save[200]={0};
            if(tet[p+1][0]!=10000)
            {
                for(int i=0;tet[p][i]!=10000;i++)
                {
                    for(int j=0;tet[p+1][j]!=10000;j++)
                    {
                        save[o]=tet[p][i]+tet[p+1][j];
                        o++;
                    }
                }
                qsort(save,o,sizeof(int),compc);
                /*for(int j=0;j<51;j++)
                {
                    cout<<save[j]<<" ";
                }
                cout<<endl;
                system("pause");*/
                fia=0;
                if(save[0]!=0||save[1]!=0)
                {    
                    tet[p+1][0]=save[0];
                    fia++;
                }
                for(int i=1;i<=100;i++)
                {
                    if(save[i]!=tet[p+1][fia-1]&&save[i]!=0)
                    {
                        tet[p+1][fia]=save[i];
                        fia++;
                    }
                    if(fia==10)
                        break;
                }
                if(fia!=0)
                {
                for(int i=fia;i<200;i++)
                     tet[p+1][i]=10000;
                }
            }
            else
            {
                for(int i=0;i<10;i++)
                {
                     tet[p+1][i]= tet[p][i];
                }
            }
            /*for(int i=0;i<10;i++)
                {
                     cout<<tet[p+1][i]<<" ";
                }
                cout<<endl;
                system("pause");*/        
        }
        if(tet[Num-1][0]==10000)
        {
            cout<<" "<<0;
        }
        else
        {
        for(int i=0;i<10;i++)
        {    
                if(tet[Num-1][i]==10000)
                    break;
                cout<<" "<<tet[Num-1][i];
        }
        }
        cout<<endl;
        temp++;
    }
}
int comp( const void *a, const void *b)
{ 
    int c, d, x;
    c = *(int *)(a);
    d = *(int *)(b);
    if(st[c]<st[d])
        return 1;  
    else if(st[c]>st[d])
        return -1;
    else if(st[c]==st[d])
        return 0;          
}
int compb( const void *a, const void *b)
{ 
    int c, d, x;
    c = *(int *)(a);
    d = *(int *)(b);
    if(c>d)
        return 1;  
    else if(c<d)
        return -1;
    else if(c==d)
        return 0;          
}
int compc( const void *a, const void *b)
{ 
    int c, d, x;
    c = *(int *)(a);
    d = *(int *)(b);
    if(c>d)
        return 1;  
    else if(c<d)
        return -1;
    else if(c==d)
        return 0;          
}
void binary(int N)
{
     int k;
     k=pnum;
     if (N>=0) 
     {
         x[N] = 0;
         binary(N-1);
         x[N] = 1;
         binary(N-1);
     }
     else 
     {
         
         for(int i=0;i<le;i++) 
         {
             if(x[le-1-i]==1)
             {    
                 k+=st[stlist[i]];
                 checkt[k]=1;
                 if(tet[stlist[i]][1]>0&&tet[stlist[i]][1]!=100)
                     k+=tet[stlist[i]][1];
                 checkt[k]=1;
             }    
         }
         
     }
}

