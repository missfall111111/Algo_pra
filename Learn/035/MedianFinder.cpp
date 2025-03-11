#include <queue>
#include<vector>
using namespace std;
class MedianFinder {
	public:
		priority_queue<int>pre; //默认大根堆
		priority_queue<int,vector<int>,greater<int>>pos;  //小根堆
		MedianFinder() {
			
		}

		void addNum(int num) {
			if(pre.empty()&&pos.empty()){
				pre.push(num);
				return;
			}
			if(num<pre.top()){
				pre.push((num));
			}
			else{
				pos.push(num);
			}
			
			if(pre.size()-pos.size()==2){
				pos.push(pre.top());
				pre.pop();
			}
			else if(pos.size()-pre.size()==2){
				pre.push(pos.top());
				pos.pop();
			}
			
			
		}

		double findMedian() {
			if(pre.size()==pos.size()){
				return (pre.top()+pos.top())/2.0;
			}
			else if(pre.size()-pos.size()==1){
				return pre.top();
			}
			else{
				return pos.top();
			}
			
		}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
