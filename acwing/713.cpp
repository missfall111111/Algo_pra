#include <iostream>

using namespace std;

int main()
{
  int n;
  int x;
  int cnt=0;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>x;
    if(x>=10 &&x<=20)
    {
      cnt++;
    }
  }

  cout<<cnt<<" in"<<endl;
  cout<<n-cnt<<" out"<<endl;
  return 0;
}
