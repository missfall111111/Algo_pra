#include <iostream>
using namespace std;

int main()
{
  int a,b,c;
  cin>>a>>b>>c;
  int max;
  if(a>b)
  {
    max=a;
  }
  else
  {
    max=b;
  }
  if(c>max)
  {
    max=c;
  }
  printf("%d eh o maior",max);
  return 0;
}
