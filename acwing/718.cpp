#include <iostream>

using namespace std;

int main()
{
  int n[3]={0};
  int m=0;
  int t;
  cin>>t;
  for(int i=0;i<t;i++)
  {
    int p;
    cin>>p;
    char c;
    cin>>c;
    if(c=='C')
    {
      n[0]+=p;
    }
    else if(c=='R')
    {
      n[1]+=p;
    }
    else 
    {
      n[2]+=p;
    }
    m+=p;
  }

  cout<<"Total: "<<m<<" animals"<<endl;
  cout<<"Total coneys: "<<n[0]<<endl;
  cout<<"Total rats: "<<n[1]<<endl;
  cout<<"Total frogs: "<<n[2]<<endl;

  printf("Percentage of coneys: %.2lf %%\n",n[0]*1.0/m*100);
  printf("Percentage of rats: %.2lf %%\n",n[1]*1.0/m*100);
  printf("Percentage of frogs: %.2lf %%\n",n[2]*1.0/m*100);

  return 0;
}
