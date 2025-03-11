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
  double z=a+b+c-x-d;
  if(x+z>d)
  {
    printf("Perimetro = %.1lf",a+b+c);
  }
  else 
  {
    printf("Area = %.1lf",(a+b)*c/2);
  }
  return 0;
}

