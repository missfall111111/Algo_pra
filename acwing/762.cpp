#include <cstdio>
#include <iostream>

#include <string>

using namespace std;

int main()
{
  string a,b;
  double k;
  cin>>k;
  getchar();
  getline(cin,a);
  getline(cin,b);

  int cnt=0;
  for(int i=0;i<a.size();i++)
  {
    if(a[i]==b[i])
    {
      cnt++;
    }
  }

  double p= cnt*1.0/a.size();
  if(p>=k)
  {
    cout<<"yes"<<endl;
  }
  else 
  {
    cout<<"no"<<endl;
  }
  return 0;
}
