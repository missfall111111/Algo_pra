#include <iostream>

using namespace std;

int f(int n,int m)
{
  int a=m+n;
  long long  x=1;
  int c=a;
  for(int i=1;i<=m;i++)
  {
    x*=c;
    c--;
  }
    
  int y=1;
  for(int i=2;i<=m;i++)
  {
    y*=i;
  }
  return x/y;
}
int main()
{
  int n,m;
  cin>>n>>m;
  cout<<f(n,m)<<endl;

  return 0;
}
