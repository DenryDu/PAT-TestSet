#include <bits/stdc++.h>
using namespace std;
int DTo_ReverseToD(int num, int radix){
	int rst=0;
    vector<int> temp;
    while(num!=0){
        temp.push_back(num%radix);
        num/=radix;
    }
    for(int i=0;i<temp.size();i++){
        rst*=radix;
        rst+=temp[i];
    }
	return rst;
}
bool IsPrime(long long num){
    if(num<2)   return false;
	if(num==2)	return true;
	for(int i=2;i<sqrt(num)+1;i++){
		if((num%i)==0)	return false;
	}
	return true;
}
int main(){
	int num, tempNum, radix;
	cin>>num;
	while(true){	
		cin>>radix;
		tempNum = DTo_ReverseToD(num, radix);
		if(IsPrime(num)&&IsPrime(tempNum))	cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		vc.push_back(make_pair(num,radix));
		cin>>num;
		if(num<0)	break;
	}
    return 0;
}
