#include <iostream>

#include <string>
using namespace std;

int main()
{
  string s,a,b;
  int cnt=0;
  char c;
  while(cin>>c)
  {
    if(c==',')
    {
      cnt++;
      continue;
    }
    if(cnt==0)
    {
      s+=c;
    }
    else if(cnt==1)
    {
      a+=c;
    }
    else if(cnt==2)
    {
      b+=c;
    }
  }
  int w=-1;

  for(int i=0;i<s.size();i++)
  {
    int flag=0;
    for(int j=i;j<a.size()+i;j++)
    {
      if(j>=s.size()||s[j]!=a[j-i])
      {
        flag=1;
        break;
      }
    }
    if(flag==1)
    {
      continue;
    }
    
    for(int j=i+a.size();j<s.size();j++)
    { int flag=0;
      for(int m=j;m<j+b.size();m++)
      {
        if(m>=s.size()||s[m]!=b[m-j])
        {
          flag=1;
          break;
        }
      }

      if(flag==0)
      {
        int d=j-(i+a.size());
        if(d>w)
        {
          w=d;
        }
      }
    }
  }
  cout<<w<<endl;
  return 0;
}
