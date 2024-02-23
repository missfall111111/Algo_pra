#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
  int a,b;
  cin>>a>>b;
  if(b>a)
  {
    printf("O JOGO DUROU %d HORA(S)",b-a);
  }
  else 
  {
    printf("O JOGO DUROU %d HORA(S)",b+24-a);}
  return 0;

}

