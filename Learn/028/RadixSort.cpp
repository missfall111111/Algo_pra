#include<iostream>
#include<algorithm>

using namespace std;
const int MAXN=100000;
int arr[MAXN];
int n;
const int BASE=10;
int cnt[BASE];
int help[MAXN];
void radixSort(int bits){
//	cout<<"bits="<<bits<<"\n";
	for(int i=0,offset=1;i<bits;i++,offset*=BASE){
		fill(cnt,cnt+BASE,0);   //[cnt,cnt+BASE)全部赋值为0
		for(int i=0;i<n;i++){
			cnt[(arr[i]/offset)%BASE]++;
		}
		//前缀数量分区
		for(int i=1;i<BASE;i++){
			cnt[i]=cnt[i]+cnt[i-1];
		}
		for(int i=n-1;i>=0;i--){
			help[--cnt[(arr[i]/offset)%BASE]]=arr[i];
		}
		
		for(int i=0;i<n;i++){
			arr[i]=help[i];
		}
	}
}
//计算一个非负整数的位数
int bits(int num){
	int ans=0;
	while(num!=0){
		num/=BASE;
		ans++;
	}
	
	return ans;
}
//把负数变为非负整数，得到最大数字的进制位数
void sort(){
	int m=arr[0];
	for(int i=1;i<n;i++){
		m=min(m,arr[i]);
	}
//	cout<<"Min="<<m<<"\n";
	int Max=0;
	for(int i=0;i<n;i++){
		arr[i]-=m;
		Max=max(Max,arr[i]);
	}
//	cout<<"MAx="<<Max<<"\n";
	radixSort(bits(Max));
	
	for(int i=0;i<n;i++){
		arr[i]+=m;
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort();
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
	return 0;
}

/**
 * debug
 * 1. 变量写混没有
 * 2. 各种条件
 * 3. cout
 */
