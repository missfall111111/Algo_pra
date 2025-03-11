#include <iostream>

#include <string>
using namespace std;

int main()
{
  int t[26]={0};
  string a;
  cin>>a;

  for(char c:a)
  {
    t[c-'a']++;
  }

  int f=0;
  for(char c:a)
  {
    if(t[c-'a']==1)
    {
      cout<<c<<endl;
      f=1;
      break;
    }
  }
  if(f==0)
  {
    cout<<"no"<<endl;
  }

  return 0;
}

