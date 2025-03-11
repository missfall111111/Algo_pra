#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<algorithm>

using namespace std;


double calculateGiNi(int wealth[],int n){
	double sumOfAbsoluteDifferences=0;
	double sumOfWealth=0;
	for(int i=0;i<n;i++){
		sumOfWealth+=wealth[i];
		for(int j=0;j<n;j++){
			sumOfAbsoluteDifferences+=abs(wealth[i]-wealth[j]);
		}
	}
	
	return sumOfAbsoluteDifferences/(2*n*sumOfWealth);
}
void experiment(int n,int t){
	int wealth[n];
	for(int i = 0; i < n; i++){
		wealth[i] = 100;  // 每个人初始财富都是100
	}
	srand(time(0));
	for(int i=0;i<t;i++){
		bool hasMoney[n]={false};
		
		for(int j=0;j<n;j++){
			if(wealth[j]>0){
				hasMoney[j]=true;
			}
		}
		
		for(int j=0;j<n;j++){
			if(hasMoney[j]){
				int other=j;
				do{
					other=rand() % n; //生成0-n-1的随机数
				}while(other==j);
				wealth[j]--;
				wealth[other]++;
			}
		}			
	}
	
	sort(wealth,wealth+n);
	
	cout<<"列出每个人的财富（从贫穷到富有）："<<endl;
	for(int i=0;i<n;i++){
		cout<<wealth[i]<<" ";
		if(i%10==9){
			cout<<endl;
		}
	}
	
	cout<<endl;
	cout<<"这个社会的基尼系数为："<<calculateGiNi(wealth,n)<<endl;
}


int main()
{
	cout<<"一个社会的基尼系数是一个在0-1之间的小数"<<endl;
	cout<<"基尼系数为0代表所有人的财富完全一样"<<endl;
	cout<<"基尼系数为1代表1个人掌握了全社会的财富"<<endl;
	cout<<"基尼系数越小，代表全社会财富分布越均匀；越大则代表全社会财富越不均衡"<<endl;
	cout<<"在2022年，世界各国的平均基尼系数为0.44"<<endl;
	cout<<"目前普遍认为，当基尼系数达到0.5时，"<<endl;
	cout<<"就意味着社会财富差距非常大，分布非常不均衡"<<endl;
	cout<<"社会可能因此陷入危机，比如大量的犯罪或者社会动荡"<<endl;
	cout<<"测试开始"<<endl;
	
	int n=100;
	int t=1000000;
	cout<<"人数："<<n<<endl;
	cout<<"轮数："<<t<<endl;
	
	experiment(n,t);
	
	cout<<"测试结束"<<endl;
}
