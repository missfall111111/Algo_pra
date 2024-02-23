#include <iostream>

#include <string>

using namespace std;

int main()
{
  string a;
  getline(cin,a);
  for(int i=0;i<a.size();i++)
  {
    cout<<a[i]<<" ";
  }
  return 0;
}
