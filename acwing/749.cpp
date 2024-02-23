#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
  char c;
  cin>>c;

  double a[12][12];

  double res=0;

  for(int i=0;i<12;i++)
  {
    for(int j=0;j<12;j++)
    {
      cin>>a[i][j];
      if(i<=4 && j>=i+1 && j<=10-i)
      {
        res+=a[i][j];
      }
    }
  }
// (2+10)*5/2
  if(c=='M')
  {
    printf("%.1lf",res/30);
  }
  else if(c=='S')
  {
    printf("%.1lf",res);
  }

  return 0;
}


