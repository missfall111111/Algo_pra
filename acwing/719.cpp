#include <iostream>
#include <algorithm>

using  namespace std;

int sum(int x,int y)
{
  if(x>y)
  {
    swap(x,y);
  }
  int sum=0;
  for(int i=x+1;i<y;i++)
  {
    if(i%2!=0)
    {
      sum+=i;
    }
  }
  return sum;
}


int main()
{
  int n;
  cin>>n;
  int x,y;

  for(int i=0;i<n;i++)
  {
    cin>>x>>y;
    int res=sum(x,y);
    cout<<res<<endl;
  }

  return 0;
}
