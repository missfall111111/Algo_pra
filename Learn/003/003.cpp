#include<iostream>

using namespace std;

void printBinary(int num){
	for(int i=31;i>=0;i--){
		cout<<((num&(1<<i))==0?"0":"1");  //注意运算符的优先级导致这样的括号是必要的
		if(i%8==0){
			cout<<" ";
		}
	}
}
int main(){
	
}
