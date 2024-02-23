#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
int main()
{
  string s;
  cin>>s;

  if(s.back()=='.')
  {
    s.pop_back();
  }
  char c;
  string l=s;

  while((c=getchar())!='\n')
  {
    cin>>s;
    if(s.back()=='.')
    {
      s.pop_back();
    }
    if(s.size()>l.size())
    {
      l=s;
    }
  }

  cout<<l;
  return 0;
}


  
