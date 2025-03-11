#include <iostream>

using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  int a=1;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m-1;j++)
    {
      cout<<a++<<" ";
    }
    cout<<"PUM"<<endl;
    a++;
  }
  return 0;
}
