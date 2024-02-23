#include <iostream>

#include <string.h>

using namespace std;

int main()
{
  int n;

  cin>>n;
  string a,b;
  while(n--)
  {
    cin>>a>>b;
    if(a==b)
    {
      cout<<"Tie"<<endl;
    }
    else if((a=="Hunter" && b=="Gun")
        || (a=="Gun" && b=="Bear")
        | (a=="Bear" && b=="Hunter"))
    {
      cout<<"Player1"<<endl;
    }
    else 
    {
      cout<<"Player2"<<endl;
    }
  }
    return 0;
  }
