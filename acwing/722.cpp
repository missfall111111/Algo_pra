#include <iostream>
#include <type_traits>

using namespace std;

int main()
{
  int a,b;
  cin>>a>>b;
  while(a>0 && b>0)
  {
    int sum=0;
    if(a>b)
    {
      swap(a,b);
    }
    for(int i=a;i<=b;i++)
    {
      cout<<i<<" ";
      sum+=i;
    }
    cout<<"Sum="<<sum<<endl;
    cin>>a>>b;
  }
  return 0;
}
