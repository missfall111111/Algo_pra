#include <iostream>

using namespace std;

int main()
{
  int n;
  
  while(cin>>n,n)
  {
    for(int i=1;i<n+1;i++)
    {
      for(int j=i;j>=1;j--)
      {
        cout<<j<<" ";
      }
      for(int j=2;j<=n-i+1;j++)
      {
        cout<<j<<" ";
      }
      cout<<endl;
    }
    cout<<endl;
  }
  return 0;
}


