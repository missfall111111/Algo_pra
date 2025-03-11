#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s,sub;
  while(cin>>s>>sub)
  {
    int pos=0;
    for(int i=1;i<s.size();i++)
    {
      if(s[i]>s[pos])
      {
        pos=i;
      }
    }
    for(int i=0;i<=pos;i++)
    {
      cout<<s[i];
    }
    cout<<sub;
    for(int i=pos+1;i<s.size();i++)
    {
      cout<<s[i];
    }
    cout<<endl;
  }
  return 0;
}
