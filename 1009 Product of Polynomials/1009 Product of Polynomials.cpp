#include <bits/stdc++.h>
using namespace std;
int main(){
	int exp;
	double cof;
	int nonZero;
	double ploys[2][1001]={0};
	double ployResult[2002]={0};
	vector< pair<int, double> > result;
	for(int i=0;i<2;i++){
		cin>>nonZero;
		for(int j=0;j<nonZero;j++){
			cin>>exp>>cof;
			ploys[i][exp]=cof;
		}
	}
	
	for(int i=0;i<1001;i++){
		for(int j=0;j<1001;j++){
			if(ploys[0][i]!=0&&ploys[1][j]!=0)
				ployResult[i+j]+=(ploys[0][i]*ploys[1][j]);
			else continue;
		}
	}
	
	for(int i=2001;i>=0;i--)
		if(ployResult[i]!=0.0)
			result.push_back(make_pair(i,ployResult[i]));

	cout<<result.size();
	for(int i=0;i<result.size();i++)
		printf(" %d %.1f", result[i].first, result[i].second);
	return 0;
}
