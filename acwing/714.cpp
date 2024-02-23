#include <iostream>

using namespace std;

int main()
{
  int x;
  int y;
  cin>>x>>y;
  int sum=0;
  if(x<y)
  {
    int temp=x;
    x=y;
    y=temp;
  }
  for(int i=y+1;i<x;i++)
  {
    if(i%2!=0)
    {
      sum+=i;
    }
  }
  cout<<sum;
  return 0;
}
