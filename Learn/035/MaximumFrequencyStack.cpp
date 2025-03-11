#include<unordered_map>
#include<vector>
using namespace std;
class FreqStack {
public:
	unordered_map<int,vector<int>>cntValues;
	unordered_map<int,int>valueTimes;
	int maxTimes;
	FreqStack() {
		maxTimes=0;
	}
	
	void push(int val) {
		valueTimes[val]++;
		maxTimes=max(maxTimes,valueTimes[val]);
		cntValues[valueTimes[val]].push_back(val);
	}
	
	int pop() {
		int val=cntValues[maxTimes].back();
		cntValues[maxTimes].pop_back();
		valueTimes[val]--;
		if(cntValues[maxTimes].empty()){
			cntValues.erase(maxTimes);
			maxTimes--;
		}
		return val;
	}
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
