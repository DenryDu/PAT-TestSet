#include <bits/stdc++.h>
using namespace std;
long  long MAP(long  long i){
	if(i>='0'&&i<='9') return i-48;
	else if (i>='a'&&i<='z') return i-87;
	else return -1;
}
long  long ToD(string s,long  long radix){
	long  long current, exp, ans=0;
	for(int i=s.size()-1;i>=0;i--){
		current=MAP(s[i]);
		exp=s.size()-i-1;
		if(current>=0&&current<radix){
			ans+=current*pow(radix,exp);
		}else return -1;
	}
	return ans;
}
long long upperBound(string s, string s2, long long radix){
	long long current, high, max=-1;
	for(int i=0;i<s2.size();i++){
		current=MAP(s2[i]);
		if(max<current)
			max=current;
	}
	max++;
	high=max>ToD(s,radix) ? max : ToD(s,radix);
	return (high+1);
}

int main(){  
	string input[2];
	long  long value[2];
	int tag=0;
	long  long radix;	
	cin>>input[0]>>input[1]>>tag>>radix;
	value[tag-1]=ToD(input[tag-1],radix);
	//此处，tag-1代表被指定进制的数,2/tag-1代表的是进制待定的数
	//接下来是二分法
	//下界：因为我的进制转换函数以及二分过程做了修改，所以我的下界不需要指定，都从2开始即可
	//上界：
	int low=2;
	long long m, curVal, high=upperBound(input[tag-1],input[2/tag-1], radix);
	while(low<=high){
		m=(low+high)/2;
		curVal=ToD(input[2/tag-1],m);//进制待定那个数的当前值
		if(curVal==value[tag-1]){
			cout<<m;
			break;
		}else if(curVal>value[tag-1]||curVal<-1)	high=m-1;
		else	low=m+1;
	}
	if(low>high)
		cout<<"Impossible";
	return 0;
}
