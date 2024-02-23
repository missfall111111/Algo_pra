#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
  string a,b,c;
  cin>>a>>b>>c;

  if(a=="vertebrado"&&b=="ave"&&c=="carnivoro")
    cout<<"aguia";
  else if(a=="vertebrado"&&b=="ave"&&c=="onivoro")
    cout<<"pomba";
  else if(a=="vertebrado"&&b=="mamifero"&&c=="onivoro")
    cout<<"homem";
  else if(a=="vertebrado"&&b=="mamifero"&&c=="herbivoro")
    cout<<"vaca";
  else if(a=="invertebrado"&&b=="inseto"&&c=="hematofago")
    cout<<"pulga";
  else if(a=="invertebrado"&&b=="inseto"&&c=="herbivoro")
    cout<<"lagarta";
  else if(a=="invertebrado"&&b=="anelideo"&&c=="hematofago")
    cout<<"sanguessuga";
  else 
    cout<<"minhoca";
  return 0;
}
