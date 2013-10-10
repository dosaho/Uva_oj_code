#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
char as[2000];
int  a[2000],b[2000],c[2000],d[2000];
void defid(int b[2000],int d[2000]);
int chenkbn(int c[2000],int d[2000],int checkn);
void chenkcn(int c[2000],int d[2000],int checkn);
int sa,bl,cl,al;
int main(void)
{
    int temp,checkn,N,m;
    //freopen("1.out","w",stdout);
    cin>>N;
    for(int y=0;y<N;y++)
    {
        cin>>as;
        for(int i=0;i<2000;i++)
        {    
            c[i]=0;
            b[i]=0;
            d[i]=0;
        }
        for(int i=strlen(as)-1;i>=0;i--)
            a[i]=as[strlen(as)-1-i]-'0';
        if(strlen(as)%2==1)
        {
            sa=a[strlen(as)-1];
            al=1;
        }
        else
        {
            sa=a[strlen(as)-1];
            if(strlen(as)>1&&a[strlen(as)-2]==0)
            {
                sa*=10;
                al=2;
            }
            else if(strlen(as)>1)
            {
                sa*=10;
                sa+=a[strlen(as)-2];
                al=2;
            }
        }
        temp=(int)sqrt(sa);
        b[1999]=temp;
        bl=1;
        if(al==2)
        {
            a[strlen(as)-1]=a[strlen(as)-1]-(temp*temp)/10;
            a[strlen(as)-2]=a[strlen(as)-2]-((temp*temp)%10);
            if(a[strlen(as)-2]<0)
            {
                a[strlen(as)-1]--;
                a[strlen(as)-2]+=10;
            }                  
            c[1998]=a[strlen(as)-1];
            c[1999]=a[strlen(as)-2];
        }
        else
        {
            a[strlen(as)-1]=a[strlen(as)-1]-temp*temp;
            c[1999]=a[strlen(as)-1];
        }
        while(al<strlen(as))
        {
            al+=2;
            for(int i=2000-al;i<=2000-3;i++)
                c[i]=c[i+2];
            c[1998]=a[strlen(as)-al+1];
            c[1999]=a[strlen(as)-al];
            for(int i=2000-al;i<2000;i++)
            {    
                d[i]=0;
            }
            defid(b,d);
            checkn=9;
            do
            {
                m=chenkbn(c,d,checkn);
                checkn+=m;
                for(int i=2000-al;i<2000;i++)
                {    
                    d[i]=0;
                }
                defid(b,d);
            }while(m==-1);
            for(int i=2000-al;i<2000;i++)
            {    
                d[i]=0;
            }
            defid(b,d);
            chenkcn(c,d,checkn);
            for(int i=1999-bl;i<1999;i++)
                b[i]=b[i+1];
            b[1999]=checkn;
            bl++;
                
        }
        for(int i=2000-bl;i<=1999;i++)
            cout<<b[i];
        if(y+1!=N)
            cout<<endl<<endl;
        else
            cout<<endl;
    }
    return 0;
}

void defid(int b[2000],int d[2000])
{
     int carry=0;
     for(int i=1999;i>=2000-bl;i--)
         d[i]=20*b[i];
     for(int i=1999;i>=1998-bl;i--)
     {
         d[i]+=carry;
         carry=d[i]/10;
         d[i]%=10;
     } 
}

int chenkbn(int c[2000],int d[2000],int checkn)
{
    int carry;
    carry=0;
    d[1999]=checkn;
    for(int i=1999;i>=1999-bl-1;i--)
         d[i]=checkn*d[i];
    for(int i=1999;i>=1997-bl;i--)
     {
         d[i]+=carry;
         carry=d[i]/10;
         d[i]%=10;
     }
     /*for(int i=1999-bl-1;i<=1999;i++)
                cout<<d[i];
                cout<<endl;
                system("pause");*/
     int p=0;
     for(int i=1999;i>=1999-al;i--)
     {
         d[i]-=c[i];
         if(d[i]==0)
             p++;
         if(d[i]<0)
             d[i-1]--;
     }
     if(d[1999-al]>=0&&p!=al+1)
         return -1;
     else
         return 0;   
}
void chenkcn(int c[2000],int d[2000],int checkn)
{
    int carry;
    carry=0;
    d[1999]=checkn;
    /*for(int i=2000-bl-1;i<=1999;i++)
                cout<<d[i];
                cout<<endl;
                system("pause");*/
    for(int i=1999;i>=1999-bl-1;i--)
         d[i]=checkn*d[i];
   /*for(int i=2000-bl-1;i<=1999;i++)
                cout<<i<<" "<<d[i]<<" ";
                cout<<"po"<<endl;
                system("pause");*/
    for(int i=1999;i>=1996-bl;i--)
     {
         d[i]+=carry;
         carry=d[i]/10;
         d[i]%=10;
     }
     
     /*for(int i=1999-bl-1;i<=1999;i++)
                cout<<i<<" "<<d[i];
                cout<<endl;
                system("pause");*/
      for(int i=1999;i>=1999-al+1;i--)
     {
         /*cout<<c[i]<<" "<<d[i]<<" ";
         system("pause");*/
         c[i]-=d[i];
         if(c[i]<0)
         {
             c[i-1]--;
             c[i]+=10;
         }
     }
      /*for(int i=2000-al;i<=1999;i++)
                cout<<c[i];
                cout<<endl;*/ 
}
     
