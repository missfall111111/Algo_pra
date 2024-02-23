#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
  int a[7];
  for(int i=0;i<7;i++)
  {
    a[i]=0;
  }
  int sum;
  cin>>sum;
  printf("%d\n",sum);
  int m[7];
  m[0]=100,m[1]=50,m[2]=20,m[3]=10,m[4]=5,
  m[5]=2,m[6]=1;
  while(sum!=0)
  {
    if(sum>=100)
    {
      a[0]++;
      sum-=100;
    }
    else if(sum>=50)
    {
      a[1]++;
      sum-=50;
    }
    else if(sum>=20)
    {
      a[2]++;
      sum-=20;
    }
    else if(sum>=10)
    {
      a[3]++;
      sum-=10;
    }
    else if(sum>=5)
    {
      a[4]++;
      sum-=5;
    }
    else if(sum>=2)
    {
      a[5]++;
      sum-=2;
    }
    else if(sum>=1)
    {
      a[6]++;
      sum-=1;
    }
  }
 for(int i=0;i<7;i++)
 {
   printf("%d nota(s) de R$ %d,00\n",a[i],m[i]);
 }
 return 0;
}
