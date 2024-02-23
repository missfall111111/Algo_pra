#include <iostream>
#include <string>

using namespace std;

int main()
{
  string a[100];
  cin>>a[0];
  int cnt=1;
  char c;
  while(c=getchar(),c!='\n')
  {
    cin>>a[cnt];
    cnt++;
  }
  // int cnt=0;
  // while(cin>>a[cnt++])
  // {
  //   char c=getchar();
  //   if(c=='\n')
  //   {
  //     break;
  //   }
  // }
  
  string m,n;
  cin>>m>>n;
  for(string &s:a)
  {
    if(s==m)
    {
      cout<<n<<" ";
    }
    else 
    {
      cout<<s<<" ";
    }
  }
  return 0;
}
