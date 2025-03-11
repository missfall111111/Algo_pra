#include <iostream>

using namespace std;

int main()
{
  int a,n;
  cin>>a>>n;
  while(n<=0)
  {
    cin>>n;
  }
  int sum=0;
  for(int i=0;i<n;i++)
  {
    sum+=a+i;
  }
  cout<<sum;

  return 0;
}
