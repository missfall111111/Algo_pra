#include <iostream>
#include <string>
#include <algorithm>
#include <type_traits>
using namespace std;

int main()
{
  string a,b;
  cin>>a>>b;

  if(a.size()<b.size())
  {
    swap(a,b);
  }

  int i;
  for(i=0;i<a.size();i++)
  {
    char c=a.front();
    a.erase(0,1);
    a.push_back(c);
    if(a.find(b)!=string::npos)
    {
      cout<<"true"<<endl;
      break;
    }
  }
  if(i==a.size())
  {
    cout<<"false"<<endl;
  }
  return 0;
}



