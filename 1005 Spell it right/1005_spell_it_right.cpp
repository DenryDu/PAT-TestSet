#include <bits/stdc++.h>
using namespace std;
int main(){
	char ch;
	string numToString[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
	int count=0;
	vector<int> digits;
	ch=cin.get();
	while(ch!='\n'){
		count+=(ch-48);
		ch=cin.get();
	}
	if(count==0){
		cout<<"zero";
		return 0;
	}
	while(count!=0){
		digits.push_back(count%10);
		count/=10;
	}
	for(std::vector<int>::reverse_iterator it=digits.rbegin();it<digits.rend();it++){
		if(it+1<digits.rend())
			cout<<numToString[*it]<<" ";
		else
			cout<<numToString[*it];
	}
	return 0;
}
