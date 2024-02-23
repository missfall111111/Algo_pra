#include <iostream>

using namespace std;
int a[15][15];
int main()
{
  int n;

  while(cin>>n,n)
  {
    for(int i=0;i<n;i++)
    {
      for(int j=i;j<n;j++)
      {
        int res=1;
        int p=i+j;
        while(p--)
        {
          res*=2;
        }
        a[i][j]=a[j][i]=res;
      }
    }
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        cout<<a[i][j]<<" ";
      }
      cout<<endl;
    }
    cout<<endl;
  }
  return 0;
}
