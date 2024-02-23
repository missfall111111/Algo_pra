#include <iostream>

using namespace std;

int main()
{
  double n[6];
  int cnt=0;
  for(int i=0;i<6;i++)
  {
    cin>>n[i];
    if(n[i]>0)
    {
      cnt++;
    }
  }
  cout<<cnt<<" positive numbers"<<endl;
  return 0;
}
