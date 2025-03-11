#include<limits>
#include<iostream>
using namespace std;
class Solution {
private:
	int int_min=numeric_limits<int>::min();
public:
	int add(int a,int b){
		int ans=a;
		while(b!=0){
			ans=a^b;
			b=(a&b)<<1;
			a=ans;
		}
		return ans;
	}
	int neg(int n){
		return add(1,~n);
	}
	int minus(int a,int b){
		return add(a,neg(b));
	}
	int multiply(int a,int b){
		int ans=0;
		while(b!=0){
			if((b&1)!=0){
				ans=add(ans,a);
			}
			a<<=1;
			b=((unsigned)b>>1);
		}
		return ans;
	}
	
	//由于neg(),a和b不能是最小值
	int div(int a, int b) {
		int x=a>0?a:neg(a);
		int y=b>0?b:neg(b);  //保证正数相除
		int ans=0;
		for(int i=30;i>=0;i=minus(i,1)){//30位开始，31位为符号位
			if((x>>i)>=y){
				ans|=(1<<i);
				x=minus(x,y<<i);
			}
		}
		return ((a>0)^(b>0))?neg(ans):ans;
	}
	
	int divide(int dividend, int divisor) {
		if(dividend!=int_min && divisor!=int_min){
			return div(dividend,divisor);
		}
		
		if(dividend==int_min && divisor==int_min){
			return 1;
		}
		
		if(divisor==int_min){
			return 0;
		}
		
		if(divisor==-1){
			return numeric_limits<int>::max();
		}
		
		dividend=add(dividend,divisor>0?divisor:neg(divisor));
		int ans=div(dividend,divisor);
		int offset=divisor>0?neg(1):1;
		return add(ans,offset);	
	}
};


int main(){
	Solution s=Solution();
	cout<<s.add(12,42)<<"\n";
	cout<<s.minus(12,42)<<"\n";
	cout<<s.multiply(12,42)<<"\n";
	cout<<s.div(10,2)<<"\n";
	
	return 0;
}
