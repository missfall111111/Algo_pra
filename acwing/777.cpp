#include <iostream>
#include <string>

using namespace std;
// abbaabba
int main()
{
  string a;
  while(cin>>a,a!=".")
  {
    int n;
    int i;
    for(i=1;i<a.size();i++)
    {
      if(a.size()%i==0)
      {
        int flag=1;
        for(int j=i;j<=a.size()-i;j+=i)
        {
          if(a.substr(0,i)!=a.substr(j,i))
          {
            flag=0;
          }
        }
        if(flag==1)
        {
          n=i;
          break;
        }
      }
    }
    if(i==a.size())
    {
      n=a.size();
    }
    cout<<a.size()/n<<endl;
  }

  return 0;
}



