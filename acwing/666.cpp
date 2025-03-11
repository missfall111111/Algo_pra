#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  double a,b,c;
  cin>>a>>b>>c;
  double d=max(max(a,b),c); 
  double x=min(min(a,b),c);
  double z=a+b+c-d-x;
  a=d;
  b=z;
  c=x;

  if(a>=b+c)
  {
    printf("NAO FORMA TRIANGULO\n");
  }
  else 
  {
    if(a*a==b*b+c*c)
    {
      printf("TRIANGULO RETANGULO\n");
    }
    else if(a*a>b*b+c*c)
    {
      printf("TRIANGULO OBTUSANGULO\n");
    }
    else if(a*a<b*b+c*c)
    {
      printf("TRIANGULO ACUTANGULO\n");
    }

    if(a==b && a==c)
    {
      printf("TRIANGULO EQUILATERO\n");
    }
    else if((a==b && a!=c)
        || (a==c && a!=b)
        || (b==c && a!=b))
        {
          printf("TRIANGULO ISOSCELES\n");
        }
  }
  return 0;
}


