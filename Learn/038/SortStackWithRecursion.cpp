#include<stack>
#include<iostream>
using namespace std;


/**
 * 返回一个栈的深度
 */
int deep(stack<int>&a){
	int p=a.top();
	a.pop();
	if(a.empty()){
		a.push(p);
		return 1;
	}
	
	int d=1+deep(a);
	a.push(p);
	return d;
}

/*
 *一个栈，往下数d层，返回其中的最大值
 *栈的实际深度>=d
 *不改变内部结构
 */

int getMax(stack<int>&a,int d){
	int cur=a.top();
	a.pop();
	if(d==1){
		a.push(cur);
		return cur;
	}
	int restMax=getMax(a,d-1);
	a.push(cur);
	return max(cur,restMax);
}

/**
 * @brief 一个栈，往下数d层，看看最大值m出现的次数
 * 栈的实际深度>=d
 * 
 * @param a 
 * @param d 
 * @param m 
 * 
 * @return 
 */
int times(stack<int>&a,int d,int m){
	int cur=a.top();
	a.pop();
	if(d==1){
		a.push(cur);
		return cur==m?1:0;
	}
	
	int tRest=times(a,d-1,m);
	a.push(cur);
	return tRest+(cur==m?1:0); //Fuck 优先级
}

/**
 * @brief 一个栈，已知向下d层，最大值为m，出现了k次，现在这些个最大值沉底
 * 不改变其他数据
 * 
 * @param a 
 * @param d 
 * @param k 
 * @param m 
 */
void down(stack<int>&a,int m,int k,int d){
	int cur=a.top();
	a.pop();
	if(d==1){
		for(int i=0;i<k;i++){
			a.push(m);
		}
		if(cur!=m){
			a.push(cur);
		}
		return;
	}
	
	down(a,m,k,d-1);
	if(cur==m){
		return;
	}
	a.push(cur);
	return;
}

void sort(stack<int>&x){
	int d=x.size();
	while(d!=0){
		int m=getMax(x,d);
		int t=times(x,d,m);
		down(x,m,t,d);
		d-=t;
	}
}
int main(){
	stack<int>x;
	x.push(1);
	x.push(2);
	x.push(3);
	x.push(4);
	x.push(5);
	x.push(6);
	x.push(7);
	cout<<deep(x)<<"\n";
	cout<<getMax(x,3)<<"\n";
	cout<<times(x,7,5)<<"\n";
//	down(x,7,1,7);
	sort(x);
	while(!x.empty()){
		cout<<x.top()<<" ";
		x.pop();
	}
	return 0;
}
