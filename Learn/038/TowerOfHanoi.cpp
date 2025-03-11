#include<iostream>
using namespace std;


/**
 * @brief n个盘子，从a到c
 * 
 * @param a 
 * @param b 
 * @param c 
 */
void f(char from,char other,char to,int n){
	if(n==1){
		cout<<from<<"->"<<to<<"\n";
		return ;
	}
	f(from,to,other,n-1);
	cout<<from<<"->"<<to<<"\n";
	f(other,from,to,n-1);
}
/**
 * @brief 一个n层的汉诺塔在左，需要把他转移到右边的柱子
 * 
 * @param n 
 */
void hanoi(int n){
	f('a','b','c',n);
}

int main(){
	hanoi(3);
	return 0;
}
