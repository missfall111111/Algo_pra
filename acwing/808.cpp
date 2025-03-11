#include <iostream>

using namespace std;

int gcd(int x,int y)
{
  int r=x%y;
  while(r!=0)
  {
    x=y;
    y=r;
    r=x%y;
  }
  return y;
}
int main()
{
  int a,b;
  cin>>a>>b;
  cout<<gcd(a,b)<<endl;
  return 0;
}
