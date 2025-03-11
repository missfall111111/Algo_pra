#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;
class RandomizedCollection {
	public:
		vector<int>arr;
		unordered_map<int, unordered_set<int>>map;
		RandomizedCollection() {
			srand(time(nullptr));
		}

		bool insert(int val) {
			if (map.count(val)) {
				map[val].emplace(arr.size());
			} else {
				unordered_set<int>a;
				a.emplace(arr.size());
				map[val] = a;
			}
			arr.push_back(val);
			return map[val].size() == 1;
		}

		bool remove(int val) {
			if (map.count(val)) {
				unordered_set<int>&a = map[val]; //这里需要引用，否则得到的只是拷贝
				int valIndex = *a.begin();
				int endIndex = arr.size() - 1;
				map[arr[endIndex]].erase(endIndex);
				map[arr[endIndex]].emplace(valIndex);
				arr[valIndex] = arr[endIndex];
				arr.erase(arr.begin() + endIndex);
				a.erase(valIndex);
				if (a.size() == 0) {
					map.erase(val);
				}
				return true;
			} else {
				return false;
			}
		}

//		bool remove(int val) {
//			if(map.count(val)){
//				unordered_set<int>&a=map[val];  //这里需要引用，否则得到的只是拷贝
//				int valIndex=*a.begin();
//				int endIndex=arr.size()-1;
//				if(val==arr[endIndex]){
//					a.erase(endIndex);
//				}
//				else{
//					map[arr[endIndex]].erase(endIndex);
//					map[arr[endIndex]].emplace(valIndex);
//					arr[valIndex]=arr[endIndex];
//					a.erase(valIndex);
//				}
//				arr.erase(arr.begin()+endIndex);
//
//				if(a.size()==0){
//					map.erase(val);
//				}
//				return true;
//			}
//			else{
//				return false;
//			}
//		}

//		bool remove(int val) {
//			if (!map.count(val)) return false;
//
//			auto& valSet = map[val];
//			int removeIdx = *valSet.begin();
//			int lastIdx = arr.size() - 1;
//			int lastVal = arr[lastIdx];
//
//			if (val == lastVal) {
//				valSet.erase(lastIdx);
//			} else {
//				auto& lastValSet = map[lastVal];
//				lastValSet.erase(lastIdx);
//				lastValSet.insert(removeIdx);
//				arr[removeIdx] = lastVal;
//				valSet.erase(removeIdx);
//			}
//
//			arr.pop_back();
//			if (valSet.empty()) map.erase(val);
//			return true;
//		}

		int getRandom() {
			return arr[rand() % arr.size()];
		}
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


//  正确解法
//class RandomizedCollection {
//private:
//	vector<int> arr;
//	unordered_map<int, unordered_set<int>> map;
//public:
//	RandomizedCollection() {
//		srand(time(nullptr));
//	}
//
//	bool insert(int val) {
//		bool notExist = (map.find(val) == map.end());
//		map[val].insert(arr.size());
//		arr.push_back(val);
//		return notExist;
//	}
//
//	bool remove(int val) {
//		if (!map.count(val)) return false;
//
//		auto& valSet = map[val];
//		int removeIdx = *valSet.begin();
//		int lastIdx = arr.size() - 1;
//		int lastVal = arr[lastIdx];
//
//		if (val == lastVal) {
//			valSet.erase(lastIdx);
//		} else {
//			auto& lastValSet = map[lastVal];
//			lastValSet.erase(lastIdx);
//			lastValSet.insert(removeIdx);
//			arr[removeIdx] = lastVal;
//			valSet.erase(removeIdx);
//		}
//
//		arr.pop_back();
//		if (valSet.empty()) map.erase(val);
//		return true;
//	}
//
//	int getRandom() {
//		return arr[rand() % arr.size()];
//	}
//};
