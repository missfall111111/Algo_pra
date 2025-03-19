#include <iostream>
#include <unordered_map>
using namespace std;


const int MAXN = 100010;
int arr[MAXN];
int n;

//返回数组中，正数个数和负数个数相同的最大子数组的长度
//对于数组里的每一个数，得到当前的正负数前缀和sum
//0就是平衡 正数多少就是多几个正数 负数多少就是多几个负数
//寻找map之前是否存在和自己一样的前缀和的位置，那个位置+1到自己的子数组就是有效的
int f() {
	int sum = 0;
	int ans = 0;
	//正负数前缀和 索引位置
	unordered_map<int, int>map;
	map[0] = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) {
			sum++;
		} else if (arr[i] < 0) {
			sum--;
		}

		if (map.count(sum)) {
			ans = max(ans, i - map[sum]);
		} else {
			map[sum] = i;
		}
	}
	return ans;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << f();
	return 0;
}
// 64 位输出请用 printf("%lld")
