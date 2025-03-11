#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
  double w;
  cin>>w;
  double f;
  if(w<=400)
  {
    f=0.15;
  }
  else if(w>400 &&w<=800)
  {
    f=0.12;
  }
  else if(w>800 && w<=1200)
  {
    f=0.1;
  }
  else if(w>1200 && w<=2000)
  {
    f=0.07;
  }
  else
  {
    f=0.04;
  }
  double nw=w*(1+f);
  double d =w*f;
  printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: %.0lf %%\n",nw,d,f*100);
  
  return 0;
}

