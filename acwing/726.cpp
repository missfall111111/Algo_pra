#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int n;
  cin>>n;
  int z;

  for(int i=0;i<n;i++)
  {
    int f=1;
    cin>>z;
    if(z<=1)
    {
      f=0;
    }
    for(int j=2;j<=sqrt(z);j++)
    {
      if(z%j==0)
      {
        f=0;
        break;
      }
    }
    if(!f)
      cout<<z<<" is not prime"<<endl;
    else 
      cout<<z<<" is prime"<<endl;
  }
  return 0;
}


