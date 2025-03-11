#include <iostream>

using namespace std;

bool is_w(int z)
{
  if(z==1)
  {
    return false;
  }
    int sum=1;
    for(int i=2;i<z/i;i++)
    {
      if(z%i==0)
      {
          sum+=i;
          sum+=z/i;
      }
    }
    return z==sum;
}
int main()
{ 
  int n;
  cin>>n;

  int z;
  for(int i=0;i<n;i++)
  {
    cin>>z;
    if(is_w(z))
    {
      cout<<z<<" is "<<"perfect"<<endl;
    }
    else 
    {
      cout<<z<<" is not "<<"perfect"<<endl;
    }
  }
  return 0;
}


