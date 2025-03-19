#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
int n;
int aim;
int arr[MAXN];

//返回目标子数组中累加和为目标长度的最长字串的长度c
//遍历数组的每一个位置 他向前最多多少能凑到区间和为aim
//此时前缀和为sum 找到sum-aim这个前缀和最早出现的索引 其+1即为l
int f(int aim) {
	//前缀和 最早出现的索引位置
	unordered_map<int, int>map;
	map[0] = -1;  //这一步很重要,否则会缺少记录0开始的这种类型的ans
	int ans = 0;
	int sum = 0; //当前i位置的前缀和
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (map.count(sum - aim)) {
			ans = max(ans, i - (map[sum - aim]));
		}
		//没有的话就忽略
		if (!map.count(sum)) {
			map[sum] = i;
		}
	}
	return ans;
}
int main() {
	cin >> n >> aim;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << f(aim);

}
// 64 位输出请用 printf("%lld")
