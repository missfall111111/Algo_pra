#include <iostream>

#include <string>
using namespace std;

int main()
{
  int n;
  while(cin>>n,n!=0)
  {
    string s[n];
    for(int i=0;i<n;i++)
    {
      cin>>s[i];
    }

    int len=s[0].size();
    for(int i=1;i<n;i++)
    {
      if(s[i].size()<len)
      {
        len=s[i].size();
      }
    }

    int i;
    int flag=0;
    for(i=0;i<len;i++)
    {
      for(int j=1;j<n;j++)
      {
        if(s[j][s[j].size()-1-i]!=s[0][s[0].size()-1-i])
        {
          flag=1;
          break;
        }
      }
      if(flag==1)
      {
        break;
      }
    }
    i--;
    if(i!=-1)
    {
      cout<<s[0].substr(s[0].size()-1-i,i+1)<<endl;
    }
    else 
    {
      cout<<" "<<endl;
    }
  }

    return 0;
  }
