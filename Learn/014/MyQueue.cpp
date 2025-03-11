/**
 * 两个栈实现一个队列
 */


#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
private:
	stack<int>in;
	stack<int>out;
public:
	MyQueue() {
	}
	
	void push(int x) {
		in.push(x);
	}
	
	int pop() {
		if(out.empty()){
			while(!in.empty()){
				out.push(in.top());
				in.pop();
			}
		}
		int res=out.top();
		out.pop();
		return res;
	}
	
	int peek() {
		if(out.empty()){
			while(!in.empty()){
				out.push(in.top());
				in.pop();
			}
		}
		return out.top();
	}
	
	bool empty() {
		return in.empty()&&out.empty();
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(){
	return 0;
}
