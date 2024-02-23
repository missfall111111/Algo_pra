#include <iostream>

using namespace std;

void print2D(int a[][100],int r,int c)
{
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)
    {
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
}
  

int main()
{
  int r,c;
  cin>>r>>c;

  int a[100][100];
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)
    {
      cin>>a[i][j];
    }
  }
  print2D(a,r,c);
  return 0;
}
