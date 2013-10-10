#include<iostream>
#include<cmath>
#include <string.h>
using namespace std;
int p,comstep,dend;
int comnump,stat[1000][500]={0},hand[100]={0},piles[7][100]={0},end=0,nump,step,pth,c,wend=1,saint=0,numint,cycle,compiles[7][100]={0},comhand[100]={0},sastep=0,x,sapath[1000]={0},compth,sa,check,nowstat[500]={0},knowstat[500]={0};
void pick();
void cpick();
int main()
{
    //freopen("1789456.out","w",stdout);
    while(1)
    {
            memset(piles,0,sizeof(piles));
            memset(compiles,0,sizeof(compiles));
            memset(hand,0,sizeof(hand));
            memset(comhand,0,sizeof(comhand));
            step=0;
            pth=0;
            comstep=0;
            saint=0;
            end=0;
            wend=1;
            compth=0;
            comnump=0;
            dend=1;
            for(int i=0;i<52;i++)
            {
                    cin>>c;
                    if(i<14)
                    {
                            piles[pth][i/7+1]=c;
                            piles[pth][0]++;
                            step++;
                            pth++;
                            if(pth==7)
                                    pth=0;
                    }
                    else
                            hand[i-14]=c;
                    if(c==0)
                    {
                            end=1;
                            break;
                    }
            }
            nump=38;
            step=14;
            pth=0;
            while(nump!=0&&wend==1&&dend==1)
            {
                    if(piles[pth][0]!=0)
                    {
                            pick();




                            memset(nowstat,0,sizeof(nowstat));
                            sastep=0;
                            nowstat[sastep]=nump;
                            sastep+=1;
                            sastep+=nump;
                            for(int i=1;i<sastep;i++)
                            {
                                    nowstat[i]=hand[i-1];
                            }
                            for(int i=0;i<7;i++)
                            {
                                    nowstat[sastep]=piles[i][0];
                                    sastep+=1;
                                    p=1;
                                    for(int j=sastep;j<sastep+piles[i][0];j++)
                                    {
                                            nowstat[j]=piles[i][p];
                                            p++;
                                    }
                                    sastep+=piles[i][0];
                            }

                            for(int iii=0;iii<saint;iii++)
                            {
                                    cycle=1;
                                    for(int j=0;j<60;j++)
                                    {
                                            if(nowstat[j]!=stat[iii][j])
                                            {
                                                    cycle=0;
                                                    break;
                                            }
                                    }
                                    if(cycle==1)
                                    {
                                            dend=0;

                                            x=step-(int)pow((double)2,(double)iii)-14;

                                            comstep=(int)pow((double)2,(double)(iii-1))+14;
                                            //cout<<comstep<<endl;

                                            memset(piles,0,sizeof(piles));
                                            memset(compiles,0,sizeof(compiles));
                                            memset(hand,0,sizeof(hand));
                                            memset(comhand,0,sizeof(comhand));
                                            sastep=0;
                                            nump=stat[iii-1][sastep];
                                            comnump=stat[iii-1][sastep];
                                            sastep+=stat[iii-1][sastep];
                                            sastep++;
                                            for(int o=1;o<sastep;o++)
                                            {
                                                    hand[o-1]=stat[iii-1][o];
                                                    comhand[o-1]=stat[iii-1][o];
                                            }
                                            for(int u=0;u<7;u++)
                                            {
                                                    piles[u][0]=stat[iii-1][sastep];
                                                    compiles[u][0]=stat[iii-1][sastep];
                                                    sastep+=1;
                                                    int p=1;
                                                    for(int j=sastep;j<sastep+piles[u][0];j++)
                                                    {
                                                            piles[u][p]=stat[iii-1][j];
                                                            compiles[u][p]=stat[iii-1][j];
                                                            p++;
                                                    }
                                                    sastep+=piles[u][0];
                                            }
                                            pth=sapath[iii-1];
                                            compth=sapath[iii-1];
                                            int kk=1;
                                            while(kk<=x)
                                            {
                                                    if(piles[pth][0]!=0)
                                                    {
                                                            pick();
                                                            kk++;
                                                            comstep++;
                                                    }
                                                    pth++;
                                                    if(pth==7)
                                                            pth=0;
                                            }
                                            cycle=0;
                                            while(cycle==0)
                                            {
                                                    while(piles[pth][0]==0)
                                                    {
                                                        pth++;
                                                        if(pth==7)
                                                            pth=0;
                                                    }
                                                    if(piles[pth][0]!=0)
                                                    {
                                                            pick();
                                                            comstep++;
                                                    }
                                                    pth++;
                                                        if(pth==7)
                                                            pth=0;
                                                    memset(nowstat,0,sizeof(nowstat));
                                                    sastep=0;
                                                    nowstat[0]=nump;
                                                    sastep+=1;
                                                    sastep+=nump;
                                                    for(int i=1;i<sastep;i++)
                                                    {
                                                            nowstat[i]=hand[i-1];
                                                    }
                                                    for(int i=0;i<7;i++)
                                                    {
                                                            nowstat[sastep]=piles[i][0];
                                                            sastep+=1;
                                                            p=1;
                                                            for(int j=sastep;j<sastep+piles[i][0];j++)
                                                            {
                                                                    nowstat[j]=piles[i][p];
                                                                    p++;
                                                            }
                                                            sastep+=piles[i][0];
                                                    }
                                                    while(compiles[compth][0]==0)
                                                    {
                                                        compth++;
                                                        if(compth==7)
                                                            compth=0;
                                                    }
                                                    if(compiles[compth][0]!=0)
                                                    {
                                                            cpick();
                                                    }
                                                    compth++;
                                                    if(compth==7)
                                                            compth=0;
                                                    memset(knowstat,0,sizeof(knowstat));
                                                    sastep=0;
                                                    knowstat[0]=comnump;
                                                    sastep+=1;
                                                    sastep+=comnump;
                                                    /*cout<<nump<<"nump "<<comnump<<"comnump"<<endl;*/
                                                    for(int i=1;i<sastep;i++)
                                                    {
                                                            knowstat[i]=comhand[i-1];
                                                    }
                                                    for(int i=0;i<7;i++)
                                                    {
                                                            knowstat[sastep]=compiles[i][0];
                                                            sastep+=1;
                                                            p=1;
                                                            for(int j=sastep;j<sastep+compiles[i][0];j++)
                                                            {
                                                                    knowstat[j]=compiles[i][p];
                                                                    p++;
                                                            }
                                                            sastep+=compiles[i][0];
                                                    }
                                                    /*for(int jj=0;jj<60;jj++)
                                                    {

                                                            cout<<knowstat[jj]<<" ";
                                                    }
                                                    cout<<endl;
                                                    for(int jj=0;jj<60;jj++)
                                                    {

                                                            cout<<nowstat[jj]<<" ";
                                                    }

                                                    cout<<endl;
                                                    cout<<comstep<<endl;
                                                    for(int ii=0;ii<nump;ii++)
                                            {
                                                    cout<<hand[ii]<<" ";
                                            }
                                            cout<<endl;
                                            for(int ii=0;ii<7;ii++)
                                            {
                                                    for(int jj=0;jj<15;jj++)
                                                    {
                                                            cout<<piles[ii][jj]<<" ";
                                                    }
                                                    cout<<endl;
                                            }
                                            cout<<endl;

                                            for(int ii=0;ii<comnump;ii++)
                                            {
                                                    cout<<comhand[ii]<<" ";
                                            }
                                            cout<<endl;
                                            for(int ii=0;ii<7;ii++)
                                            {
                                                    for(int jj=0;jj<15;jj++)
                                                    {
                                                            cout<<compiles[ii][jj]<<" ";
                                                    }
                                                    cout<<endl;
                                            }
                                            cout<<endl;
                                            cout<<compth<<"  "<<pth<<endl;


                                                    if (comstep>=226)
                                                        system("pause");*/

                                                    cycle=1;
                                                    for(int jj=0;jj<60;jj++)
                                                    {

                                                            if(knowstat[jj]!=nowstat[jj])
                                                            {
                                                                    cycle=0;
                                                                    break;
                                                            }
                                                    }



                                            }
                                    }
                                    if(cycle==1)
                                        break;
                            }
                    }
                    pth++;
                    if(pth==7)
                            pth=0;
                    wend=0;
                    for(int i=0;i<7;i++)
                    {
                            if(piles[i][0]!=0)
                            {
                                    wend=1;
                                    break;
                            }
                    }
                    numint=(int)pow((double)2,(double)saint);
                    sastep=0;
                    if(step==14+numint)
                    {
                            sapath[saint]=pth;
                            stat[saint][0]=nump;
                            sastep+=1;
                            sastep+=nump;
                            for(int i=1;i<sastep;i++)
                            {
                                    stat[saint][i]=hand[i-1];
                            }
                            for(int i=0;i<7;i++)
                            {
                                    stat[saint][sastep]=piles[i][0];
                                    sastep+=1;
                                    p=1;
                                    for(int j=sastep;j<sastep+piles[i][0];j++)
                                    {
                                            stat[saint][j]=piles[i][p];
                                            p++;
                                    }
                                    sastep+=piles[i][0];
                            }
                            saint++;
                    }


            }
            if(end==1)
                break;
            if(comstep!=0)
                    cout<<"Draw: "<<comstep<<endl;
            else if(nump==0)
                    cout<<"Loss: "<<step<<endl;
            else
                    cout<<"Win : "<<step<<endl;

            if(end==1)
                    break;
        }
}

void pick()
{
        for(sa=1;piles[pth][sa]!=0;sa++){};
        piles[pth][sa]=hand[0];
        piles[pth][0]++;
        nump--;
        step++;
        for(int j=0;j<nump;j++)
            hand[j]=hand[j+1];
        check=1;
        while(check==1)
        {
            check=0;
            if(piles[pth][0]>=3)
            {
                if((piles[pth][1]+piles[pth][2]+piles[pth][piles[pth][0]]==10)||(piles[pth][1]+piles[pth][2]+piles[pth][piles[pth][0]]==20)||(piles[pth][1]+piles[pth][2]+piles[pth][piles[pth][0]]==30))
                {
                    hand[nump]=piles[pth][1];
                    hand[nump+1]=piles[pth][2];
                    hand[nump+2]=piles[pth][piles[pth][0]];
                    nump+=3;
                    piles[pth][piles[pth][0]]=0;
                    piles[pth][0]-=3;
                    for(int j=1;j<=piles[pth][0]+5;j++)
                        piles[pth][j]=piles[pth][j+2];
                    check=1;

                }
                else if((piles[pth][1]+piles[pth][piles[pth][0]]+piles[pth][piles[pth][0]-1]==10)||(piles[pth][1]+piles[pth][piles[pth][0]]+piles[pth][piles[pth][0]-1]==20)||(piles[pth][1]+piles[pth][piles[pth][0]]+piles[pth][piles[pth][0]-1]==30))
                {
                    hand[nump]=piles[pth][1];
                    hand[nump+1]=piles[pth][piles[pth][0]-1];
                    hand[nump+2]=piles[pth][piles[pth][0]];
                    nump+=3;
                    piles[pth][piles[pth][0]]=0;
                    piles[pth][piles[pth][0]-1]=0;
                    piles[pth][0]-=3;
                    for(int j=1;j<=piles[pth][0]+4;j++)
                        piles[pth][j]=piles[pth][j+1];
                    check=1;

                }
                else if((piles[pth][piles[pth][0]-2]+piles[pth][piles[pth][0]-1]+piles[pth][piles[pth][0]]==10)||(piles[pth][piles[pth][0]-2]+piles[pth][piles[pth][0]-1]+piles[pth][piles[pth][0]]==20)||(piles[pth][piles[pth][0]-2]+piles[pth][piles[pth][0]-1]+piles[pth][piles[pth][0]]==30))
                {
                    hand[nump]=piles[pth][piles[pth][0]-2];
                    hand[nump+1]=piles[pth][piles[pth][0]-1];
                    hand[nump+2]=piles[pth][piles[pth][0]];
                    nump+=3;
                    piles[pth][piles[pth][0]]=0;
                    piles[pth][piles[pth][0]-1]=0;
                    piles[pth][piles[pth][0]-2]=0;
                    piles[pth][0]-=3;
                    check=1;

                }
            }
        }
}
void cpick()
{
        for(sa=1;compiles[compth][sa]!=0;sa++){};
        compiles[compth][sa]=comhand[0];
        compiles[compth][0]++;
        comnump--;
        for(int j=0;j<comnump;j++)
            comhand[j]=comhand[j+1];
        check=1;
        while(check==1)
        {
            check=0;
            if(compiles[compth][0]>=3)
            {
                if((compiles[compth][1]+compiles[compth][2]+compiles[compth][compiles[compth][0]]==10)||(compiles[compth][1]+compiles[compth][2]+compiles[compth][compiles[compth][0]]==20)||(compiles[compth][1]+compiles[compth][2]+compiles[compth][compiles[compth][0]]==30))
                {
                    comhand[comnump]=compiles[compth][1];
                    comhand[comnump+1]=compiles[compth][2];
                    comhand[comnump+2]=compiles[compth][compiles[compth][0]];
                    comnump+=3;
                    compiles[compth][compiles[compth][0]]=0;
                    compiles[compth][0]-=3;
                    for(int j=1;j<=compiles[compth][0]+5;j++)
                        compiles[compth][j]=compiles[compth][j+2];
                    check=1;

                }
                else if((compiles[compth][1]+compiles[compth][compiles[compth][0]]+compiles[compth][compiles[compth][0]-1]==10)||(compiles[compth][1]+compiles[compth][compiles[compth][0]]+compiles[compth][compiles[compth][0]-1]==20)||(compiles[compth][1]+compiles[compth][compiles[compth][0]]+compiles[compth][compiles[compth][0]-1]==30))
                {
                    comhand[comnump]=compiles[compth][1];
                    comhand[comnump+1]=compiles[compth][compiles[compth][0]-1];
                    comhand[comnump+2]=compiles[compth][compiles[compth][0]];
                    comnump+=3;
                    compiles[compth][compiles[compth][0]]=0;
                    compiles[compth][compiles[compth][0]-1]=0;
                    compiles[compth][0]-=3;
                    for(int j=1;j<=compiles[compth][0]+4;j++)
                        compiles[compth][j]=compiles[compth][j+1];
                    check=1;

                }
                else if((compiles[compth][compiles[compth][0]-2]+compiles[compth][compiles[compth][0]-1]+compiles[compth][compiles[compth][0]]==10)||(compiles[compth][compiles[compth][0]-2]+compiles[compth][compiles[compth][0]-1]+compiles[compth][compiles[compth][0]]==20)||(compiles[compth][compiles[compth][0]-2]+compiles[compth][compiles[compth][0]-1]+compiles[compth][compiles[compth][0]]==30))
                {
                    comhand[comnump]=compiles[compth][compiles[compth][0]-2];
                    comhand[comnump+1]=compiles[compth][compiles[compth][0]-1];
                    comhand[comnump+2]=compiles[compth][compiles[compth][0]];
                    comnump+=3;
                    compiles[compth][compiles[compth][0]]=0;
                    compiles[compth][compiles[compth][0]-1]=0;
                    compiles[compth][compiles[compth][0]-2]=0;
                    compiles[compth][0]-=3;
                    check=1;

                }
            }
        }

}



