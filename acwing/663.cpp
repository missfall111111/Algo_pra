#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
  int n[3];
  int m[3];
  for(int i=0;i<3;i++)
  {
    cin>>n[i];
    m[i]=n[i];
  }
  for(int i=0;i<2;i++)
  {
    int min=n[i];
    for(int j=i+1;j<3;j++)
    {
      if(n[j]<min)
      {
        int temp=min;
        min=n[j];
        n[j]=temp;
      }
    }
    n[i]=min;
  }
  for(int i=0;i<3;i++)
  {
    printf("%d\n",n[i]);
  }
  printf("\n");
  for(int i=0;i<3;i++)
  {
    printf("%d\n",m[i]);
  }
  return 0;
}
    
    
