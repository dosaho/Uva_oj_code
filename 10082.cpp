#include<stdio.h>
int main()
{
    char te[200];
    while(gets(te))
    {
        for(int i=0;te[i]!='\0';i++)
        {
            if(te[i]=='1')
                printf("`");
            else if(te[i]==' ')
                printf(" ");
            else if(te[i]=='2')
                printf("1");
            else if(te[i]=='3')
                printf("2");
            else if(te[i]=='4')
                printf("3");
            else if(te[i]=='5')
                printf("4");
            else if(te[i]=='6')
                printf("5");
            else if(te[i]=='7')
                printf("6");
            else if(te[i]=='8')
                printf("7");
            else if(te[i]=='9')
                printf("8");
            else if(te[i]=='0')
                printf("9");
            else if(te[i]=='-')
                printf("0");
            else if(te[i]=='=')
                printf("-");
            else if(te[i]=='W')
                printf("Q");
            else if(te[i]=='E')
                printf("W");
            else if(te[i]=='R')
                printf("E");
            else if(te[i]=='T')
                printf("R");
            else if(te[i]=='Y')
                printf("T");
            else if(te[i]=='U')
                printf("Y");
            else if(te[i]=='I')
                printf("U");
            else if(te[i]=='O')
                printf("I");
            else if(te[i]=='P')
                printf("O");
            else if(te[i]=='[')
                printf("P");
            else if(te[i]==']')
                printf("[");
            else if(te[i]==92)
                printf("]");
            else if(te[i]=='S')
                printf("A");
            else if(te[i]=='D')
                printf("S");
            else if(te[i]=='F')
                printf("D");
            else if(te[i]=='G')
                printf("F");
            else if(te[i]=='H')
                printf("G");
            else if(te[i]=='J')
                printf("H");
            else if(te[i]=='K')
                printf("J");
            else if(te[i]=='L')
                printf("K");
            else if(te[i]==';')
                printf("L");
            else if(te[i]==39)
                printf(";");
            else if(te[i]=='X')
                printf("Z");
            else if(te[i]=='C')
                printf("X");
            else if(te[i]=='V')
                printf("C");
            else if(te[i]=='B')
                printf("V");
            else if(te[i]=='N')
                printf("B");
            else if(te[i]=='M')
                printf("N");
            else if(te[i]==',')
                printf("M");
            else if(te[i]=='.')
                printf(",");
            else if(te[i]=='/')
                printf(".");
        }
        printf("\n");
    }
} 
