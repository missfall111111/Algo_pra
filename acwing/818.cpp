#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int n,l,r;
  cin>>n>>l>>r;
  int a[n];
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  sort(a+l,a+r+1);

  for(int i=0;i<n;i++)
  {
    cout<<a[i]<<" ";
  }
  return 0;
}
