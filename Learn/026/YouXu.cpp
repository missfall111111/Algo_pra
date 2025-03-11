#include <iostream>
#include <map>
#include <set>
#include <queue>
using namespace std;

int main() {
	// 1. TreeMap操作演示 (C++中用map实现,底层也是红黑树)
	map<int, string> treeMap;
	
	// 插入键值对
	treeMap[5] = "这是5";
	treeMap[7] = "这是7"; 
	treeMap[1] = "这是1";
	treeMap[2] = "这是2";
	treeMap[3] = "这是3";
	treeMap[4] = "这是4";
	treeMap[8] = "这是8";
	
	// 判断key是否存在
	cout << (treeMap.find(1) != treeMap.end()) << endl;
	cout << (treeMap.find(10) != treeMap.end()) << endl;
	
	// 获取值
	cout << treeMap[4] << endl;
	
	// 修改值
	treeMap[4] = "张三是4";
	cout << treeMap[4] << endl;
	
	// 删除key
	treeMap.erase(4);
	cout << (treeMap.find(4) == treeMap.end()) << endl;
	
	// 获取第一个key和最后一个key
	cout << treeMap.begin()->first << endl;  
	cout << (--treeMap.end())->first << endl;
	
	// 找<=4的最大key
	auto it1 = treeMap.upper_bound(4);
	if(it1 != treeMap.begin()) {
		--it1;
		cout << it1->first << endl;
	}
	
	// 找>=4的最小key
	auto it2 = treeMap.lower_bound(4);
	if(it2 != treeMap.end()) {
		cout << it2->first << endl;
	}
	
	cout << "========" << endl;
	
	// 2. TreeSet操作演示 (C++中用set实现)
	set<int> treeSet;
	treeSet.insert(3);
	treeSet.insert(3); // 重复元素不会插入
	treeSet.insert(4);
	treeSet.insert(4);
	
	cout << "有序表大小 : " << treeSet.size() << endl;
	
	while(!treeSet.empty()) {
		cout << *treeSet.begin() << endl;
		treeSet.erase(treeSet.begin());
	}
	
	// 3. 小根堆演示
	priority_queue<int, vector<int>, greater<int>> minHeap;
	minHeap.push(3);
	minHeap.push(3);
	minHeap.push(4); 
	minHeap.push(4);
	
	cout << "堆大小 : " << minHeap.size() << endl;
	while(!minHeap.empty()) {
		cout << minHeap.top() << endl;
		minHeap.pop();
	}
	
	// 4. 大根堆演示
	priority_queue<int> maxHeap; // 默认就是大根堆
	maxHeap.push(3);
	maxHeap.push(3);
	maxHeap.push(4);
	maxHeap.push(4);
	
	cout << "堆大小 : " << maxHeap.size() << endl;
	while(!maxHeap.empty()) {
		cout << maxHeap.top() << endl;
		maxHeap.pop();
	}
	
	return 0;
}

