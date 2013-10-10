#include<iostream>
#include<stdlib.h>
using namespace std;
int cmp1(const void *a,const void *b);
int cmp2(const void *a,const void *b);
int X[1000*1000],Y[1000*1000];
int main()
{
    
    int num,total,a=0,b=0,c=0,d=0,check,low,upp,mid,checkf,test,ok=0,first;
    freopen("1.out","w",stdout);
    while(cin>>total)
    {
        int sa[total];
        if(total==0)
            break;
        for(int i=0;i<total;i++)
        {
            cin>>num;
            sa[i]=num;
        }
        for(int i=0;i<total;i++)
        {    
            for(int j=0;j<total;j++)
            {
                X[total*i+j]=sa[i]+sa[j];
                Y[total*i+j]=sa[i]-sa[j];
            }
        }
        int at[total*total],bt[total*total];
        for(int i=0;i<total*total;i++)
        {
            at[i]=i;
            bt[i]=i;
        }
        qsort(at,total*total,sizeof(int),cmp1);
        qsort(bt,total*total,sizeof(int),cmp2);
       
            
        check=0;
        first=0;
        checkf=0;
        for(int i=total*total-1;i>=0;i--)
        {
            low=0;
            upp=total*total-1;
            while(low<=upp)
            {
                mid=low + (upp - low)/2;
                if(X[at[mid]]<Y[bt[i]])
                    low=mid+1;
                else if(X[at[mid]]>Y[bt[i]])
                    upp=mid-1;
                else
                {    
                    check=1;
                    break;
                }
            }
            if(check==1)
            {
                test=mid;
                for(int j=test;j<total*total;j++)
                {
                    if(X[at[j]]!=Y[bt[i]])
                        break;
                    b=at[j]%total;
                    a=(at[j]-b)/total;
                    c=bt[i]%total;
                    d=(bt[i]-c)/total;
                    if((sa[a]!=sa[b])&&(sa[a]!=sa[c])&&(sa[a]!=sa[d])&&(sa[b]!=sa[c])&&(sa[b]!=sa[d])&&(sa[c]!=sa[d]))
                    {
                        
                        
                        if(first==0)
                        {
                            ok=sa[d];
                            first=1;
                            checkf=1;
                        }
                        else
                        {
                            if(sa[d]>ok)
                                ok=sa[d];
                        }
                        
                    }
                }
                for(int j=test-1;j>=0;j--)
                {
                    if(X[at[j]]!=Y[bt[i]])
                        break;
                    b=at[j]%total;
                    a=(at[j]-b)/total;
                    c=bt[i]%total;
                    d=(bt[i]-c)/total;
                    
                    if((sa[a]!=sa[b])&&(sa[a]!=sa[c])&&(sa[a]!=sa[d])&&(sa[b]!=sa[c])&&(sa[b]!=sa[d])&&(sa[c]!=sa[d]))
                    {
                       
                        
                        if(first==0)
                        {
                            ok=sa[d];
                            first=1;
                            checkf=1;
                        }
                        else
                        {
                            if(sa[d]>ok)
                                ok=sa[d];
                        }
                    }
                    
                }
            }
        
        }
        if(checkf==1)
            cout<<ok<<endl;
        else
            cout<<"no solution"<<endl;
    }
}

int cmp1(const void *a,const void *b)
{
    int x,y;
    x=*(int *)(a);
    y=*(int *)(b);
    if(X[x]>X[y])
        return 1;
    else if(X[x]==X[y])
        return 0;
    else
        return -1;
}
int cmp2(const void *a,const void *b)
{
    int x,y;
    x=*(int *)(a);
    y=*(int *)(b);
    if(Y[x]>Y[y])
        return 1;
    else if(Y[x]==Y[y])
        return 0;
    else
        return -1;
}              
