#include <iostream>

using namespace std;

int main()
{
  int a=0,b=1;

  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    if(i==1)
    {
      cout<<a<<" ";
    }
    else if(i==2)
    {
      cout<<b<<" ";
    }
    else 
    {
      int temp=a;
      a=b;
      b=temp+b;
      cout<<b<<" ";
    }
  }
  return 0;
}

