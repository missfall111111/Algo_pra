#include <iostream>

#include <string>

using namespace std;

int main()
{
  string a;
  getline(cin,a);
  for(int i=0;i<a.size();i++)
  {
    if(a[i]>=65 && a[i]<=90)
    {
      if(a[i]=='Z')
      {
        cout<<'A';
      }
      else 
      {
        cout<<(char)(a[i]+1);
      }
    }
    else if(a[i]>=97 && a[i]<=122)
    {
      if(a[i]=='z')
      {
        cout<<'a';
      }
      else 
      {
        cout<<(char)(a[i]+1);
      }
    }
    else 
    {
      cout<<a[i];
    }
  }
  return 0;
}
