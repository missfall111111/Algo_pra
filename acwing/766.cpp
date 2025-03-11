#include <iostream>
#include <string>

using namespace std;

int main()
{
  string a;
  getline(cin,a);

  int f=0;
  for(char c:a)
  {
    if(c!=' ')
    {
      cout<<c;
      if(f==1)
      {
        f=0;
      }
    }
    else 
    {
      if(f)
      {
        continue;
      }
      else 
      {
        f=1;
        cout<<c;
      }
    }
  }
  return 0;
}
