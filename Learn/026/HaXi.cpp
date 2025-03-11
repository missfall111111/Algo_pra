#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

class Student {
public:
	int age;
	string name;
	
	Student(int a, string b) : age(a), name(b) {}
	
	// 重载 == 操作符，定义学生对象的相等性
	bool operator==(const Student &other) const {
		return age == other.age && name == other.name;
	}
};

// 必须提供哈希函数来支持 Student 对象作为 unordered_set 或 unordered_map 的 key
namespace std {
	template <>
	struct hash<Student> {
		size_t operator()(const Student &s) const {
			return hash<int>()(s.age) ^ hash<string>()(s.name);  // 使用年龄和名字的哈希值组合
		}
	};
}

int main() {
	// String 示例
	string str1 = "Hello";
	string str2 = "Hello";
	
	//true   string类型的==被重载了，比较的是内容相同与否，而不是地址
	cout << (str1 == str2) << endl;
	
	unordered_set<string> set;
	set.insert(str1);
	// true，"Hello" 存在于 set 中
	cout << (set.count("Hello") > 0) << endl;
	cout << (set.count(str2) > 0) << endl;  //同样，关注的是内容相同
	
	set.insert(str2);
	cout << set.size() << endl;  // set.size() = 1，因为 set 是不允许重复的
	set.erase(str1);
	set.clear();
	cout << set.empty() << endl;  // true, set 已清空
	
	cout << "===========" << endl;
	
	// HashMap 示例
	unordered_map<string, string> map1;
	map1[str1] = "World";
	cout << map1.count("Hello") << endl;  // 1, 因为 key "Hello" 存在
	cout << map1.count(str2) << endl;     // 1, 因为 key "Hello" 存在
	
	cout << (map1.find(str2) != map1.end() ? map1[str2] : "not found") << endl;  // World
	cout << (map1.find("你好") == map1.end()) << endl;  // true, "你好" 不在 map 中
	map1.erase("Hello");
	cout << map1.size() << endl;  // 0, map 只剩下一个元素
	map1.clear();
	cout << map1.empty() << endl;  // true
	
	cout << "===========" << endl;
	
	// 使用整数数组模拟哈希表（当 key 范围是固定的可控时）
	int arr[100] = {0};  // 创建一个大小为 100 的数组
	arr[56] = 7285;
	arr[34] = 3671263;
	arr[17] = 716311;
	arr[24] = 1263161;
	cout << "在笔试场合中哈希表往往会被数组替代" << endl;
	
	cout << "===========" << endl;
	
	// Student 示例
	Student s1(17, "张三");
	Student s2(17, "张三");
	
	unordered_map<Student, string> map3;
	map3[s1] = "这是张三";
	
	cout << map3.count(s1) << endl;  // 1
	cout << map3.count(s2) << endl;  // 1, 因为 s1 和 s2 在定义时相等（重载了 == 操作符）
	
	map3[s2] = "这是另一个张三";
	cout << map3.size() << endl;  // 1，s1 和 s2 被视为同一个 key
	cout << map3[s1] << endl;     // 这是另一个张三
	cout << map3[s2] << endl;     // 这是另一个张三
	
	return 0;
}

