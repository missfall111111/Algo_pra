#include <iostream>

using namespace std;

int get_unique_count(int a[],int n)
{
  int t=0;
  for(int i=0;i<n;i++)
  {
    int f=0;
    for(int j=0;j<i;j++)
    {
      if(a[j]==a[i])
      {
        f=1;
        break;
      }
    }
    if(f==0)
    {
      t++;
    }
  }    
  return t;
}
int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  cout<<get_unique_count(a,n)<<endl;
  return 0;
}
