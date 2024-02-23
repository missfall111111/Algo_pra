#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  if(c<a || ((c==a)&&(d<=b)))
  {
    c+=24;
  }
  if(d<b)
  {
    d+=60;
    c-=1;
  }

  printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)",c-a,d-b);

  return 0;
}

