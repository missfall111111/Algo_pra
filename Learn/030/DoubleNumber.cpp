#include<vector>

using namespace std;



class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		vector<int>res;
		int eor=0;
		for(const auto& i:nums){
			eor^=i;
		}
		
		//Brain Kernighan算法，提取一个数字最右侧的1
		//0000 0110 => x
		//1111 1010 => -x 
		long rightOne=eor&(-eor);  
		
		int eor2=0;
		for(const auto& i:nums){
			if((i&rightOne)==0){
				eor2^=i;
			}
		}
		res.push_back(eor2);
		res.push_back(eor^eor2);
		return res;
	}
};
