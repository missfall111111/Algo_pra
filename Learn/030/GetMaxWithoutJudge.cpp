




using namespace std;



class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 * 获取最大值
	 * @param a int整型 
	 * @param b int整型 
	 * @return int整型
	 */
	int flip(int x){ //x为0.返回1；x为1返回0
		return x^1;
	}
	int sign(int x) //x为非负数，则返回1；x为负数，则返回0.
	{
		return flip((unsigned)x>>31);     //这里要强制转换为无符号数，因为需要逻辑右移
	}	
	int getMax1(int a,int b){
		int c=a-b;   //这一步存在溢出风险
		
		
		int returnA=sign(c);
		int returnB=flip(returnA);
		return a*returnA+b*returnB;
	}
	
	
	
	
	int getMax2(int a,int b){  //没有任何问题的实现
		int c=a-b;
		
		int sa=sign(a);
		int sb=sign(b);
		int sc=sign(c);
		
		int diffAB=sa^sb; 
		int sameAB=flip(diffAB);
		
		int returnA=diffAB*sa+sameAB*sc;
		int returnB=flip(returnA);
		
		return a*returnA+b*returnB;
	}
	
	
	
	int getMax(int a, int b) {
		// write code here
		return getMax2(a,b);
	}
};
