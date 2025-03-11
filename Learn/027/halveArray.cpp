#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
	int halveArray(vector<int>& nums) {
		double sum=0;
		double ans=0;
		priority_queue<double> heap;
		for(const auto & num:nums){
			sum+=num;
			heap.push(num);
		}
		double minus=0;
		sum/=2;
		while(minus<sum){
			minus+=heap.top()/2;
			heap.push(heap.top()/2);
			heap.pop();
			ans++;
		}
		return ans;		
	}
};
