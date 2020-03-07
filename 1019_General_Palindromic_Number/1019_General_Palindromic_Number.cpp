#include <bits/stdc++.h>
using namespace std;
long long int base, num;
vector<long long int> palin;
int main(){
    cin>>num>>base;
    if(num==0){
        cout<<"Yes"<<endl<<"0";
        return 0;
    }
    while(num!=0){
        palin.push_back(num%base);
        num/=base;
    }
    int flag=palin.size()%2==0? 0:1;
    bool IsYes=true;
    for(int i=0;i<palin.size()/2+flag;i++){
        if(palin[i]!=palin[palin.size()-1-i]){
            IsYes=false; 
            break;
        }
    }
    if(IsYes)   cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    for(int i=palin.size()-1;i>=0;i--){
        cout<<palin[i];
        if(i!=0)
            cout<<" ";
    }
    return 0;
}
