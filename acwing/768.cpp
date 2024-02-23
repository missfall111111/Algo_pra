#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int main()
{
  string a,b;
  getline(cin,a);
  getline(cin,b);
 
  int i=0;
  while(a[i]!='\0' ||  b[i]!='\0')
  {
    if(a[i]==b[i])
    {
      i++;
      continue;;
    }
    else if((a[i]==b[i]+32 || b[i]==a[i]+32) &&((a[i]>='a'&& a[i]<='z') ||(b[i]>='a'&&b[i]<='z')))
    {
      i++;
      continue;
    }
    else 
    {
      if((a[i]>='a'&&a[i]<='z')&&(b[i]>='A'&&b[i]<='Z'))
      {
        b[i]+=32;
      }
      else if((a[i]>='A'&&a[i]<='Z')&&(b[i]>='a'&&b[i]<='z'))
      {
        a[i]+=32;
      }
      if(a[i]>b[i])
      {
        cout<<">";
        break;
      }
      else 
      {
        cout<<"<";
        break;
      }
    }
  }
  if(i==a.size()&& i==b.size())
  {
    cout<<"=";
  }
  return 0;
}
  
