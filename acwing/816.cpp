#include <iostream>

using namespace std;

void reverse(int a[],int s)
{
  int l=0,r=s-1;
  while(l<r)
  {
    int temp=a[l];
    a[l]=a[r];
    a[r]=temp;
    l++;r--;
  }
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
  reverse(a,s);
  for(int i=0;i<n;i++)
  {
    cout<<a[i]<<" " ;
  }
  return 0;
}
