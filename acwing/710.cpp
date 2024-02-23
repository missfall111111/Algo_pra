#include <iostream>

using namespace std;

int main()
{
  int x;
  cin>>x;

  for(int i=0;i<6;i++)
  {
    if(i==0)
    {
      if(x%2!=0)
      {
        cout<<x<<endl;
      }
      else 
      {
        x+=1;
        cout<<x<<endl;
      }
    }
    else 
    {
      cout<<x<<endl;
    }
    x+=2;
  }
  return 0;
}


