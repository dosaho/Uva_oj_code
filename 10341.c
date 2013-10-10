#include<stdio.h>
#include<math.h>
int main()
{
    double p,q,r,s,t,u,upp,low,uppa,lowa,mid,mida;
    while(scanf("%lf %lf %lf %lf %lf %lf",&p,&q,&r,&s,&t,&u)!=EOF)
    {
         upp=1;
         low=0;
         uppa=p*pow(exp(1),-upp)+q*sin(upp)+r*cos(upp)+s*tan(upp)+t*upp*upp+u;
         lowa=p*pow(exp(1),-low)+q*sin(low)+r*cos(low)+s*tan(low)+t*low*low+u;
         
         if(uppa*lowa>0)
         {    
             printf("No solution\n");
         }
        
         else
         {
              while(upp-low>0.0000001)
              {
                  mid=(low+upp)/2;
                  mida=p*pow(exp(1),-mid)+q*sin(mid)+r*cos(mid)+s*tan(mid)+t*mid*mid+u;
                  if(mida==0)
                  {
                      printf("%.4lf\n",mid);
                      break;
                  }
                  if(mida*lowa>0)
                      low=mid;
                  else
                      upp=mid;
                  
                  uppa=p*pow(exp(1),-upp)+q*sin(upp)+r*cos(upp)+s*tan(upp)+t*upp*upp+u;
                  lowa=p*pow(exp(1),-low)+q*sin(low)+r*cos(low)+s*tan(low)+t*low*low+u;
              }
              printf("%.4lf\n",mid);
         }
    }   
}
