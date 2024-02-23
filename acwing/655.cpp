#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
  int T;
  cin>>T;
  int y=T/365;
  T=T%365;
  int m=T/30;
  T=T%30;
  int d=T;
  printf("%d ano(s)\n%d mes(es)\n%d dia(s)",y,m,d);
  return 0;
}
