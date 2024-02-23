#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  double x[2],y[2];
  for(int i=0;i<2;i++)
  {
    cin>>x[i]>>y[i];
  }
  double result=sqrt((x[1]-x[0])*(x[1]-x[0])+
      (y[1]-y[0])*(y[1]-y[0]));
  printf("%.4lf",result);
  return 0;
}
