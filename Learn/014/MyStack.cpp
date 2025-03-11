/**
 * 两个队列实现一个栈
 */


#include<iostream>
#include<queue>

using namespace std;

class MyStack {
private:
	queue<int>q1;
	queue<int>q2;
public:
	MyStack() {
		
	}
	
	void push(int x) {
		if(q1.empty()){
			q2.push(x);
		}
		else{
			q1.push(x);
		}
	}
	
	int pop() {
		if(!q1.empty()){
			while(q1.size()!=1){
				q2.push(q1.front());
				q1.pop();
			}
			int res=q1.front();
			q1.pop();
			return res;
		}
		else{
			while(q2.size()!=1){
				q1.push(q2.front());
				q2.pop();
			}
			int res=q2.front();
			q2.pop();
			return res;
		}
	}
	
	int top() {
		if(q1.empty()){
			return q2.back();
		}
		else{
			return q1.back();
		}
	}
	
	bool empty() {
		return q1.empty()&&q2.empty();
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main(){
	return 0;
}
