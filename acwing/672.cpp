#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
  double n;
  cin>>n;
  double t=0;
  if(n<2000)
  {
    cout<<"Isento";
  }
  else if(n<3000)
  {
    t=(n-2000)*0.08;
    printf("R$ %.2lf",t);
  }
  else if(n<4500)
  {
    t+=1000*0.08;
    t+=(n-3000)*0.18;
    printf("R$ %.2lf",t);
  }
  else 
  {
    t+=1000*0.08+1500*0.18;
    t+=(n-4500)*0.28;printf("R$ %.2lf",t);
  }

  return 0;
}
