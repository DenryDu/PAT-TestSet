#include <bits/stdc++.h>
using namespace std;
int winNum, cusNum;
double total=0.0;
typedef struct Time{
    int hour;
    int min;
    int sec;
    Time(int h, int m, int s): hour(h), min(m), sec(s){}
    Time(): hour(), min(), sec(){}
    Time& operator =(const Time &t){
        this->hour=t.hour;
        this->min=t.min;
        this->sec=t.sec;
        return *this;
    }
    bool operator <(const Time &t){
        if(this->hour!=t.hour)  return this->hour<t.hour;
        else if(this->min!=t.min)   return this->min<t.min;
        else return this->sec<t.sec;
    }
}Time;
typedef struct record{
    Time t;
    int pro_t;
}record;
bool cmp(const record &a, const record &b){
        if(a.t.hour!=b.t.hour) return (a.t.hour<b.t.hour);
        else if(a.t.min!=b.t.min)   return (a.t.min<b.t.min);
        else    return (a.t.sec<b.t.sec);
}
double subtrac(const Time &t1, const Time &t2){
    double cnt=0.0;
    cnt+=t1.sec-t2.sec;
    cnt+=(t1.min-t2.min)*60;
    cnt+=(t1.hour-t2.hour)*60*60;
    return cnt;
}
void add_t(Time &rst, const record &rc){
    for(int i=0;i<rc.pro_t;i++){
        rst.min++;
        if(rst.min==60){
            rst.hour++;
            rst.min=0;
        }
    }
}
void swap_t(Time &rst, const record &rc){
    rst.hour=rc.t.hour;
    rst.min=rc.t.min;
    rst.sec=rc.t.sec;
    for(int i=0;i<rc.pro_t;i++){
        rst.min++;
        if(rst.min==60){
            rst.hour++;
            rst.min=0;
        }
    }
}
vector< record > que;
vector< Time > win;
int main(){
    cin>>cusNum>>winNum;
    for(int i=0;i<winNum;i++){
        Time temp(8,0,0);
        win.push_back(temp);
    }
    for(int i=0;i<cusNum;i++){
        record temp;
        scanf("%d:%d:%d %d", &temp.t.hour, &temp.t.min, &temp.t.sec, &temp.pro_t);
        if((temp.t.hour>17)||(temp.t.hour==17&&(temp.t.min!=0||temp.t.sec!=0)))  
            continue;
        que.push_back(temp);
    }
    sort(que.begin(), que.end(), cmp);
    //////////////////////////////////////////////////////////////////////////////debug
    for(int i=0;i<que.size();i++){
        cout<<endl<<"que"<<endl;
        cout<<que[i].t.hour<<":"<<que[i].t.min<<":"<<que[i].t.sec<<endl;
    }
    for(int i=0;i<que.size();i++){
        int flag=-1;
        Time temp(80,0,0);
        for(int j=0;j<win.size();j++){
           if(win[j]<temp){
               temp=win[j];
               flag=j;
           }
        }
        if(que[i].t<win[flag]){
          total+=subtrac(win[flag],que[i].t);
          add_t(win[flag],que[i]);
       }
        else{
          swap_t(win[flag],que[i]);
        }
        ////////////////////////////////////////////////////////////////////////debug
        for(int j=0;j<win.size();j++){
            cout<<endl<<"win"<<endl;
            cout<<win[j].hour<<":"<<win[j].min<<":"<<win[j].sec<<endl;
        }
    }
    total/=(double)que.size();
    double p=(total-60.00*(total/60))/60.00;
    total=(total/60)+p;
    printf("%.1f", total);
    return 0;
}
