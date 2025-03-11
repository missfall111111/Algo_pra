#include <iostream>

#define N 110
using namespace std;
int a[N][N]={0};
int main()
{
  int n,m;
  cin>>n>>m;

  int dx[4]={-1,0,1,0};
  int dy[4]={0,1,0,-1};

  int x=0,y=0;
  int p=1;
  for(int i=1;i<=n*m;i++)
  {
    a[x][y]=i;

    int c=x+dx[p];
    int d=y+dy[p];
    if(c>=n|| d>=m || c<0 || d<0 || a[c][d]!=0)
    {
      p=(p+1)%4;
      c=x+dx[p];
      d=y+dy[p];
    }
    x=c;
    y=d;
  }

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cout<<a[i][j]<<' ';
    }
    cout<<endl;
  }
  return 0;
}

