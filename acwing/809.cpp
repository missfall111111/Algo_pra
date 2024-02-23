#include <iostream>
#include <type_traits>

using namespace std;

int lcm(int a,int b)
{
  if(a<b)
  {
    swap(a,b);
  }
  int i;
  for(i=1;a*i%b!=0;i++);
  return a*i;
}
int main()
{
  int a,b;
  cin>>a>>b;

  cout<<lcm(a,b)<<endl;
  return 0;
}
