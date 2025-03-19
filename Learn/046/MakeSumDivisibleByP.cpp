#include <vector>
#include <unordered_map>
#include <limits>
using namespace std;


class Solution {
public:
	
	//删去最短的一段子数组，使得其累加和可以被p整除
	//返回其长度
	//1. 先求出整体的累积和对于p的取余情况，得到整体的余数q
	//2. 余数前缀和每个位置都有自己的和sum
	//如果sum>=q 找最近的x-q ;
	//如果sum<q 找最近的p-(q-x);
	//在一个map里找
	int minSubarray(vector<int>& nums, int p) {
		int s = 0;
		
		for (unsigned int i = 0; i < nums.size(); i++) {
			s += nums[i] % p;
			s%=p;
		}
		
		int q = s % p;  //整体多出的余数
		
		if (q == 0) {
			return 0;
		}
		
		int sum = 0;
		unsigned int ans = numeric_limits<int>::max();
		//余数前缀和 索引位置
		unordered_map<int, int>map;
		map[0] = -1;
		for (unsigned int i = 0; i < nums.size(); i++) {
			sum += nums[i]%p;
			sum%=p;
			int a = sum ;
			
			if (a >= q) {
				if (map.count(a - q)) {
					ans = min(ans, i - map[a - q]);
				}
			} else {
				if (map.count(p - (q - a))) {
					ans = min(ans, i - map[p - (q - a)]);
				}
			}
			
			map[a] = i;
		}
		
		if (ans == nums.size()) {
			return -1;
		}
		return ans;
	}
};
