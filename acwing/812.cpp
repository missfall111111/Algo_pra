#include <iostream>

using namespace std;

void print(int a[],int s)
{
  for(int i=0;i<s;i++)
  {
    cout<<a[i]<<" ";
  }
  cout<<endl;
}
int main()
{
  int n,s;
  cin>>n>>s;

  int a[n];
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }

  print(a,s);
  return 0;
}
