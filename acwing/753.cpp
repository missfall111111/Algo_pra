#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int n;

  while(cin>>n,n)
  {
    n++;
    for(int i=1;i<n;i++)
    {
      for(int j=1;j<n;j++)
      {
        int res=min((min(min(i,j),(n-i))),(n-j));
        cout<<res<<" ";
      }
      cout<<endl;
    }
    cout<<endl;
  }
  return 0;
}
