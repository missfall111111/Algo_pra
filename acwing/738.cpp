#include <iostream>

using namespace std;

int main()
{
  int v;
  cin>>v;

  int a[10];
  for(int i=0;i<10;i++)
  {
    a[i]=v;
    v*=2;
    cout<<"N["<<i<<"] = "<<a[i]<<endl;
  }
return 0;
}
