#include <iostream>

using namespace std;

int abs(int a)
{
  return a<0 ? -a:a;
}
int main()
{
  int x;
  cin>>x;
  cout<<abs(x)<<endl;
  return 0;
}
