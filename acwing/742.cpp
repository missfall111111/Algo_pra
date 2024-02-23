#include <iostream>

using namespace std;

int main()
{
  int n;
  cin>>n;

  int x[n];
  for(int i=0;i<n;i++)
  {
    cin>>x[i];
  }

  int min=x[0];
  int pos=0;
  for(int i=1;i<n;i++)
  {
    if(x[i]<min)
    {
      min=x[i];
      pos=i;
    }
  }
  cout<<"Minimum value: "<<min<<endl;
  cout<<"Position: "<<pos<<endl;

  return 0;
}


