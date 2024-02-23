#include <iostream>

#include <string.h>
#include <string>

using namespace std;

int main()
{
  string a;
  getline(cin,a);
  int len=a.size();

  char b[len];

  for(int i=0;i<len;i++)
  {
    b[i]=a[i]+a[(i+1)%len];
  }
//  cout<<b<<endl;
  for(int i=0;i<len;i++)
  {
    cout<<b[i];
  }

  return 0;
}
