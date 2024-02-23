#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
  int n;
  cin>>n;

  getchar();
  while(n--)
  {
    string a;
    getline(cin,a);
    int max_time=0;
    char max_c=a[0];

    int lc=a[0];
    int time=1;

    for(int i=1;i<a.size();i++)
    {
      if(a[i]==lc)
      {
        time++;
      }
      else 
      {
        if(time>max_time)
        {
          max_time=time;
          max_c=lc;
        }
        time=1;
        lc=a[i];
      }
    }
    if(time>max_time)
    {
      max_time=time;
      max_c=lc;
    }
    cout<<max_c<<" "<<max_time<<endl;
  }
  return 0;
}



