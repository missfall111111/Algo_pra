#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
  int n[2];
  double s[2],d[2];
  for(int i=0;i<2;i++)
  {
    cin>>n[i]>>s[i]>>d[i];
  }
  printf("VALOR A PAGAR: R$ %.2lf",s[1]*d[1]+s[0]*d[0]);
  return 0;

}
