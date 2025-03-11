#include <iostream>

using namespace std;

long long int F(int z)
{
  long long int a=0,b=1;
  while(z--)
  {
   long long int temp=a;
    a=b;
    b=b+temp;
  }
  return a;
}

int main()
{
  int n;
  cin>>n;

  int z;

  for(int i=0;i<n;i++)
  {
    cin>>z;
    long long int res=F(z);
    cout<<"Fib("<<z<<") = "<<res<<endl;
  }

  return 0;
}
