#include <bits/stdc++.h>
using namespace std;
int toll[24];
int recordNum;
typedef struct Time{
    int day;
    int hour;
    int min;
    int month; 
    Time(const Time &t): month(t.month), day(t.day), hour(t.hour), min(t.min){}
    Time(int m, int d, int h, int mm): month(m), day(d),hour(h),min(mm){}
}Time;
typedef struct record{
    string name;
    Time t;
    bool online;
    record(string na, int m, int d, int h, int mm, bool tag): name(na), t(m,d,h,mm), online(tag){}
}record;
bool cmpRec(const record &a, const record &b){
        if(a.name.compare(b.name)!=0)   return (a.name< b.name);
        else if(a.t.month!=b.t.month) return (a.t.month<b.t.month);
        else if(a.t.day!=b.t.day) return (a.t.day<b.t.day);
        else if(a.t.hour!=b.t.hour)   return (a.t.hour<b.t.hour);
        else    return (a.t.min<b.t.min);
}
typedef struct bill{
    string name;
    Time t_1;
    Time t_2;
    int len;
    double cost;
    bill(string na, Time t1, Time t2): name(na), t_1(t1), t_2(t2){
        this->len=(t2.day-t1.day)*24*60+(t2.hour-t1.hour)*60+(t2.min-t1.min);
        int min=0;
        double amount=0.0;
		while (t1.day!=t2.day || t1.hour!=t2.hour || t1.min!=t2.min){
			amount+=toll[t1.hour];
			t1.min++;
			min++;
			if (t1.min==60){
				t1.hour++;
				t1.min=0;
			}
			if (t1.hour==24){
				t1.day++;
				t1.hour=0;
			}
		}
        this->cost=amount/100.00;      
    }
}bill;
vector<record> recordList;
map<string, vector<bill> > billMap;
int main(){
    ///////////////////////////////////////////////read toll and recordNum
    for(int i=0;i<24;i++)
        scanf("%d", &toll[i]);
    scanf("%d", &recordNum);
    ///////////////////////////////////////////////read record
    for(int i=0;i<recordNum;i++){
        string name, tag;
        int month, day, hour, min;
        bool online;
        cin>>name;
        scanf("%d:%d:%d:%d", &month, &day, &hour, &min);
        cin>>tag;
        if(tag=="on-line")  online=true;
        else    online=false;
        record temp(name, month, day, hour, min, online);
        recordList.push_back(temp);
    }
    ///////////////////////////////////////////////make records sorted and paired, and insert into bill
    sort(recordList.begin(),recordList.end(),cmpRec);
    for(int i=0;i<recordList.size()-1;i++){
        if(recordList[i].name.compare(recordList[i+1].name)==0&&recordList[i].online==true&&recordList[i+1].online==false){
            bill temp(recordList[i].name,recordList[i].t,recordList[i+1].t);
            billMap[recordList[i].name].push_back(temp);
        }
    }
    for(std::map< string , vector< bill > >::iterator it = billMap.begin();it!=billMap.end();it++){ 
        cout<<it->first;
        vector<bill> billList = it->second;   
		printf(" %02d\n", billList[0].t_1.month);  
        double total=0;
        for(std::vector<bill>::iterator i = billList.begin();i!=billList.end();i++){
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", i->t_1.day, i->t_1.hour, i->t_1.min,
                                                               i->t_2.day, i->t_2.hour, i->t_2.min, i->len, i->cost); 
            total+=i->cost;
        }
        printf("Total amount: $%.2f\n", total);
    }
    return 0;
}
