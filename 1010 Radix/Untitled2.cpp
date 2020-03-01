#include <bits/stdc++.h>
using namespace std;
int MAP(int i){
	if(i>='0'&&i<='9') return i-48;
	else if (i>='a'&&i<='z') return i-87;
	else return -1;
}
long  long ToD(string s,int radix){
	int current;
	int exp;
	long  long ans=0;
	for(int i=s.size()-1;i>=0;i--){
		current=MAP(s[i]);
		exp=s.size()-i-1;
		if(current>=0&&current<radix){
			ans+=current*pow(radix,exp);
		}else return -1;
	}
	return ans;
}
string DTo(long long int num, long long int radix){
	char map[36]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	string rst="";
	vector<char> result;
	while(num!=0){
		result.push_back(map[num%radix]);
		num/=radix;
	}
	for(int i=result.size()-1;i>=0;i--){
		rst+=result[i];
	}
	return rst;
}
int main(){  
	string input[2];
	long  long value[2];
	int tag=0;
	int radix;	
	cin>>input[0]>>input[1]>>tag>>radix;
	value[tag-1]=ToD(input[tag-1],radix);
	int i;
	for(i=2;i<10000;i++){
		if(ToD(input[2/tag-1],i)==value[tag-1]){
			break;
		}
	}
	if(i<10000)
		cout<<i;
	else cout<<"Impossible";
	return 0;
}
