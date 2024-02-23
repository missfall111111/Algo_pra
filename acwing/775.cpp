#include <iostream>

#include <string>

using namespace std;

int main()
{
  int cnt=0;
  string a[100];

  while(cin>>a[cnt++]);

  for(int i=cnt-2;i>=0;i--)
  {
    cout<<a[i]<<" ";
  }

 return 0;
}
