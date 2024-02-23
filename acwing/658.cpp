#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  double a,b,c;
  cin>>a>>b>>c;
  double m=b*b-4*a*c;
  double r1,r2;
  if(a==0 || m<0)
  {
    printf("Impossivel calcular");
  }
  else 
  {
    double s=sqrt(m);
    r1=(-b+s)/(2*a);
    r2=(-b-s)/(2*a);
    printf("R1 = %.5lf\n",r1);
    printf("R2 = %.5lf\n",r2);
  }
  return 0;
}

