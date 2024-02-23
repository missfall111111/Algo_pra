#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
  double sum;
  cin>>sum;
  double n[6]={10000,5000,2000,1000,500,200};
  double m[6]={100,50,25,10,5,1};
  sum*=100;
  printf("NOTAS:\n");
  for(int i=0;i<6;i++)
  {
    int d=int(sum/n[i]);
    printf("%d nota(s) de R$ %.2lf\n",d,n[i]/100);
    sum-=d*n[i];
  }
 printf("MOEDAS:\n");
 for(int i=0;i<6;i++)
 {
   int d=int (sum/m[i]);
   printf("%d moeda(s) de R$ %.2lf\n",d,m[i]/100);
   sum-=d*m[i];
 }
  return 0;
}
