//逆序栈

#include<stack>
#include<iostream>

using namespace std;

//弹出一个栈的最下面的元素，并返回他
//a最开始不应该空
int bottomOut(stack<int>&a){
	int i=a.top();
	a.pop();
	if(a.empty()){
		return i;
	}
	int last=bottomOut(a);
	a.push(i);
	return last;
}

void reverseStack(stack<int>&a){
	int last=bottomOut(a);
	if(a.empty()){
		a.push(last);
		return;
	}
	reverseStack(a);
	a.push(last);
}
int main(){
	stack<int>a;
	a.push(5);
	a.push(4);
	a.push(3);
	a.push(2);
	a.push(1);
	
	reverseStack(a);
	
	while(!a.empty()){
		cout<<a.top()<<"\n";
		a.pop();
	}
	
	return 0;
}
