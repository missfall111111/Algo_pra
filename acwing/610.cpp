#include <cstdio>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int main()
{
  string n;
  double b,s;
  cin>>n>>b>>s;
  printf("TOTAL = R$ %.2lf",b+s*0.15);
  return 0;
}
