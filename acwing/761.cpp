#include <iostream>
#include <sstream>
#include <string.h>
#include <string>

using namespace std;

int main()
{
  string s;
  int cnt=0;
  getline(cin,s);
  for(int i=0;i<s.size();i++)
  {
    if(s[i]>=48 && s[i]<=57)
    {
      cnt++;
    }
  }
  cout<<cnt<<endl;

  return 0;
}
