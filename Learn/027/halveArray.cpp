#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

//给你一个正整数数组 nums 。每一次操作中，你可以从 nums 中选择 任意 一个数并将它减小到 恰好 一半。（注意，在后续操作中你可以对减半过的数继续执行操作）
//
//请你返回将 nums 数组和 至少 减少一半的 最少 操作数。


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
