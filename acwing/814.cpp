#include <iostream>

using namespace std;

void copy(int a[],int b[],int s)
{
  for(int i=0;i<s;i++)
  {
    b[i]=a[i];
  }
}
int main()
{
  int n,m,s;
  cin>>n>>m>>s;
  int a[n],b[m];
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  for(int i=0;i<m;i++)
  {
    cin>>b[i];
  }
  copy(a,b,s);

  for(int i=0;i<m;i++)
  {
    cout<<b[i]<<" ";
  }
  cout<<endl;
  return 0;
}
