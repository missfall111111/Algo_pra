#include "iostream"
#include <cstdio>

using namespace std;

int main()
{
  int a,b;
  cin>>a>>b;
  double m[5]={4,4.5,5,2.00,1.5};
  printf("Total: R$ %.2lf",b*m[a-1]);
  return 0;
}
