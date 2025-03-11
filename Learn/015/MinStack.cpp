#include<iostream>
#include<stack>

using namespace std;
class MinStack {
private:
	stack<int>data;
	stack<int>min;
	
public:
	MinStack() {
		
	}
	
	void push(int val) {
		data.push(val);
		if(min.empty()){
			min.push(val);
		}
		else{
			if(val<=min.top()){
				min.push(val);
			}
			else{
				min.push(min.top());
			}
		}
	}
	
	void pop() {
		data.pop();
		min.pop();
	}
	
	int top() {
		return data.top();
	}
	
	int getMin() {
		return min.top();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
