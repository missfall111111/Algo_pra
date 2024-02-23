#include <iostream>
#include <string>

using namespace std;

int main()
{
  string a;
  char b;
  cin>>a>>b;

  for(char &c:a)
  {
    if(c==b)
    {
      c='#';
    }
  }
  cout<<a<<endl;

  return 0;
}
