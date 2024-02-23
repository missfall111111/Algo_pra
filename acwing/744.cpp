#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
  int n;
  cin>>n;
  char c;
  cin>>c;

  double a[12][12];
  for(int i=0;i<12;i++)
  {
    for(int j=0;j<12;j++)
    {
      cin>>a[i][j];
    }
  }

  double res=0;
  for(int i=0;i<12;i++)
  {
    res+=a[i][n];
  }

  if(c=='S')
  {
    printf("%.1lf",res);
  }
  else if(c=='M')
  {
    printf("%.1lf",res/12);
  }

  return 0;

}

