#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
  int T;
  cin>>T;
  int h=T/3600;
  T=T%3600;
  int m=T/60;
  T=T%60;
  int s=T;
  printf("%d:%d:%d",h,m,s);
  return 0;
}

