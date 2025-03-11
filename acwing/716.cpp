#include <iostream>

using namespace std;

int main()
{
  int n,pos;
  int max;
  for(int i=1;i<101;i++)
  {
    cin>>n;
    if(i==0)
    {
      max=n;
      pos=0;
    }
    else 
    {
      if(max<n)
      {
        max=n;
        pos=i;
      }
    }
  }
  cout<<max<<endl<<pos<<endl;
  return 0;
}
