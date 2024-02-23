#include <iostream>

using namespace std;

int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++)
  {
      int x;
      if(i<=n/2)
      {
         x=2*i+1;
      }
      else 
      {
         x=(i-n/2)*(-2)+n;
      }
      int s=(n-x)/2;
      for(int m=0;m<s;m++)
      {
        cout<<" ";
      }
      for(int n=0;n<x;n++)
      {
        cout<<"*";
      }
      for(int p=0;p<s;p++)
      {
        cout<<" ";
      }
    cout<<endl;
  }
  return 0;

}

